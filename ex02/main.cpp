#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	intern("Intern", 20);		// can sign (25), can't execute (5)

	std::cout << "*** * * * TEST 1: Execute unsigned form * * * ***" << std::endl;
	PresidentialPardonForm	p1("Arthur Dent");
	boss.executeForm(p1);					// form is not signed

	std::cout << std::endl << "*** * * * TEST 2: Signed, executor too low * * * ***" << std::endl;
	intern.signForm(p1);
	intern.executeForm(p1);					// grade too low

	std::cout << std::endl << "*** * * * TEST 3: Signed + good executor * * * ***" << std::endl;
	boss.executeForm(p1);					// pardoned!

	return 0;
}