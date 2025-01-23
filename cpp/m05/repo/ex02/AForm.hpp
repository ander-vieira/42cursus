#ifndef A_FORM_H
# define A_FORM_H

# include <iostream>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm(std::string const &name, int signGrade, int executeGrade);
		~AForm();
		std::string const &getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		bool getSignature() const;
		void beSigned(Bureaucrat const &b);
		void execute(Bureaucrat const &b) const;
		class GradeTooHighException : public std::exception {};
		class GradeTooLowException : public std::exception {};
		class AlreadySignedException : public std::exception {};
		class UnsignedException : public std::exception {};
	protected:
		virtual void doThing() const = 0;
	private:
		std::string const name;
		int const signGrade;
		int const executeGrade;
		bool signature;
		AForm();
		AForm(AForm const &f);
		AForm &operator=(AForm const &f);
};

std::ostream& operator<<(std::ostream& os, AForm const &f);

#endif