#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int const grade) : name(name), grade(grade) {
	if(this->grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if(this->grade > 150)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Bureaucrat: created " << *this << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat: killed " << *this << std::endl;
}

std::string const &Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::promote() {
	if(this->grade == 1)
		throw Bureaucrat::GradeTooLowException();
	this->grade -= 1;
	std::cout << "Bureaucrat: promoted " << *this << std::endl;
}

void Bureaucrat::demote() {
	if(this->grade == 150)
		throw Bureaucrat::GradeTooHighException();
	this->grade += 1;
	std::cout << "Bureaucrat: demoted " << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const &b) {
	os << b.getName() << " (grade " << b.getGrade() << ")";
	return os;
}