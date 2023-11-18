// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Span.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Span.hpp" // needed for Span class
#include <string>   // needed for std::string

#define YELLOW "\033[33m"
#define RESET  "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void log_debug(std::string const & message)
{
    (void)message;
#ifdef DEBUG
    std::cout << YELLOW << "Span: " << message << RESET << "\n";
#endif // DEBUG
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

Span::Span() { log_debug("default constructor called"); }

Span::Span(unsigned int N) : _max_n(N)
{
    log_debug("max N constructor called");
}

Span::Span(const Span & src) : _max_n(src._max_n)
{
    log_debug("copy constructor called");
    /* @note deep copy! */
}

Span::~Span() { log_debug("destructor called"); }

Span & Span::operator=(const Span & rhs)
{
    (void) rhs;
    /* @note deep copy! */
    log_debug("assignment operator called");
    return *this;
}

void Span::addNumber(int number) { _numbers.push_back(number); }

unsigned int Span::shortestSpan() { return 0; }

unsigned int Span::longestSpan()
{
    int longest_span = 0;
    int tmp          = 0;
    for (std::vector<int>::const_iterator current = _numbers.begin();
         current != _numbers.end();
         ++current)
    {
        std::vector<int>::const_iterator next = current + 1;
        if (next != _numbers.end())
        {
            tmp = (*current - *next);
            if (tmp < 0)
            {
                tmp *= -1;
            }
            if (tmp > longest_span)
            {
                longest_span = tmp;
            }
        }
    }
    return longest_span;
    /* @note throw exception */
}

// -------------------------------------------------------------------------- //
