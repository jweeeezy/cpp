// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Bureaucrat.hpp                                                      //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>   // needed for std::string, std::ostream

class AForm;

class Bureaucrat
{

	protected:

		std::string const name;
		unsigned short int grade;

	public:

		std::string const& getName() const;
		unsigned short int getGrade() const;

		void increment();
		void decrement();

		void signForm(AForm& f);
		void executeForm(AForm const& form);

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

		Bureaucrat(std::string const name, unsigned short int grade);
		Bureaucrat();
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& rhs);

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs);

#endif // BUREAUCRAT_HPP

// -------------------------------------------------------------------------- //
