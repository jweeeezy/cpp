// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  utils.cpp                                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "BitcoinExchange.hpp" // needed for BitcoinExchange class

bool BitcoinExchange::has_multiple_f(std::string const & input)
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

bool BitcoinExchange::has_trailing_f(std::string const & input)
{
    if (*(input.end() - 1) == 'f')
    {
        return true;
    }
    return false;
}

bool BitcoinExchange::has_dot(std::string const & input)
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

bool BitcoinExchange::is_number(std::string const & input)
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

std::string BitcoinExchange::remove_whitespaces(std::string const & str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end   = str.find_last_not_of(" \t\n\r");
    if (start == std::string::npos || end == std::string::npos)
    {
        return "";
    }
    return str.substr(start, end - start + 1);
}

// -------------------------------------------------------------------------- //
