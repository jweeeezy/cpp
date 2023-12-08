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
#include <string>   // needed for std::string

#define EXPECTED_ARGC 2

#define DIGITS      "0123456789"
#define EXPRESSIONS "+-/*"

/* struct for parsing */
struct s_calculation
{
    std::string numbers;
    std::string expressions;
};

enum expressions
{
    MULTIPLICATE,
    DIVIDE,
    ADD,
    SUBSTRACT
};

/* used for debugging only */
void print(std::stack<char> tmp)
{
    while (tmp.empty() == false)
    {
        std::cout << tmp.top() << "\n";
        tmp.pop();
    }
}

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
        if (is_char_of(*it, "0123456789+-/*") == true && it + 1 != end &&
            *(it + 1) != ' ')
        {
            return false;
        }
    }
    return true;
}

static bool check_valid_chars(std::string const & str)
{
    size_t pos = str.find_first_not_of("0123456789 +-/*");
    if (pos != std::string::npos)
    {
        return false;
    }
    return true;
}

struct s_calculation part_arguments(std::string const & str)
{
    std::stringstream expressions;
    std::stringstream numbers;
    for (std::string::const_reverse_iterator it = str.rbegin();
         it != str.rend(); ++it)
    {
        if (is_char_of(*it, "0123456789") == true)
        {
            numbers << *it;
        }
        else if (is_char_of(*it, "*-/+") == true)
        {
            expressions << *it;
        }
    }
    s_calculation tmp;
    tmp.numbers     = numbers.str();
    tmp.expressions = expressions.str();
    if (tmp.numbers.size() != tmp.expressions.size() + 1)
    {
        throw std::runtime_error("Disbalance!");
        /* @note expressive error message */
    }
    return tmp;
}

static std::stack<char> order_arguments(struct s_calculation const & arguments)
{
    std::stack<char> tmp_stack;

    for (size_t i = 0; i != arguments.numbers.size(); ++i)
    {
        tmp_stack.push(arguments.numbers[i]);
        if (i < arguments.expressions.size())
            tmp_stack.push(arguments.expressions[i]);
    }
    return tmp_stack;
}

static std::stack<char> extract_arguments(std::string const & str)
{
    s_calculation const &    split_args   = part_arguments(str);
    std::stack<char> const & ordered_args = order_arguments(split_args);
    return ordered_args;
}

static int next_calculation(int result, int number, int expression)
{
    switch (expression)
    {
        case MULTIPLICATE:
            std::cout << result << " * " << number << "\n";
            result *= number;
            break;
        case DIVIDE:
            std::cout << result << " / " << number << "\n";
            result /= number;
            break;
        case ADD:
            std::cout << result << " + " << number << "\n";
            result += number;
            break;
        case SUBSTRACT:
            std::cout << result << " - " << number << "\n";
            result -= number;
            break;
        default:
            throw std::runtime_error("What the fuck\n");
    }
    return result;
}

static int calculate_result(std::stack<char> args)
{
    size_t            size_full  = args.size();
    size_t            size       = size_full;
    int               result     = 0;
    int               expression = 4;
    std::stringstream ss;
    while (size > 0)
    {
        char tmp = args.top();
        if (is_char_of(tmp, "0123456789") == true)
        {
            if (size == size_full) /* first iteration */
            {
                std::stringstream ss;
                ss << tmp;

                int number;
                ss >> number;
                result = number;
                std::cout << number << "\n";
            }
            else
            {
                std::stringstream ss;
                ss << tmp;

                int number;
                ss >> number;
                result = next_calculation(result, number, expression);
            }
        }
        else
        {
            if (tmp == '*')
            {
                expression = MULTIPLICATE;
            }
            else if (tmp == '/')
            {
                expression = DIVIDE;
            }
            else if (tmp == '+')
            {
                expression = ADD;
            }
            else if (tmp == '-')
            {
                expression = SUBSTRACT;
            }
        }
        args.pop();
        --size;
    }
    return result;
}

int main(int argc, char ** argv)
{
    if (argc != EXPECTED_ARGC)
    {
        std::cerr << "error: missing argument!\n";
        return (EXIT_FAILURE);
    }

    std::string const & arg = argv[1];
    if (check_valid_chars(arg) == false || check_valid_spacing(arg) == false)
    {
        std::cerr << "error!\n";
        return (EXIT_FAILURE);
    }

    try
    {
        std::stack<char> args = extract_arguments(arg);
        int result = calculate_result(args);
        std::cout << "Result: " << result;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << "\n";
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
