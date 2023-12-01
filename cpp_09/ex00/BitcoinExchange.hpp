// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  BitcoinExchange.hpp                                                 //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream> // needed for std::ifstream
#include <string>  // needed for std::string

class BitcoinExchange
{

  public:
    void convert(char const * file_input);
    
    BitcoinExchange(char const * file_database);
    BitcoinExchange(BitcoinExchange const & src);
    ~BitcoinExchange();
    BitcoinExchange & operator=(BitcoinExchange const & rhs);

  private:
    BitcoinExchange();

    class BadDatabaseException : public std::exception
    {
      public:
        char const * what() const throw() { return "error: bad database!\n"; }
    };

    class BadInputFileException : public std::exception
    {
      public:
        char const * what() const throw() { return "error: bad input file!\n"; }
    };

    class BadInputFileFormatException : public std::exception
    {
      public:
        char const * what() const throw()
        {
            return "error: bad input file format\nusage: date | "
                   "value\nYYYY-MM-DD | [int/float]";
        }
    };

  private:
    /* utility functions */
    bool        has_multiple_f(std::string const & input);
    bool        has_trailing_f(std::string const & input);
    bool        has_dot(std::string const & input);
    bool        is_number(std::string const & input);
    std::string remove_whitespaces(std::string const & str);

    std::ifstream _databasef;
    std::ifstream _inputf; /* @note temp var instead ?? */
};

#endif // BITCOINEXCHANGE_HPP

// -------------------------------------------------------------------------- //
