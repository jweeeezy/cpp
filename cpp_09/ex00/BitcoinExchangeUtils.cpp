// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  BitcoinExchangeUtils.cpp                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "BitcoinExchange.hpp" // needed for BitcoinExchange class
#include <iostream>            // needed for std::cout
#include <sstream>             // needed for std::stringstream

/* public member functions */
void BitcoinExchange::print_database()
{
    for (std::map<int, double>::const_iterator it = _database.begin();
         it != _database.end();
         ++it)
    {
        std::cout << it->first << " | " << it->second << "\n";
    }
}

/* private utility member functions */
bool BitcoinExchange::has_multiple_f(std::string const & input) const
{
    size_t counter = 0;
    for (std::string::const_iterator it = input.begin(); it != input.end();
         ++it)
    {
        if (*it == 'f')
        {
            ++counter;
            if (counter > 1)
            {
                return true;
            }
        }
    }
    return false;
}

bool BitcoinExchange::has_trailing_f(std::string const & input) const
{
    if (*(input.end() - 1) == 'f')
    {
        return true;
    }
    return false;
}

bool BitcoinExchange::has_dot(std::string const & input) const
{
    if (input.size() >= 3)
    {
        for (std::string::const_iterator itr = input.begin();
             itr != input.end() - 2;
             ++itr)
        {
            char current    = static_cast<unsigned char>(*itr);
            char next       = *(itr + 1);
            char after_next = static_cast<unsigned char>(*(itr + 2));

            if (std::isdigit(current) == true && next == '.' &&
                std::isdigit(after_next) == true)
            {
                return true;
            }
        }
    }
    return false;
}

bool BitcoinExchange::is_number(std::string const & input) const
{
    if (input.find_first_not_of("0123456789-+.f") != std::string::npos)
    {
        return false;
    }
    if (input.length() <= 1 &&
        (has_trailing_f(input) == true || input.compare(".") == 0))
    {
        return false;
    }
    return true;
}

std::string const
BitcoinExchange::trim_whitespaces(std::string const & input) const
{
    size_t start = input.find_first_not_of(" \t\n\r");
    size_t end   = input.find_last_not_of(" \t\n\r");
    if (start == std::string::npos || end == std::string::npos)
    {
        return "";
    }
    return input.substr(start, end - start + 1);
}

std::string const BitcoinExchange::parse_date(std::stringstream & input) const
{
    std::string token;
    std::string year;
    std::string month;
    std::string day;
    size_t      i   = 0;
    bool        eol = false;

    while (eol == false)
    {
        if (std::getline(input, token, '-').eof() == true)
        {
            eol = true;
        }
        token = trim_whitespaces(token);
        ++i;
        switch (i)
        {
            case 1:
                if (token.size() != 4)
                {
                    throw std::exception();
                }
                year = token;
                break;
            case 2:
                if (token.size() != 2)
                {
                    throw std::exception();
                }
                month = token;
                break;
            case 3:
                if (token.substr(0, token.find(" ")).size() != 2)
                {
                    throw std::exception();
                }
                day = token;
                break;
            default:
                throw std::exception();
        }
    }
    return std::string(year + month + day);
}

// std::string const BitcoinExchange::remove_dash(std::string const & str)
//{
//    std::stringstream ss;
//    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
//    {
//        if (*it != '-')
//        {
//            ss << *it;
//        }
//    }
//    return ss.str();
//}

// -------------------------------------------------------------------------- //
