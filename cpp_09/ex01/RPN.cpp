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

#ifdef DEBUG
#include <iostream> // needed for std::cerr
#endif

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

    for (t_str_cit it = input.begin(); it != input.end(); ++it)
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
            result = next_operation(get_and_remove_top(pile),
                                    get_and_remove_top(pile),
                                    get_operator(*it));
            pile.push(result);
        }
    }
    if (pile.size() >= 2)
    {
        throw std::runtime_error("invalid operation!");
    }
    return result;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> private static member functions */

bool RPN::check_valid_chars(t_str_c & str)
{
    size_t pos = str.find_first_not_of(DIGITS + OPERATORS + " ");
    if (pos != std::string::npos)
    {
        return false;
    }
    return true;
}

bool RPN::check_valid_spacing(t_str_c & str)
{
    t_str_cit end = str.end();
    for (t_str_cit it = str.begin(); it != end; ++it)
    {
        if (is_char_of(*it, DIGITS + OPERATORS) == true && it + 1 != end &&
            *(it + 1) != ' ')
        {
            return false;
        }
    }
    return true;
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

bool RPN::is_char_of(char c, t_str_c & set)
{
    for (t_str_cit it = set.begin(); it != set.end(); ++it)
    {
        if (*it == c)
        {
            return true;
        }
    }
    return false;
}

RPN::t_str_c RPN::itostr(int number)
{
    std::stringstream ss;
    ss << number;
    return ss.str();
}

void RPN::log_debug(t_str_c & message)
{
    (void)message;
#ifdef DEBUG
    std::cerr << YELLOW << message << RESET << "\n";
#endif // DEBUG
}

int RPN::next_operation(int no_left, int no_right, int expression)
{
    switch (expression)
    {
        case MULTIPLICATE:
            log_debug(itostr(no_left) + " * " + itostr(no_right));
            no_left *= no_right;
            break;
        case DIVIDE:
            if (no_right == 0)
            {
                throw std::runtime_error("division by zero not allowed!");
            }
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

RPN::t_str_c RPN::parse_arguments(char const * arg)
{
    t_str_c & tmp = arg;
    if (tmp.empty() == true)
    {
        throw std::invalid_argument("empty string!");
    }
    if (check_valid_chars(tmp) == false)
    {
        throw std::invalid_argument("invalid character!");
    }
    if (check_valid_spacing(tmp) == false)
    {
        throw std::invalid_argument("invalid spacing!");
    }
    return tmp;
}

// -------------------------------------------------------------------------- //
