// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Span.hpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream> // needed for std::ostream
#include <vector>   // needed for std::vector

class Span
{

  public:
    /* constructors */
    Span();
    Span(unsigned int N);
    Span(const Span & src);
    ~Span();
    Span & operator=(const Span & rhs);

    /* member functions */
    void              addNumber(int number);
    void              addNumbersByVector(std::vector<int>::const_iterator begin,
                                         std::vector<int>::const_iterator end);
    unsigned int      shortestSpan() const;
    unsigned int      longestSpan() const;
    std::string const getNumbers() const;

  private:
    /* exceptions */
    class TooManyNumbersException : public std::exception
    {
      public:
        const char * what() const throw()
        {
            return "Span: Can not add more numbers (max numbers reached)!";
        }
    };
    class NoViableSpanException : public std::exception
    {
      public:
        const char * what() const throw()
        {
            return "Span: Calculating Span is impossible (too few numbers)!";
        }
    };

    /* member variables */
    unsigned int     _max_n;
    std::vector<int> _numbers;
};
#endif // SPAN_HPP

// --------------------------------------------------------------------------
// //
