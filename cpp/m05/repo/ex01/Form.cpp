#include "Form.hpp"

Form::Form(std::string const &name, int signGrade, int executeGrade) : name(name), signGrade(signGrade), executeGrade(executeGrade), signature(false) {
	if(this->signGrade < 1 || this->executeGrade < 1)
		throw Form::GradeTooLowException();
	if(this->signGrade > 150 || this->executeGrade > 150)
		throw Form::GradeTooHighException();
	std::cout << "Form: created " << *this << std::endl;
}

Form::~Form() {
	std::cout << "Form: shredded " << *this << std::endl;
}

std::string const &Form::getName() const {
	return this->name;
}

int Form::getSignGrade() const {
	return this->signGrade;
}

int Form::getExecuteGrade() const {
	return this->executeGrade;
}

bool Form::getSignature() const {
	return this->signature;
}

void Form::beSigned(Bureaucrat const &b) {
	if (b.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	if (this->signature)
		throw Form::AlreadySignedException();
	this->signature = true;
}

std::ostream& operator<<(std::ostream& os, Form const &f) {
	os << f.getName()
	   << " (grade to sign " << f.getSignGrade()
	   << ", grade to execute " << f.getExecuteGrade()
	   << ", " << (f.getSignature() ? "signed" : "unsigned")
	   << ")";
	return os;
}