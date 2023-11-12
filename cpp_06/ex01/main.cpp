// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "ASerializer.hpp" // needed for ASerializer class, Data struct
#include <cstdlib>         // needed for MACROS
#include <iostream>        // needed for std::cout

#define GREEN "\033[32m"
#define RESET "\033[0m"

/* log function */

static inline void test_log(std::string const & message)
{
    std::cout << GREEN << "\n< " << message << " >" << RESET << std::endl;
}

void data_populate(Data * ptr)
{
    ptr->address = "Somestr. 17, 74076 Heilbronn";
    ptr->no_floors = 3;
    ptr->no_bedrooms = 7;
    ptr->no_bathrooms = 4;
    ptr->no_kitchen = 2;
    std::cout << "Struct populated!\n";
}

void data_print(Data * ptr)
{
    std::cout << "<<         House information         >>\n";
    std::cout << "bedrooms:  " << ptr->no_bedrooms << "\n";
    std::cout << "bathrooms: " << ptr->no_bathrooms << "\n";
    std::cout << "kitchen:   " << ptr->no_kitchen << "\n";
    std::cout << "address:   " + ptr->address + "\n";
}

int main()
{
    test_log("Initialising and populating Data struct");
    Data d;
    data_populate(&d);

    test_log("Printing Data with struct address");
    data_print(&d);

    test_log("Address of Data structure");
    std::cout << &d << "\n";

    test_log("Serialising into a uintptr_t var");
    uintptr_t iptr;
    iptr = ASerializer::serialize(&d);
    std::cout << iptr << "\n";

    test_log("Deserialising the uintptr_t var");
    Data *dptr = ASerializer::deserialize(iptr);
    std::cout << dptr << "\n";

    test_log("Printing Data with dptr");
    data_print(dptr);

    /* if object is not alive this would lead to errors */

    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
