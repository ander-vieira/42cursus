#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b1("John", 1);
		b1.demote();
	} catch(Bureaucrat::GradeTooHighException &e) {
		std::cout << "EXCEPTION: Grade too high" << std::endl;
	} catch(Bureaucrat::GradeTooLowException &e) {
		std::cout << "EXCEPTION: Grade too low" << std::endl;
	}
}