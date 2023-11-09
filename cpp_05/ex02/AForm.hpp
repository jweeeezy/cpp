// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  AForm.hpp                                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp" // needed for Bureaucrat class,
                          // std::string, std::ostream

class AForm
{

  private:
    std::string const  name;
    bool               sign_status;
    unsigned short int req_grade_sign;
    unsigned short int req_grade_exec;
    std::string        target;             /* <-- new! */

  public:
    /* constructors */
    AForm         (std::string const name, unsigned short int req_sign,
                   unsigned short int req_exec);
    AForm         ();
    AForm         (const AForm & src);
    virtual ~AForm();                      /* <-- made virtual */
    AForm & operator=(const AForm & rhs);

    /* member functions */
    std::string const & getName        () const;
    unsigned short int  getReqGradeSign() const;
    unsigned short int  getReqGradeExec() const;
    bool                getSignStatus  () const;
    std::string const & getTarget      () const; /* <-- new! */

    void                beSigned       (Bureaucrat & b);

    void                setTarget      (std::string const target);
                                           /* <-- new! */
    virtual void        execute        (Bureaucrat const & executor) const = 0;
                                           /* <-- new! */

    /* exceptions */
    class NotSignedException : public std::exception
    {
      public:
        const char * what() const throw() { return "Form is not signed yet!"; }
    };

    class GradeTooHighException : public std::exception
    {
      public:
        const char * what() const throw() { return "Grade is too high!"; }
    };

    class GradeTooLowException : public std::exception
    {
      public:
        const char * what() const throw() { return "Grade is too low!"; }
    };

};

std::ostream & operator<<(std::ostream & os, const AForm & rhs);

#endif // AFORM_HPP

// -------------------------------------------------------------------------- //
