#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>

class Bureaucrat {
	public:
		Bureaucrat(std::string const &name, int grade);
		~Bureaucrat();
		std::string const &getName() const;
		int getGrade() const;
		void promote();
		void demote();
		class GradeTooHighException : public std::exception {};
		class GradeTooLowException : public std::exception {};
	private:
		std::string const name;
		int grade;
		Bureaucrat();
		Bureaucrat(Bureaucrat const &b);
		Bureaucrat &operator=(Bureaucrat const &b);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const &b);

#endif