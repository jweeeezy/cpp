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

#include <map>     // needed for std::map
#include <string>  // needed for std::string

class BitcoinExchange
{

  public:
    /* public member functions */
    void convert(char const * file_input);
    void print_database();

    /* public constructors */
    BitcoinExchange();
    BitcoinExchange(char const * file_database);
    BitcoinExchange(BitcoinExchange const & src);
    ~BitcoinExchange();
    BitcoinExchange & operator=(BitcoinExchange const & rhs);

  private:
    /* private utility member functions */
    bool              has_multiple_f(std::string const & input) const;
    bool              has_trailing_f(std::string const & input) const;
    bool              has_dot(std::string const & input) const;
    bool              is_number(std::string const & input) const;
    std::string const parse_date(std::stringstream & input) const;
    std::string const trim_whitespaces(std::string const & str) const;
    // std::string const remove_dash(std::string const & str);
    /* @note not needed i guess */

    /* private member variables */
    std::map<int, double> _database;

  private:
    /* exceptions */
    class BadDatabaseException : public std::exception
    {
      public:
        char const * what() const throw() { return "error: bad database!\n"; }
    };

    class BadDatabaseFormatException : public std::exception
    {
      public:
        char const * what() const throw()
        {
            return "error: bad database format!\n\n"
                   "expected format: date        ,exchange_rate\n"
                   "                 [YYYY-MM-DD],[int/float]\n";
        }
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
            return "error: bad input file format\n\n"
                   "usage: date        |value\n"
                   "       [YYYY-MM-DD]|[int/float]";
        }
    };
};

#endif // BITCOINEXCHANGE_HPP

// -------------------------------------------------------------------------- //
