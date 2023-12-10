// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  RPN.hpp                                                             //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>  // needed for std::stack
#include <string> // needed for std::string

#define DIGITS    std::string("0123456789")
#define OPERATORS std::string("+-/*")

#define YELLOW "\033[33m"
#define RESET  "\033[0m"

class RPN
{
  public:
    static int calculate(char const * arg);

  private:
    typedef std::string const       t_str_c;
    typedef t_str_c::const_iterator t_str_cit;

    enum operators
    {
        MULTIPLICATE,
        DIVIDE,
        ADD,
        SUBSTRACT,
        NON_TYPE
    };

  private:
    static void log_debug(t_str_c & message);

    static bool is_char_of(char c, t_str_c & set);
    static bool check_valid_chars(t_str_c & str);
    static bool check_valid_spacing(t_str_c & str);

    static t_str_c itostr(int number);
    static t_str_c parse_arguments(char const * arg);

    static int get_operator(char c);
    static int get_and_remove_top(std::stack<int> & s);
    static int next_operation(int no_right, int no_left, int oper);

  private:
    RPN();
    RPN(const RPN & src);
    ~RPN();
    RPN & operator=(const RPN & rhs);
};

#endif // RPN

// -------------------------------------------------------------------------- //
