// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  RobotomyRequestForm.hpp                                             //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp" // needed for AForm class, Bureaucrat class, std::string

class RobotomyRequestForm : public AForm
{

	public:

		void execute(Bureaucrat const& executor) const;

		RobotomyRequestForm(std::string const& target);
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& src);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

};

#endif // ROBOTOMYREQUESTFORM

// -------------------------------------------------------------------------- //
