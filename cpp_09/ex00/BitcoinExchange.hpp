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

#include <string> // needed for std::string

class BitcoinExchange
{

  public:
    void calculate();
    BitcoinExchange(std::string const & database);
    BitcoinExchange(const BitcoinExchange & src);
    ~BitcoinExchange();
    BitcoinExchange & operator=(const BitcoinExchange & rhs);

  private:
    BitcoinExchange();

  private:
    class BadCommandLineArgumentsException : public std::exception
    {
      public:
        const char * what() const throw()
        {
            return "error: bad arguments!\nusage: ./btc [filename]";
        }
    };
    class BadInputFileException : public std::exception
    {
      public:
        const char * what() const throw() { return "error: bad input file!\n"; }
    };
    class BadInputFileFormatException : public std::exception
    {
      public:
        const char * what() const throw()
        {
            return "error: bad input file format\nusage: date | "
                   "value\nYYYY-MM-DD | [int/float]";
        }
    };

    /* utility functions */
    bool        has_multiple_f(std::string const & input);
    bool        has_trailing_f(std::string const & input);
    bool        has_dot(std::string const & input);
    bool        is_number(std::string const & input);
    std::string remove_whitespaces(std::string const & str);
};

#endif // BITCOINEXCHANGE_HPP

// -------------------------------------------------------------------------- //
