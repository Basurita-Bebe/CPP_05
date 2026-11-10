#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));            // Seed the random number generator for robotomy requests
	
	Intern		someRandomIntern;
	Bureaucrat	boss("Boss", 1);

	std::string	names[4] = {"shrubbery creation", "robotomy request", "presidential pardon", "cofee request"};
	std::string	targets[4] = {"home", "Bender", "Arthur Dent", "Boss"};

	for (int i = 0; i < 4; i++)
	{
		std::cout << std::endl << "*** * * * TEST " << i + 1 << ": \"" << names[i] << "\" * * * ***" << std::endl;
		
		AForm	*form = someRandomIntern.makeForm(names[i], targets[i]);
		if (form)							// NULL check: unknown name -> skip
		{
			std::cout << *form << std::endl;
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;					// main owns it
		}
	}

	return 0;
}