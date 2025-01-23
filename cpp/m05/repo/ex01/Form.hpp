#ifndef FORM_H
# define FORM_H

# include <iostream>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(std::string const &name, int signGrade, int executeGrade);
		~Form();
		std::string const &getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool getSignature() const;
		void beSigned(Bureaucrat const &b);
		class GradeTooHighException : public std::exception {};
		class GradeTooLowException : public std::exception {};
		class AlreadySignedException : public std::exception {};
	private:
		std::string const name;
		int const signGrade;
		int const executeGrade;
		bool signature;
		Form();
		Form(Form const &f);
		Form &operator=(Form const &f);
};

std::ostream& operator<<(std::ostream& os, Form const &f);

#endif