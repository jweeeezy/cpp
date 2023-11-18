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

#include <vector> // needed for std::vector

class Span
{
  public:
    Span();
    Span(unsigned int N);
    Span(const Span & src);
    ~Span();
    Span & operator=(const Span & rhs);

    void         addNumber(int number);
    unsigned int shortestSpan();
    unsigned int longestSpan();
    
  private:
    unsigned int     _max_n;
    std::vector<int> _numbers;
};

#endif // SPAN_HPP

// -------------------------------------------------------------------------- //
