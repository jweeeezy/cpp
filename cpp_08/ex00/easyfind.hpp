// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  easyfind.hpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <algorithm> // needed for std::find
#include <stdexcept> // needed for std::runtime_error

/* cant handle associative containers like std::map, std::set */

template <typename T>
typename T::const_iterator easyfind(T const & container, int value)
{
    typename T::const_iterator cit;
    cit = std::find(container.begin(), container.end(), value);
    if (cit != container.end())
    {
        return cit;
    }
    throw std::runtime_error("Value not found!");
};

// -------------------------------------------------------------------------- //
