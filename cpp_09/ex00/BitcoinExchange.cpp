// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  BitcoinExchange.cpp                                                 //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "BitcoinExchange.hpp" // needed for BitcoinExchange class
#include <cstdlib>             // needed for strtod
#include <sstream>             // needed for std::stringstream

#include <iostream> // @note DEBUG!

BitcoinExchange::BitcoinExchange(char const * file_database)
{
    std::ifstream f_database(file_database);
    if (!f_database)
    {
        throw BadDatabaseException();
    }

    /* format:
     * date,value
     * [YYYY-MM-DD],[exchange].[rate] */

    std::string line;
    while (std::getline(f_database, line))
    {
        size_t pos = line.find(",");
        if (pos == std::string::npos)
        {
            throw BadDatabaseFormatException();
        }
        std::string first_half = line.substr(0, pos);
        if (first_half.empty() == true)
        {
            throw BadDatabaseFormatException();
        }
        if (first_half == "date" || first_half == "Date")
        {
            continue;
        }
        int date;
        try
        {
            std::stringstream ss(first_half);
            date = std::atoi(parse_date(ss).c_str());
            (void) date;
        }
        catch (std::exception & e)
        {
            throw BadDatabaseFormatException();
        }
        if (pos + 1 == line.size())
        {
            throw BadDatabaseFormatException();
        }
        std::string second_half = line.substr(pos + 1, line.size());
        if (is_number(second_half) == false)
        {
            throw BadDatabaseFormatException();
        }
        double exchange_rate = strtod(second_half.c_str(), NULL);
        _database[date] = exchange_rate;
    }
}

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) { (void)src; }
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
    (void)rhs;
    return *this;
}

void BitcoinExchange::convert(char const * file_input)
{
    /* @note could make this a temp var too */
    std::ifstream _inputf(file_input);
    if (!_inputf)
    {
        throw BadInputFileException();
    }

    std::string line;

    while (std::getline(_inputf, line))
    {
        size_t pos = line.find("|");
        if (pos == std::string::npos)
        {
            throw BadInputFileFormatException();
        }

        std::string first_half = line.substr(0, pos);
        if (first_half.empty() == true)
        {
            throw BadInputFileFormatException();
        }

        if (first_half == "date " || first_half == "Date ")
        {
            continue;
        }
        /* test date older than database */
        /* test wrong month/year/day */
        /* edge cases for these numbers */

        std::stringstream ss(first_half);
        unsigned int      i = 0;
        std::string       token;
        std::string       year;
        std::string       month;
        std::string       date;

        /* @note mb use std::isstream no check types? */
        bool eol = false;
        while (eol == false)
        {
            if (std::getline(ss, token, '-').eof() == true)
            {
                eol = true;
            }
            token = trim_whitespaces(token);
            if (token.empty() == true)
            {
                throw BadInputFileFormatException();
            }
            ++i;
            switch (i)
            {
                case 1:
                    if (token.size() != 4)
                    {
                        throw BadInputFileFormatException();
                    }
                    break;
                case 2:
                    if (token.size() != 2)
                    {
                        throw BadInputFileFormatException();
                    }
                    break;
                case 3:
                    if (token.substr(0, token.find(" ")).size() != 2)
                    {
                        throw BadInputFileFormatException();
                    }
                    break;
                default:
                    throw BadInputFileFormatException();
            }
        }
        /* note check if pos + 1 is not the end */

        if (pos + 1 == line.size())
        {
            throw BadInputFileFormatException();
        }

        std::string second_half =
            trim_whitespaces(line.substr(pos + 1, line.size()));

        if (second_half.empty() == true)
        {
            throw BadInputFileFormatException();
        }

        //        if (second_half.size() > 4)
        //        {
        //            std::cerr << "Value is too high!\n";
        //        }

        /* @note check for f (use cpp06 functions) */
        /* --> float */

        /* else */
        /* --> int */

        /* check if > 1000 */

        /* check for max and min */
    }
}

// -------------------------------------------------------------------------- //
