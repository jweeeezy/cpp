// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  StopWatch.hpp                                                       //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include <ctime> // needed for std::clock_t, std::clock

class StopWatch
{
  public:
    StopWatch();
    StopWatch(StopWatch const & src);
    ~StopWatch();
    StopWatch & operator=(StopWatch const & rhs);

    void   start();
    void   stop();
    double get_measured_time() const;

  private:
    std::clock_t _start;
    std::clock_t _end;
    double       _measured_time;
};

#endif // STOPWATCH

// -------------------------------------------------------------------------- //
