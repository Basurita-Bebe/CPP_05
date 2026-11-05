#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));            // Seed the random number generator for robotomy requests
	
	// PRESIDENTIAL TESTS
	std::cout << "*** * * * PRESIDENTIAL PARDON FORM TESTS * * * ***" << std::endl;
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	intern("Intern", 20);		// Can sign (25), can't execute (5)

	std::cout << std::endl << "*** * * * TEST 1: Execute unsigned form * * * ***" << std::endl;
	PresidentialPardonForm	p1("Arthur Dent");
	boss.executeForm(p1);					// form is not signed

	std::cout << std::endl << "*** * * * TEST 2: Signed, executor too low * * * ***" << std::endl;
	intern.signForm(p1);
	intern.executeForm(p1);					// grade too low

	std::cout << std::endl << "*** * * * TEST 3: Signed + good executor * * * ***" << std::endl;
	boss.executeForm(p1);					// pardoned!

	// ROBOTOMY TESTS
	std::cout << std::endl << "*** * * * ROBOTOMY REQUEST FORM TESTS * * * ***" << std::endl;
	Bureaucrat	robotMaster("Robot Master", 1);
	RobotomyRequestForm	r1("Bender");
	std::cout << std::endl << "*** * * * TEST 4: Signed + executed x7 (50%) * * * ***" << std::endl;
	robotMaster.signForm(r1);
	for(int i = 0; i < 7; i++)
		robotMaster.executeForm(r1);		// 50% chance of success / failure
	return 0;
}