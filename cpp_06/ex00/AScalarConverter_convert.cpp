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

static void printConversion(char c, int i, double d, float f)
{

    /* @note handle over/underflows */
        /* check out std::numeric_limits */

    if (c < 32 || c == 127)
    {
        std::cout << "char:   "
                  << "Non displayable\n";
    }
    else
    {
        std::cout << "char:   '" << c << "'\n";
    }
    std::cout << "int:    " << i << "\n";
    std::cout << "float:  " << f << "f\n";
    std::cout << "double: " << d << "\n";
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

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> convert function */

void ScalarConverter::convert(std::string const & input)
{
    char c = 0;
    int i = 0;
    double d = 0.0;
    float f = 0.0f;

    switch (identifyType(input))
    {
    case CHAR:
        c = static_cast<char>(input[0]);
        i = static_cast<int>(c);
        d = static_cast<double>(c);
        f = static_cast<float>(c);
        break;
    case INTEGER:
        i = atoi(input.c_str());
        c = static_cast<char>(i);
        d = static_cast<double>(i);
        f = static_cast<float>(i);
        break;
    case DOUBLE:
        d = atof(input.c_str());
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
        break;
    case FLOAT:
        f = static_cast<float>(atof(input.c_str()));
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
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

    printConversion(c, i, d, f);
}

// -------------------------------------------------------------------------- //
