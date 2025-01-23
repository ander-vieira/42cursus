#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int const grade) : name(name), grade(grade) {
	if(this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if(this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
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
		throw Bureaucrat::GradeTooHighException();
	this->grade -= 1;
	std::cout << "Bureaucrat: promoted " << *this << std::endl;
}

void Bureaucrat::demote() {
	if(this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade += 1;
	std::cout << "Bureaucrat: demoted " << *this << std::endl;
}

void Bureaucrat::signForm(AForm &f) const {
	try {
		f.beSigned(*this);
		std::cout << "Bureaucrat: " << *this << " signed " << f << std::endl;
	} catch(AForm::GradeTooLowException &e) {
		std::cout << "Bureaucrat: " << *this << " could not sign " << f << " because their grade is too low" << std::endl;
	} catch(AForm::AlreadySignedException &e) {
		std::cout << "Bureaucrat: " << *this << " could not sign " << f << " because it's already signed" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &f) const {
	try {
		f.execute(*this);
		std::cout << "Bureaucrat: " << *this << " executed " << f << std::endl;
	} catch(AForm::GradeTooLowException &e) {
		std::cout << "Bureaucrat: " << *this << " could not execute " << f << " because their grade is too low" << std::endl;
	} catch(AForm::UnsignedException &e) {
		std::cout << "Bureaucrat: " << *this << " could not execute " << f << " because it's not signed" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const &b) {
	os << b.getName()
	   << " (grade " << b.getGrade()
	   << ")";
	return os;
}