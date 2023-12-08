// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <cstdlib> // needed for MACROS
#include <iostream> // needed for std::cout, std::cerr
#include <sstream>  // needed for std::stringstream
#include <stack>    // needed for std::stack
#include <string>   // needed for std::string

#define EXPECTED_ARGC 2

/* MACROS for parsing */
#define NUMBER  false
#define EXPRESS true

bool is_char_of(char c, std::string const & set)
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

bool check_valid_spacing(std::string const & str)
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

bool check_valid_chars(std::string const & str)
{
    size_t pos = str.find_first_not_of("0123456789 +-/*");
    if (pos != std::string::npos)
    {
        return false;
    }
    return true;
}

struct s_calculation
{
    std::string numbers;
    std::string expressions;
};

struct s_calculation part_arguments(std::string const & str)
{
    std::stringstream expressions;
    std::stringstream numbers;
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
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
    }
    return tmp;
}

char get_next_char(std::string const & str)
{
    static std::string::const_iterator it = str.begin();
    if (it != str.end())
    {
        return *it++;
    }
    return 'A';
}

std::stack<char> order_arguments(struct s_calculation const & arguments)
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

std::stack<char> extract_arguments(std::string const & str)
{
    s_calculation const & split_args = part_arguments(str);
    std::stack<char> const & ordered_args = order_arguments(split_args);
    return ordered_args;
}

void print(std::stack<char> tmp)
{
    while (tmp.empty() == false)
    {
        std::cout << tmp.top() << "\n";
        tmp.pop();
    }
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
        print(args);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << "\n";
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
