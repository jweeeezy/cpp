// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Intern.hpp                                                          //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp" // needed for AForm class

#define FORM_COUNT 3

class Intern
{

  public:
    /* constructors */
    Intern            ();
    Intern            (const Intern & src);
    ~Intern           ();
    Intern & operator=(const Intern & rhs);

    /* member functions */
    AForm * makeForm(std::string const & form,
                     std::string const & target) const;

    class UnknownFormException : public std::exception
    {
      public:
        const char * what() const throw()
        {
            return "Intern: I dont know this form!";
        }
    };

  private:
    /* static variables  */
    typedef struct s_function_map
    {
        std::string const name;
        AForm * (Intern::*create)(std::string const & target) const;
    } t_func_map;

    static t_func_map forms[FORM_COUNT];

    /* member functions */
    AForm * makeSCF(std::string const & target) const;
    AForm * makeRRF(std::string const & target) const;
    AForm * makePPF(std::string const & target) const;
};

#endif // INTERN

// -------------------------------------------------------------------------- //
