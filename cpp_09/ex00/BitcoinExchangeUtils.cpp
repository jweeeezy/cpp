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
#include <cstdlib>             // needed for strtod
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

double BitcoinExchange::parse_exchange_rate(std::string const & input) const
{
    if (is_number(input) == false)
    {
        throw std::exception();
    }
    double exchange_rate = strtod(input.c_str(), NULL);
    if (exchange_rate == 0 && input != "0")
    {
        throw std::exception();
    }
    return exchange_rate;
}

int BitcoinExchange::parse_date(std::string const & input) const
{
    std::stringstream stream_input(input);
    std::stringstream stream_date;
    std::string       token;
    size_t            i   = 0;
    bool              eol = false;

    while (eol == false)
    {
        if (std::getline(stream_input, token, '-').eof() == true)
        {
            eol = true;
        }
        token = trim_whitespaces(token);
        ++i;
        switch (i)
        {
            case 1:
                if (token.size() != CHAR_COUNT_YEAR ||
                    is_number(token) == false)
                {
                    throw std::exception();
                }
                stream_date << token;
                break;
            case 2:
                if (token.size() != CHAR_COUNT_MONTH ||
                    is_number(token) == false)
                {
                    throw std::exception();
                }
                stream_date << token;
                break;
            case 3:
                if (token.size() != CHAR_COUNT_DAY || is_number(token) == false)
                {
                    throw std::exception();
                }
                stream_date << token;
                break;
            default:
                throw std::exception();
        }
    }
    int date;
    stream_date >> date;
    if (stream_date.fail() || date < 0)
    {
        throw std::exception();
    }
    return date;
}

BitcoinExchange::t_split_line
BitcoinExchange::split_line_by(std::string const & line,
                               std::string const & delimiter)
{
    size_t pos = line.find(delimiter);
    if (pos == std::string::npos || pos + 1 == line.size())
    {
        throw std::exception();
    }
    std::string first_half  = trim_whitespaces(line.substr(0, pos));
    std::string second_half = trim_whitespaces(line.substr(pos + 1));
    if (first_half.empty() == true || second_half.empty() == true)
    {
        throw std::exception();
    }
    t_split_line split_line;
    split_line.left  = first_half;
    split_line.right = second_half;
    return split_line;
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
