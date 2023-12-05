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

#include <map>    // needed for std::map
#include <string> // needed for std::string

#define CHAR_COUNT_YEAR  4
#define CHAR_COUNT_MONTH 2
#define CHAR_COUNT_DAY   2

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
    typedef struct s_split_line
    {
        std::string left;
        std::string right;
    } t_split_line;

    /* typedefs */
    typedef std::map<int, double>      t_database;
    typedef t_database::const_iterator t_database_cit;

    /* private utility member functions */
    t_split_line   split_line_by(std::string const & line,
                                 std::string const & delimiter);
    bool           has_multiple_f(std::string const & input) const;
    bool           has_trailing_f(std::string const & input) const;
    bool           has_dot(std::string const & input) const;
    bool           is_number(std::string const & input) const;
    int            parse_date(std::string const & input) const;
    double         parse_value(std::string const & input) const;
    t_database_cit find_date_in_database(int date_to_find) const;

    std::string const trim_whitespaces(std::string const & str) const;

    /* private member variables */
    t_database _database;

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

    class EmptyDatabaseException : public std::exception
    {
      public:
        char const * what() const throw() { return "error: empty database!\n"; }
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
