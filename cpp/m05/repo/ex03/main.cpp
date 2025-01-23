#include "AForm.hpp"
#include "Intern.hpp"

int main() {
	std::cout << "----- INIT -----" << std::endl;

	Bureaucrat b("John", 1);
	Intern intern;
	AForm *f;

	std::cout << "----- PPF -----" << std::endl;

	f = intern.makeForm("PPF", "42");
	b.signForm(*f);
	b.executeForm(*f);
	delete f;

	std::cout << "----- RRF -----" << std::endl;

	f = intern.makeForm("RRF", "42");
	b.signForm(*f);
	b.executeForm(*f);
	delete f;

	std::cout << "----- SCF -----" << std::endl;

	f = intern.makeForm("SCF", "42");
	b.signForm(*f);
	b.executeForm(*f);
	delete f;

	std::cout << "----- WWF -----" << std::endl;

	f = intern.makeForm("WWF", "42");
	if (f == NULL)
		std::cout << "Main: fired the intern" << std::endl;
}