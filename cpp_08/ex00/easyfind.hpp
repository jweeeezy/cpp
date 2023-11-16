// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  easyfind.hpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <stdexcept> // needed for std::runtime_error

/* c++03 would be to use std::find */
/* cant handle associative containers like std::map, std::set */
/* could use container.find() for that. that would restrict other containers */

template <typename T>
typename T::const_iterator easyfind(T const & container, int value)
{
    for (typename T::const_iterator it = container.begin();
         it != container.end();
         ++it)
    {
        if (*it == value)
        {
            return it;
        }
    }
    throw std::runtime_error("Value not found!");
};

// -------------------------------------------------------------------------- //
