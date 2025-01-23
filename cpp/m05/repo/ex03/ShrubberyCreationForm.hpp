#ifndef SHRUBBERY_CREATION_FORM_H
# define SHRUBBERY_CREATION_FORM_H

# include <iostream>
# include <fstream>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(std::string const &target);
		~ShrubberyCreationForm();
		std::string const &getTarget() const;
	protected:
		void doThing() const;
	private:
		std::string const target;
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &f);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &f);
};

#endif