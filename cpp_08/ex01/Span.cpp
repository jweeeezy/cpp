// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Span.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Span.hpp"  // needed for Span class
#include <algorithm> // needed for std::next
#include <sstream>   // needed for std::stringstream
#include <stdexcept> // needed for std::runtime_error
#include <string>    // needed for std::string
#include <vector>    // needed for std::vector

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

Span::Span() : _max_n(0) { log_debug("default constructor called"); }

Span::Span(unsigned int N) : _max_n(N)
{
    log_debug("max N constructor called");
}

Span::Span(const Span & src) : _max_n(src._max_n)
{
    log_debug("copy constructor called");
    _numbers.clear();
    std::copy(src._numbers.begin(),
              src._numbers.end(),
              std::back_inserter(_numbers));
}

Span::~Span() { log_debug("destructor called"); }

Span & Span::operator=(Span const & rhs)
{
    log_debug("assignment operator called");
    if (this != &rhs)
    {
        _max_n = rhs._max_n;
        _numbers.clear();
        std::copy(rhs._numbers.begin(),
                  rhs._numbers.end(),
                  std::back_inserter(_numbers));
    }
    return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

void Span::addNumber(int number)
{
    if (_numbers.size() >= _max_n)
    {
        throw TooManyNumbersException();
    }
    _numbers.push_back(number);
}

void Span::addNumbersByVector(t_vec_int_cit begin, t_vec_int_cit end)
{
    t_vec_int sequence(begin, end);
    if (_numbers.size() + sequence.size() > _max_n)
    {
        throw TooManyNumbersException();
    }
    _numbers.insert(_numbers.end(), sequence.begin(), sequence.end());
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.empty() == true || _numbers.size() <= 1)
    {
        throw NoViableSpanException();
    }

    t_vec_int sorted_numbers = _numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());

    unsigned int shortest_span =
        static_cast<unsigned int>(sorted_numbers[1] - sorted_numbers[0]);

    for (size_t i = 2; i != sorted_numbers.size(); ++i)
    {
        unsigned int current_span = static_cast<unsigned int>(
            sorted_numbers[i] - sorted_numbers[i - 1]);
        if (current_span < shortest_span)
        {
            shortest_span = current_span;
        }
    }
    return shortest_span;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.empty() == true || _numbers.size() <= 1)
    {
        throw NoViableSpanException();
    }
    t_vec_int sorted_numbers = _numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());
    return static_cast<unsigned int>(sorted_numbers.back() -
                                     sorted_numbers.front());
}

std::string const Span::getNumbers() const
{
    std::stringstream ss;
    t_vec_int_cit     end = _numbers.end();
    for (t_vec_int_cit it = _numbers.begin(); it != end; ++it)
    {
        if (it + 1 == end)
        {
            ss << *it;
            break;
        }
        ss << *it << " ";
    }
    return ss.str();
}

// -------------------------------------------------------------------------- //
