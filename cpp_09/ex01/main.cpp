// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <cstdlib>  // needed for MACROS
#include <iostream> // needed for std::cout, std::cerr
#include <sstream>  // needed for std::stringstream
#include <stack>    // needed for std::stack
#include <stdexcept>
#include <string> // needed for std::string

#define EXPECTED_ARGC 2

#define DIGITS    std::string("0123456789")
#define OPERATORS std::string("+-/*")

#define YELLOW "\033[33m"
#define RESET  "\033[0m"

enum operators
{
    MULTIPLICATE,
    DIVIDE,
    ADD,
    SUBSTRACT,
    NON_TYPE
};

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> utility functions */

static int get_operator(char c)
{
    if (c == '*')
    {
        return MULTIPLICATE;
    }
    else if (c == '/')
    {
        return DIVIDE;
    }
    else if (c == '+')
    {
        return ADD;
    }
    else if (c == '-')
    {
        return SUBSTRACT;
    }
    return NON_TYPE;
}

void log_debug(std::string const & message)
{
    (void)message;
#ifdef DEBUG
    std::cout << YELLOW << message << RESET << "\n";
#endif // DEBUG
}

static int log_exit(std::string const & message)
{
    std::cerr << "error: " << message << "\n";
    return (EXIT_FAILURE);
}

static std::string const itostr(int number)
{
    std::stringstream ss;
    ss << number;
    return ss.str();
}

static int get_top_number(std::stack<int> & pile)
{
    int tmp = pile.top();
    pile.pop();
    return tmp;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> parsing functions */

static bool is_char_of(char c, std::string const & set)
{
    for (std::string::const_iterator it = set.begin(); it != set.end(); ++it)
    {
        if (*it == c)
        {
            return true;
        }
    }
    return false;
}

static bool check_valid_spacing(std::string const & str)
{
    std::string::const_iterator end = str.end();
    for (std::string::const_iterator it = str.begin(); it != end; ++it)
    {
        if (is_char_of(*it, DIGITS + OPERATORS) == true && it + 1 != end &&
            *(it + 1) != ' ')
        {
            return false;
        }
    }
    return true;
}

static bool check_valid_chars(std::string const & str)
{
    size_t pos = str.find_first_not_of(DIGITS + OPERATORS + " ");
    if (pos != std::string::npos)
    {
        return false;
    }
    return true;
}

static std::string const parse_arguments(char const * arg)
{
    std::string const & tmp = arg;
    if (check_valid_chars(arg) == false)
    {
        throw std::invalid_argument("invalid character!");
    }
    if (check_valid_spacing(arg) == false)
    {
        throw std::invalid_argument("invalid spacing!");
    }
    return tmp;
    /* @note need to check order / count of operands / operators */
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> RPN calculation functions */

static int next_calculation(int no_right, int no_left, int expression)
{
    /* hint: no_right gets passed first because its the first no on the stack */
    switch (expression)
    {
        case MULTIPLICATE:
            log_debug(itostr(no_left) + " * " + itostr(no_right));
            no_left *= no_right;
            break;
        case DIVIDE:
            log_debug(itostr(no_left) + " / " + itostr(no_right));
            no_left /= no_right;
            break;
        case ADD:
            log_debug(itostr(no_left) + " + " + itostr(no_right));
            no_left += no_right;
            break;
        case SUBSTRACT:
            log_debug(itostr(no_left) + " - " + itostr(no_right));
            no_left -= no_right;
            break;
        case NON_TYPE:
            throw std::runtime_error("NON_TYPE case in switch statement");
        default:
            throw std::runtime_error("default case in switch statement");
    }
    return no_left;
}

static int calculate(std::string const & input)
{
    std::stack<int> pile;
    int             result = 0;

    for (std::string::const_iterator it = input.begin(); it != input.end();
         ++it)
    {
        if (is_char_of(*it, DIGITS))
        {
            std::stringstream ss;

            ss << *it;
            int number;
            ss >> number;
            pile.push(number);
        }
        else if (is_char_of(*it, OPERATORS))
        {
            result = next_calculation(get_top_number(pile),
                                      get_top_number(pile),
                                      get_operator(*it));
            pile.push(result);
        }
    }
    return result;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> main functions */

int main(int argc, char ** argv)
{
    if (argc != EXPECTED_ARGC)
    {
        return log_exit("missing argument!");
    }
    try
    {
        int result = calculate(parse_arguments(argv[1]));
        std::cout << result;
    }
    catch (std::exception & e)
    {
        return log_exit(e.what());
    }
    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
