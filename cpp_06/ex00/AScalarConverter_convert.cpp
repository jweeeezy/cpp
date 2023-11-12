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
#include <sstream>              // needed for std::istringstream

#define PREFIX_CHAR "char:   "
#define PREFIX_INT "int:    "
#define PREFIX_FLOAT "float:  "
#define PREFIX_DOUBLE "double: "

enum Type
{
    CHAR,
    INTEGER,
    DOUBLE,
    FLOAT,
    INFNEG,
    INFPOS,
    NANF,
    STRING,
    NON_TYPE,
    NON_PRINTABLE,
};

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> helper functions */

static bool isNan(std::string const & input)
{
    if (input == "nanf" || input == "nan" || input == "NANF" || input == "NAN")
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

static bool isInfNeg(std::string const & input)
{
    if (input == "-inf" || input == "-inff" || input == "-INF" ||
        input == "-INFF")
    {
        return true;
    }
    return false;
}

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

static bool hasMultipleF(std::string const & input)
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

static long double getFloat(std::string const & input)
{
    long double f;
    std::istringstream iss(input.substr(0, input.size() - 1));
    iss >> f;
    return f;
}

static Type identifyType(std::string const & input)
{
    if (isNan(input) == true)
    {
        return (NANF);
    }
    if (isInfNeg(input) == true)
    {
        return (INFNEG);
    }
    if (isInfPos(input) == true)
    {
        return (INFPOS);
    }
    if (isPrintable(input) == false)
    {
        return (NON_PRINTABLE);
    }
    if (isNumber(input) == true)
    {
        if (hasMultipleF(input) == true)
        {
            return (NON_TYPE);
        }
        if (hasTrailingF(input) == true)
        {
            return (FLOAT);
        }
        if (hasDot(input) == true)
        {
            return (DOUBLE);
        }
        if (input.find("f") != std::string::npos ||
            input.find(".") != std::string::npos)
        {
            return (NON_TYPE);
        }
        return (INTEGER);
    }
    if (input.length() >= 2)
    {
        return (STRING);
    }
    return (CHAR);
}

void printChar(long int value)
{
    if ((value < 32 && value > 0) || (value > 126 && value <= 255))
    {
        std::cout << PREFIX_CHAR << "non_displayable\n";
    }
    else if (value < std::numeric_limits<char>::min() ||
             value > std::numeric_limits<char>::max())
    {
        std::cout << PREFIX_CHAR << "overflow/underflow\n";
    }
    else
    {
        std::cout << PREFIX_CHAR << "'" << static_cast<char>(value) << "'\n";
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
    std::istringstream iss(input);
    char c;
    long int i;
    long double d;

    switch (identifyType(input))
    {
    case CHAR:
        iss >> c;
        printChar(c);
        printInt(static_cast<long int>(c));
        printFloat(static_cast<long double>(c));
        printDouble(static_cast<long double>(c));
        break;
    case INTEGER:
        iss >> i;
        printChar(i);
        printInt(i);
        printFloat(static_cast<long double>(i));
        printDouble(static_cast<long double>(i));
        break;
    case DOUBLE:
        iss >> d;
        printChar(static_cast<long int>(d));
        printInt(static_cast<long int>(d));
        printFloat(d);
        printDouble(d);
        break;
    case FLOAT:
        d = getFloat(input);
        printChar(static_cast<long int>(d));
        printInt(static_cast<long int>(d));
        printFloat(d);
        printDouble(d);
        break;
    case INFNEG:
        std::cout << "char:   impossible\n"
                  << "int:    impossible\n"
                  << "double: -inf\n"
                  << "float:  -inff\n";
        return;
    case INFPOS:
        std::cout << "char:   impossible\n"
                  << "int:    impossible\n"
                  << "double: +inf\n"
                  << "float:  +inff\n";
        return;
    case NANF:
        std::cout << "char:   impossible\n"
                  << "int:    impossible\n"
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
