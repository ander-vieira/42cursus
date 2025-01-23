#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b("John", 2);
		Form f("10T", 1, 3);

		b.signForm(f);
		b.promote();
		b.signForm(f);
		b.signForm(f);
	} catch(Bureaucrat::GradeTooHighException &e) {
		std::cout << "EXCEPTION: Bureaucrat: Grade too high" << std::endl;
	} catch(Bureaucrat::GradeTooLowException &e) {
		std::cout << "EXCEPTION: Bureaucrat: Grade too low" << std::endl;
	} catch(Form::GradeTooHighException &e) {
		std::cout << "EXCEPTION: Form: Grade too high" << std::endl;
	} catch(Form::GradeTooLowException &e) {
		std::cout << "EXCEPTION: Form: Grade too low" << std::endl;
	} catch(Form::AlreadySignedException &e) {
		std::cout << "EXCEPTION: Form: Already signed" << std::endl;
	}
}