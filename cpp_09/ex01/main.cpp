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
#include <stack>    // needed for std::stack
#include <string>   // needed for std::string

#define EXPECTED_ARGC 2
#define NUMBER        false
#define EXPRESS       true

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

std::stack<char> extract_arguments(std::string const & str)
{
    std::stack<char> tmp;
    bool             no_or_expr = NUMBER;
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
    {
        if (*it != ' ')
        {
            if (is_char_of(*it, "0123456789") == true && no_or_expr == NUMBER)
            {
                tmp.push(*it);
                no_or_expr = !no_or_expr;
            }
            else if (is_char_of(*it, "*-/+") == true && no_or_expr == EXPRESS)
            {
                tmp.push(*it);
                no_or_expr = !no_or_expr;
            }
        }
    }
    return tmp;
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

    std::stack<char> expr = extract_arguments(arg);
    
    while (expr.empty() == false)
    {
        std::cout << expr.top() << "\n";
        expr.pop();
    }

    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
