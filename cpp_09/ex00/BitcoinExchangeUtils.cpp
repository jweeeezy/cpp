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
#include <fstream>             // needed for std::ifstream
#include <iostream>            // needed for std::cout
#include <sstream>             // needed for std::stringstream

/* public member functions */
void BitcoinExchange::convert(char const * file_input)
{
    if (_database.empty() == true)
    {
        throw EmptyDatabaseException();
    }

    std::ifstream f_input(file_input);
    if (!f_input)
    {
        throw BadInputFileException();
    }

    std::string line;
    while (std::getline(f_input, line))
    {
        try
        {
            t_split_line split_line = split_line_by(line, "|");
            if (split_line.left == "date" || split_line.left == "Date")
            {
                continue;
            }

            int date = parse_date(split_line.left);
            /* handle error */

            double value = parse_value(split_line.right);
            /* handle error */

            t_database_cit it = find_date_in_database(date);
            /* handle error */

            long double result = value * it->second;
            /* check for max and min values */
            std::cout << it->first << " => " << value << " = " << result
                      << "\n";
        }
        catch (std::exception & e)
        {
            std::cerr << e.what();
        }
    }
}

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

/*@note might not be needed */
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
    /* need to adapt this so for just number and then double/floats */
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

double BitcoinExchange::parse_value(std::string const & input) const
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

BitcoinExchange::t_database_cit
BitcoinExchange::find_date_in_database(int date_to_find) const
{
    t_database_cit it         = _database.end();
    int            first_date = _database.begin()->first;
    while (it == _database.end())
    {
        it = _database.find(date_to_find);
        --date_to_find;
        if (date_to_find < first_date)
        {
            throw std::exception();
        }
    }
    return it;
}

// -------------------------------------------------------------------------- //
