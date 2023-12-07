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
    void convert(char const * path_input);
    void print_database();

    /* public constructors */
    BitcoinExchange();
    BitcoinExchange(char const * path_database);
    BitcoinExchange(BitcoinExchange const & src);
    ~BitcoinExchange();
    BitcoinExchange & operator=(BitcoinExchange const & rhs);

  private:
    /* structs */
    struct s_split_line
    {
        std::string left;
        std::string right;
    };

    /* typedefs */
    typedef struct s_split_line        t_split_line;
    typedef std::map<int, double>      t_database;
    typedef t_database::const_iterator t_database_cit;

    /* private utility member functions */
    bool              has_multiple_f(std::string const & input) const;
    bool              has_trailing_f(std::string const & input) const;
    bool              has_dot(std::string const & input) const;
    bool              is_number(std::string const & input) const;
    bool              is_double(std::string const & input) const;
    std::string const trim_whitespaces(std::string const & str) const;
    t_split_line      split_line_by(std::string const & line,
                                    std::string const & delimiter) const;
    bool              is_leap_year(int year) const;
    bool              check_valid_date(int date) const;
    int               parse_date(std::string const & input) const;
    double            parse_value(std::string const & input) const;
    std::string const convert_date_to_str(int date) const;
    std::string const format_arg_for_output(std::string const & input) const;
    t_database_cit    find_date_in_database(int date_to_find) const;

    /* private member variables */
    t_database _database;

  private:
    /* exceptions */
    class BadDatabaseException : public std::exception
    {
      public:
        char const * what() const throw() { return "error: bad database!\n"; }
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
};

#endif // BITCOINEXCHANGE_HPP

// -------------------------------------------------------------------------- //
