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
# define FORM_HPP

#include "Bureaucrat.hpp" // needed for Bureaucrat class, 
						  // std::string, std::ostream

class Form
{

	private:
		
		std::string const  name;
		bool               sign_status;
		unsigned short int req_grade_sign;
		unsigned short int req_grade_exec;

	public:

		std::string const&  getName() const;
		unsigned short int  getReqGradeSign() const;
		unsigned short int  getReqGradeExec() const;
		bool                getSignStatus() const;

		void                beSigned(Bureaucrat &b);

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Grade is too high!";
				}
			
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Grade is too low!";
				}
			
		};

		Form(std::string const name,
		     unsigned short int req_sign,
			 unsigned short int req_exec);
		Form();
		Form(const Form& src);
		~Form();
		Form& operator=(const Form& rhs);

};

std::ostream &operator<<(std::ostream &os, const Form &rhs);

#endif // FORM_HPP

// -------------------------------------------------------------------------- //
