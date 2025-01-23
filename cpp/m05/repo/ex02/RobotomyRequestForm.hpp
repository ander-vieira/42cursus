#ifndef ROBOTOMY_REQUEST_FORM_H
# define ROBOTOMY_REQUEST_FORM_H

# include <iostream>
# include <cstdlib>
# include <ctime>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(std::string const &target);
		~RobotomyRequestForm();
		std::string const &getTarget() const;
	protected:
		void doThing() const;
	private:
		std::string const target;
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &f);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &f);
};

#endif