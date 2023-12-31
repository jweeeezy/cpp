// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  ShrubberyCreationForm.hpp                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp" // needed for AForm class, Bureaucrat class, std::string

class ShrubberyCreationForm : public AForm
{

  public:
    /* constructors */
    ShrubberyCreationForm            (std::string const & target);
    ShrubberyCreationForm            ();
    ShrubberyCreationForm            (const ShrubberyCreationForm & src);
    ~ShrubberyCreationForm           ();
    ShrubberyCreationForm & operator=(const ShrubberyCreationForm & rhs);

    /* member functions */
    void execute(Bureaucrat const & executor) const;

};

#endif // SHRUBBERYCREATIONFORM

// -------------------------------------------------------------------------- //
