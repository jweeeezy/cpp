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
#include <fstream>  // needed for std::ifstream
#include <iostream> // needed for std::cerr
#include <sstream>  // needed for std::stringstream

#define EXPECTED_ARGC 2

static bool has_trailing_f(std::string const & input)
{
    if (*(input.end() - 1) == 'f')
    {
        return true;
    }
    return false;
}

static bool has_multiple_F(std::string const & input)
{
    size_t counter = 0;
    for (std::string::const_iterator it = input.begin(); it != input.end();
         ++it)
    {
        if (*it == 'f')
        {
            ++counter;
            if (counter > 1)
            {
                return true;
            }
        }
    }
    return false;
}

std::string remove_whitespaces(std::string const & str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end   = str.find_last_not_of(" \t\n\r");
    if (start == std::string::npos || end == std::string::npos)
    {
        return "";
    }
    return str.substr(start, end - start + 1);
}

int main(int argc, char ** argv)
{
    if (argc != EXPECTED_ARGC)
    {
        std::cerr << "Usage:\n[ ./btc <filename> ]";
        return (EXIT_FAILURE);
        /* @note how is usage usually displayed? */
    }
    std::string arg = argv[1];
    if (arg.empty() == true)
    {
        std::cerr << "Usage:\n[ ./btc <filename> ]";
        return (EXIT_FAILURE);
    }

    /* @note database file */
    std::ifstream file_database("data.csv");
    std::string   line;
    //   std::cout << "Content of file\n";
    while (std::getline(file_database, line))
    {
        //        std::cout << line << "\n";
    }

    /* @note second input file */
    std::ifstream file_input(arg.c_str());
    if (!file_input)
    {
        std::cerr << "Usage:\n[ ./btc <filename> ]";
        return (EXIT_FAILURE);
    }

    while (std::getline(file_input, line))
    {
        size_t pos = line.find("|");
        if (pos == std::string::npos)
        {
            std::cerr << "Error: Wrong Input file format!\n";
            return (EXIT_FAILURE);
        }
        std::string first_half = line.substr(0, pos);

        if (first_half == "date " || first_half == "Date ")
        {
            continue;
        }
        /* test date older than database */
        /* test wrong month/year/day */
        /* edge cases for these numbers */

        std::stringstream ss(first_half);
        unsigned int      i = 0;
        std::string       token;
        std::string       year;
        std::string       month;
        std::string       date;

        /* @note mb use std::isstream no check types? */
        bool eol = false;
        while (eol == false)
        {
            if (std::getline(ss, token, '-').eof() == true)
            {
                eol = true;
            }
            token = remove_whitespaces(token);
            if (token.empty() == true)
            {
                std::cerr << "some token.empty() error";
                return (EXIT_FAILURE);
            }
            ++i;
            switch (i)
            {
                case 1:
                    if (token.size() != 4)
                    {
                        std::cerr << "Error: Wrong year format!\n";
                        return (EXIT_FAILURE);
                    }
                    break;
                case 2:
                    if (token.size() != 2)
                    {
                        std::cerr << "Error: Wrong month format!\n";
                        return (EXIT_FAILURE);
                    }
                    break;
                case 3:
                    if (token.substr(0, token.find(" ")).size() != 2)
                    {
                        std::cerr << "Error: Wrong day format!\n";
                        return (EXIT_FAILURE);
                    }
                    break;
                default:
                    std::cerr << "Some date formatting error!\n";
                    return (EXIT_FAILURE);
            }
            // std::cout << token << "\n";
        }
        // std::cout << date << month << year << "\n";
        /* note check if pos + 1 is not the end */

        if (pos + 1 == line.size())
        {
            std::cerr << "Some formatting error in input file\n";
            return (EXIT_FAILURE);
        }

        std::string second_half =
            remove_whitespaces(line.substr(pos + 1, line.size()));

        if (second_half.empty() == true)
        {
            std::cerr << "Some formatting error in input file\n";
            return (EXIT_FAILURE);
        }

        //        if (second_half.size() > 4)
        //        {
        //            std::cerr << "Value is too high!\n";
        //        }

        /* @note check for f (use cpp06 functions) */
        /* --> float */

        /* else */
        /* --> int */

        /* check if > 1000 */

        /* check for max and min */
    }

    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
