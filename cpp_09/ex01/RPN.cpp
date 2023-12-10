// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  RPN.cpp                                                             //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "RPN.hpp" // needed for RPN class
#include <sstream> // needed for std::stringstream

/* unused constructors */
RPN::RPN() {}
RPN::RPN(const RPN & src) { (void)src; }
RPN::~RPN() {}
RPN & RPN::operator=(const RPN & rhs)
{
    (void)rhs;
    return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> public static member functions */

int RPN::calculate(char const * arg)
{
    std::stack<int> pile;
    int             result = 0;
    t_str_c         input  = parse_arguments(arg);

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
            result =
                next_calculation(get_and_remove_top(pile),
                                 get_and_remove_top(pile), get_operator(*it));
            pile.push(result);
        }
    }
    return result;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> private static member functions */

void RPN::log_debug(std::string const & message)
{
    (void)message;
#ifdef DEBUG
    std::cout << YELLOW << message << RESET << "\n";
#endif // DEBUG
}

bool RPN::is_char_of(char c, std::string const & set)
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

bool RPN::check_valid_chars(std::string const & str)
{
    size_t pos = str.find_first_not_of(DIGITS + OPERATORS + " ");
    if (pos != std::string::npos)
    {
        return false;
    }
    return true;
}

bool RPN::check_valid_spacing(std::string const & str)
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

std::string const RPN::itostr(int number)
{
    std::stringstream ss;
    ss << number;
    return ss.str();
}

std::string const RPN::parse_arguments(char const * arg)
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

int RPN::get_operator(char c)
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

int RPN::get_and_remove_top(std::stack<int> & pile)
{
    int tmp = pile.top();
    pile.pop();
    return tmp;
}

int RPN::next_calculation(int no_right, int no_left, int expression)
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

// -------------------------------------------------------------------------- //
