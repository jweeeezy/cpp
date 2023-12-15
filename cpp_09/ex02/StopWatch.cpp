// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  StopWatch.cpp                                                       //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "StopWatch.hpp" // needed for StopWatch class
#include <string>        // needed for std::string

#ifdef DEBUG
#include <iostream> // needed for std::cerr
#endif              // DEBUG

#define YELLOW "\033[33m"
#define RESET  "\033[0m"

#define CLOCKS_PER_MS CLOCKS_PER_SEC * 1000.0

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void log_debug(std::string const & message)
{
    (void)message;
#ifdef DEBUG
    std::cerr << YELLOW << "StopWatch: " << message << RESET << "\n";
#endif // DEBUG
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

StopWatch::StopWatch() { log_debug("default constructor called"); }

StopWatch::StopWatch(StopWatch const & src)
{
    log_debug("copy constructor called");
    *this = src;
}

StopWatch::~StopWatch() { log_debug("destructor called"); }

StopWatch & StopWatch::operator=(StopWatch const & rhs)
{
    log_debug("assignment operator called");
    if (this != &rhs)
    {
        _start = rhs._start;
        _end = rhs._end;
        _measured_time = rhs._measured_time;
    }
    return *this;
}

double StopWatch::get_measured_time() const { return _measured_time; }

void StopWatch::start()
{
    _start = std::clock();
    if (_start == std::clock_t(-1))
    {
        throw std::runtime_error(
            "StopWatch.start(): Cannot retrieve std::clock()");
    }
}

void StopWatch::stop()
{
    _end = std::clock();
    if (_end == std::clock_t(-1))
    {
        throw std::runtime_error(
            "StopWatch.stop(): Cannot retrieve std::clock()");
    }
    _measured_time = static_cast<double>(_end - _start) / CLOCKS_PER_MS;
}

// --------------------------------------------------------------------------
// //
