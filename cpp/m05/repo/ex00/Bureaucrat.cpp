#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, t_grade const grade) : name(name), grade(grade) {
	if(this->grade < MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	if(this->grade > MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Bureaucrat: created " << *this << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat: killed " << *this << std::endl;
}

std::string const &Bureaucrat::getName() const {
	return this->name;
}

t_grade Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::promote() {
	if(this->grade == MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->grade -= 1;
	std::cout << "Bureaucrat: promoted " << *this << std::endl;
}

void Bureaucrat::demote() {
	if(this->grade == MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->grade += 1;
	std::cout << "Bureaucrat: demoted " << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const &b) {
	os << b.getName() << " (grade " << b.getGrade() << ")";
	return os;
}