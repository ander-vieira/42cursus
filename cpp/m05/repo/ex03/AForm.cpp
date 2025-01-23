#include "AForm.hpp"

AForm::AForm(std::string const &name, int signGrade, int executeGrade) : name(name), signGrade(signGrade), executeGrade(executeGrade), signature(false) {
	if(this->signGrade < 1 || this->executeGrade < 1)
		throw AForm::GradeTooLowException();
	if(this->signGrade > 150 || this->executeGrade > 150)
		throw AForm::GradeTooHighException();
	std::cout << "Form: created " << *this << std::endl;
}

AForm::~AForm() {
	std::cout << "Form: shredded " << *this << std::endl;
}

std::string const &AForm::getName() const {
	return this->name;
}

int AForm::getSignGrade() const {
	return this->signGrade;
}

int AForm::getExecuteGrade() const {
	return this->executeGrade;
}

bool AForm::getSignature() const {
	return this->signature;
}

void AForm::beSigned(Bureaucrat const &b) {
	if (b.getGrade() > this->signGrade)
		throw AForm::GradeTooLowException();
	if (this->signature)
		throw AForm::AlreadySignedException();
	this->signature = true;
}

void AForm::execute(Bureaucrat const &b) const {
	if (b.getGrade() > this->executeGrade)
		throw AForm::GradeTooLowException();
	if (!this->signature)
		throw AForm::UnsignedException();
	this->doThing();
}

std::ostream& operator<<(std::ostream& os, AForm const &f) {
	os << f.getName()
	   << " (grade to sign " << f.getSignGrade()
	   << ", grade to execute " << f.getExecuteGrade()
	   << ", " << (f.getSignature() ? "signed" : "unsigned")
	   << ")";
	return os;
}