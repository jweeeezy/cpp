// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  PresidentialPardonForm.hpp                                          //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp" // needed for AForm class, Bureaucrat class, std::string

class PresidentialPardonForm : public AForm
{

  public:
    /* constructors */
    PresidentialPardonForm            (std::string const & target);
    PresidentialPardonForm            ();
    PresidentialPardonForm            (const PresidentialPardonForm & src);
    ~PresidentialPardonForm           ();
    PresidentialPardonForm & operator=(const PresidentialPardonForm & rhs);

    /* member functions */
    void execute(Bureaucrat const & executor) const;

};

#endif // PRESIDENTIALPARDONFORM

// -------------------------------------------------------------------------- //
