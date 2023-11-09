// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Form.hpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp" // needed for Bureaucrat class,
                          // std::string, std::ostream

class Form
{

  private:
    std::string const  name;
    bool               signed_status;
    unsigned short int req_grade_sign;
    unsigned short int req_grade_exec;

  public:
    /* constructors */
    Form            (std::string const & name, unsigned short int req_sign,
                     unsigned short int req_exec);
    Form            ();
    Form            (const Form & src);
    ~Form           ();
    Form & operator=(const Form & rhs);

    /* member functions */
    std::string const & getName        () const;
    bool                getSignStatus  () const;
    unsigned short int  getReqGradeSign() const;
    unsigned short int  getReqGradeExec() const;

    void                beSigned(Bureaucrat const & b);

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

std::ostream & operator<<(std::ostream & os, const Form & rhs);

#endif // FORM_HPP

// -------------------------------------------------------------------------- //
