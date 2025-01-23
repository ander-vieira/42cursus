#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>

typedef unsigned int t_grade;

# define MIN_GRADE 1
# define MAX_GRADE 150

class Bureaucrat {
	public:
		Bureaucrat(std::string const &name, t_grade grade);
		~Bureaucrat();
		std::string const &getName() const;
		t_grade getGrade() const;
		void promote();
		void demote();
		class GradeTooHighException : public std::exception {};
		class GradeTooLowException : public std::exception {};
	private:
		std::string const name;
		t_grade grade;
		Bureaucrat();
		Bureaucrat(Bureaucrat const &b);
		Bureaucrat &operator=(Bureaucrat const &b);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const &b);

#endif