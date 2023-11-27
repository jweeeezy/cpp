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

        while (std::getline(ss, token, '-'))
        {
            if (token.empty() == true)
            {
                std::cerr << "some token.empty() error";
                return (EXIT_FAILURE);
            }
            ++i;
            switch (i)
            {
                case 1:
                    year = token;
                    if (year.size() != 4)
                    {
                        std::cerr << "Error: Wrong year format!\n";
                        return (EXIT_FAILURE);
                    }
                    break;
                case 2:
                    month = token;
                    if (month.size() != 2)
                    {
                        std::cerr << "Error: Wrong month format!\n";
                        return (EXIT_FAILURE);
                    }
                    break;
                case 3:
                    date = token.substr(0, token.find(" "));
                    if (date.size() != 2)
                    {
                        std::cerr << "Error: Wrong month format!\n";
                        return (EXIT_FAILURE);
                    }
                    break;
                default:
                    std::cerr << "Some date formatting error!\n";
                    return (EXIT_FAILURE);
            }
            std::cout << token << "\n";
        }
        std::cout << date << month << year << "\n";

        std::string second_half = line.substr(pos, line.size());
        /* test with floats/ints */
        /* edge cases for these numbers */
    }

    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
