// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  AScalarConverter_convert.cpp                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "AScalarConverter.hpp" // needed for Type struct
#include <cstdlib>              // needed for atoi(), atof()
#include <iostream>             // needed for std::cout
#include <limits>
#include <sstream> // needed for std::istringstream

#define PREFIX_CHAR "char:   "
#define PREFIX_INT "int:    "
#define PREFIX_FLOAT "float:  "
#define PREFIX_DOUBLE "double: "

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> helper functions */

static bool isPrintable(std::string const & input)
{
    for (std::string::const_iterator itr = input.begin(); itr != input.end();
         ++itr)
    {
        if (std::isprint(static_cast<unsigned char>(*itr)) == false)
        {
            return false;
        }
    }
    return true;
}

// void printConversion(char c, int i, double d, float f)
//{
//
//     if (c < 32 || c == 127)
//     {
//         std::cout << "char:   "
//                   << "Non displayable\n";
//     }
//     else
//     {
//         std::cout << "char:   '" << c << "'\n";
//     }
//     std::cout << "int:    " << i << "\n";
//     std::cout << "float:  " << f << "f\n";
//     std::cout << "double: " << d << "\n";
// }

static bool hasTrailingF(std::string const & input)
{
    if (*(input.end() - 1) == 'f')
    {
        return true;
    }
    return false;
}

static bool isNumber(std::string const & input)
{
    if (input.find_first_not_of("0123456789-+.f") != std::string::npos)
    {
        return false;
    }
    if (input.length() <= 1 &&
        (hasTrailingF(input) == true || input.compare(".") == 0))
    {
        return false;
    }
    return true;
}

static bool hasDot(std::string const & input)
{
    if (input.size() >= 3)
    {
        for (std::string::const_iterator itr = input.begin();
             itr != input.end() - 2; ++itr)
        {
            char current = static_cast<unsigned char>(*itr);
            char next = *(itr + 1);
            char after_next = static_cast<unsigned char>(*(itr + 2));

            if (std::isdigit(current) == true && next == '.' &&
                std::isdigit(after_next) == true)
            {
                return true;
            }
        }
    }
    return false;
}

static bool isNan(std::string const & input)
{
    if (input == "nanf" || input == "nan" || input == "NANF" || input == "NAN")
    {
        return true;
    }
    return false;
}

static bool isInfNeg(std::string const & input)
{
    if (input == "-inf" || input == "-inff" || input == "-INF" ||
        input == "-INFF")
    {
        return true;
    }
    return false;
}

static bool isInfPos(std::string const & input)
{
    if (input == "inf" || input == "inff" || input == "+inf" ||
        input == "+inff" || input == "INF" || input == "INFF" ||
        input == "+INF" || input == "+INFF")
    {
        return true;
    }
    return false;
}

static ScalarConverter::Type identifyType(std::string const & input)
{
    if (isNan(input) == true)
    {
        return (ScalarConverter::NANF);
    }
    if (isInfNeg(input) == true)
    {
        return (ScalarConverter::INFNEG);
    }
    if (isInfPos(input) == true)
    {
        return (ScalarConverter::INFPOS);
    }
    if (isPrintable(input) == false)
    {
        return (ScalarConverter::NON_PRINTABLE);
    }
    if (isNumber(input) == true)
    {
        if (hasTrailingF(input) == true)
        {
            return (ScalarConverter::FLOAT);
        }
        else if (hasDot(input) == true)
        {
            return (ScalarConverter::DOUBLE);
        }
        else
        {
            if (input.find("f") != std::string::npos ||
                input.find(".") != std::string::npos)
            {
                return (ScalarConverter::NON_TYPE);
            }
            return (ScalarConverter::INTEGER);
        }
    }
    else
    {
        if (input.length() >= 2)
        {
            return (ScalarConverter::STRING);
        }
        return (ScalarConverter::CHAR);
    }
}

int stringToInt(std::string const & input)
{
    int value;
    std::istringstream stream(input);

    if (stream >> value)
    {
    }

    std::cout << value;
    return value;
}

void printChar(long int value)
{
    if (value < std::numeric_limits<char>::min() ||
        value > std::numeric_limits<char>::max())
    {
        std::cout << PREFIX_CHAR << "overflow/underflow\n";
    }
    else if (value < 32 || value > 127)
    {
        std::cout << PREFIX_CHAR << "non_displayable\n";
    }
    else
    {
        std::cout << PREFIX_CHAR << static_cast<char>(value) << "\n";
    }
}

void printInt(long int value)
{
    if (value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max())
    {
        std::cout << PREFIX_INT << "overflow/underflow\n";
    }
    else
    {
        std::cout << PREFIX_INT << value << "\n";
    }
}

void printDouble(long double value)
{
    if (value < std::numeric_limits<double>::min() ||
        value > std::numeric_limits<double>::max())
    {
        std::cout << PREFIX_DOUBLE << "overflow/underflow\n";
    }
    else
    {
        std::cout << PREFIX_DOUBLE << value;
        if (value == static_cast<int>(value))
        {
            std::cout << ".0";
        }
        std::cout << "\n";
    }
}

void printFloat(long double value)
{
    if (value < std::numeric_limits<float>::min() ||
        value > std::numeric_limits<float>::max())
    {
        std::cout << PREFIX_FLOAT << "overflow/underflow\n";
    }
    else
    {
        std::cout << PREFIX_FLOAT << value;
        if (value == static_cast<int>(value))
        {
            std::cout << ".0f";
        }
        std::cout << "\n";
    }
}
/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> convert function */

void ScalarConverter::convert(std::string const & input)
{
    char c;
    int  i;

    switch (identifyType(input))
    {
    case CHAR:
        c = static_cast<char>(input[0]);
        printChar(c);
        printInt(static_cast<long int>(c));
        printDouble( static_cast<long double>(c));
        printFloat(static_cast<long double>(c));
        break;
    case INTEGER:
        i = atoi(input.c_str());
        printInt(static_cast<long int>(i));
        printChar(static_cast<long int>(i));
        printDouble( static_cast<long double>(i));
        printFloat(static_cast<long double>(i));
        break;
    case DOUBLE:
        /* not yet implemented */
        break;
    case FLOAT:
        /* not yet implemented */
        break;
    case INFNEG:
        std::cout << "char:   non displayable\n"
                  << "int:    nnn displayable\n"
                  << "double: -inf\n"
                  << "float:  -inff\n";
        return;
    case INFPOS:
        std::cout << "char:   non displayable\n"
                  << "int:    non displayable\n"
                  << "double: +inf\n"
                  << "float:  +inff\n";
        return;
    case NANF:
        std::cout << "char:   non displayable\n"
                  << "int:    non displayable\n"
                  << "double: nan\n"
                  << "float:  nanf\n";
        return;
    case STRING:
        throw StringException();
    case NON_PRINTABLE:
        throw NonPrintableException();
    case NON_TYPE:
        throw NoTypeIdentifiedException();
    }
}

// -------------------------------------------------------------------------- //
