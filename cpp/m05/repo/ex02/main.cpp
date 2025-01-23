#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	try {
		std::cout << "----- INIT -----" << std::endl;

		Bureaucrat b("John", 2);
		ShrubberyCreationForm scf("Mom");
		RobotomyRequestForm rrf("Dad");
		PresidentialPardonForm ppf("42");

		std::cout << "----- SCF -----" << std::endl;

		b.executeForm(scf);
		b.signForm(scf);
		b.executeForm(scf);

		std::cout << "----- RRF -----" << std::endl;

		b.executeForm(rrf);
		b.signForm(rrf);
		b.executeForm(rrf);

		std::cout << "----- PPF -----" << std::endl;

		b.executeForm(ppf);
		b.signForm(ppf);
		b.executeForm(ppf);
	} catch(Bureaucrat::GradeTooHighException &e) {
		std::cout << "EXCEPTION: Bureaucrat: Grade too high" << std::endl;
	} catch(Bureaucrat::GradeTooLowException &e) {
		std::cout << "EXCEPTION: Bureaucrat: Grade too low" << std::endl;
	} catch(AForm::GradeTooHighException &e) {
		std::cout << "EXCEPTION: Form: Grade too high" << std::endl;
	} catch(AForm::GradeTooLowException &e) {
		std::cout << "EXCEPTION: Form: Grade too low" << std::endl;
	} catch(AForm::AlreadySignedException &e) {
		std::cout << "EXCEPTION: Form: Already signed" << std::endl;
	}
}