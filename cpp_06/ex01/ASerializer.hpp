// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  ASerializer.hpp                                                     //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef ASERIALIZER_HPP
#define ASERIALIZER_HPP

#include "Data.hpp" // needed for Data struct
#include <stdint.h> // needed for uintptr_t

class ASerializer
{
  public:
    
    /* static functions */
    static uintptr_t serialize  (Data * ptr);
    static Data *    deserialize(uintptr_t raw);

  private:
    
    /* constructors */
    ASerializer            ();
    ASerializer            (const ASerializer & src);
    ~ASerializer           ();
    ASerializer & operator=(const ASerializer & rhs);

};

#endif // ASERIALIZER_HPP

// -------------------------------------------------------------------------- //
