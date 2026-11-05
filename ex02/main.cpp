#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
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

	// SHRUBBERY TESTS
	std::cout << std::endl << "*** * * * SHRUBBERY CREATION FORM TESTS * * * ***" << std::endl;
	Bureaucrat	gardener("Gardener", 140);	// Can sign (145), can't execute (137)
	Bureaucrat	rookie("Rookie", 150);		// Can't even sign

	std::cout << std::endl << "*** * * * TEST 5: Grade too low to sign * * * ***" << std::endl;
	ShrubberyCreationForm	s1("home");
	rookie.signForm(s1);					// 150 > 145 → couldn't sign

	std::cout << std::endl << "*** * * * TEST 6: Signed, executor too low * * * ***" << std::endl;
	gardener.signForm(s1);					// 140 <= 145 → signed
	gardener.executeForm(s1);				// 140 > 137 → couldn't execute

	std::cout << std::endl << "*** * * * TEST 7: Signed + good executor * * * ***" << std::endl;
	boss.executeForm(s1);					// creates "home_shrubbery" 🌳

	std::cout << std::endl << "*** * * * TEST 8: File can't be opened * * * ***" << std::endl;
	ShrubberyCreationForm	s2("no_such_dir/garden");	// folder doesn't exist → open fails
	boss.signForm(s2);
	boss.executeForm(s2);					// FileOpenException

	return 0;
}