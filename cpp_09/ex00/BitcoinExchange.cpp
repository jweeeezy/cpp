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
#include <fstream>             // needed for std::ifstream
#include <iostream>            // needed for std::cout, std::cerr
#include <sstream>             // needed for std::stringstream

#define YELLOW "\033[33m"
#define RESET  "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void log_debug(std::string const & message)
{
    (void)message;
#ifdef DEBUG
    std::cout << YELLOW << "BitcoinExchange: " << message << RESET << "\n";
#endif // DEBUG
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

BitcoinExchange::BitcoinExchange()
{
    log_debug("default constructor called\n");
}

BitcoinExchange::BitcoinExchange(char const * file_database)
{
    log_debug("database constructor called\n");
    std::ifstream f_database(file_database);
    if (!f_database)
    {
        throw BadDatabaseException();
    }

    std::string line;
    while (std::getline(f_database, line))
    {
        size_t pos = line.find(",");
        int    date;
        double exchange_rate;

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
        try
        {
            std::stringstream ss(first_half);
            date = std::atoi(parse_date(ss).c_str());
            if (date <= 0)
            {
                throw BadDatabaseFormatException();
            }
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
        exchange_rate = strtod(second_half.c_str(), NULL);
        if (exchange_rate == 0 && second_half != "0")
        {
            /* @note check for 0 ? */
            std::cerr << "error: exchange_rate too big\n";
        }
        _database[date] = exchange_rate;
    }
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
    : _database(src._database)
{
    log_debug("copy constructor called\n");
}

BitcoinExchange::~BitcoinExchange() { log_debug("destructor called\n"); }

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
    log_debug("assignment operator called\n");
    if (this != &rhs)
    {
        _database = rhs._database;
    }
    return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

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
