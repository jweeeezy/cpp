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
        try
        {
            t_split_line split_line = split_line_by(line, ",");
            if (split_line.left == "date" || split_line.left == "Date")
            {
                continue;
            }
            int    date          = parse_date(split_line.left);
            double exchange_rate = parse_value(split_line.right);
            _database[date]      = exchange_rate;
        }
        catch (std::exception & e)
        {
            std::stringstream ss;
            ss << "error: " << e.what() << "\n";
            throw std::runtime_error(ss.str());
        }
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

// -------------------------------------------------------------------------- //
