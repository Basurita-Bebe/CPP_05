#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "*** * * * TEST 1: valid Form * * * ***" << std::endl;
	try
	{
		Form f("Tax 28B", 50, 25);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "*** * * * TEST 2: invalid Form (signGrade 0) * * * ***" << std::endl;
	try
	{
		Form f("Bad High", 0, 25);
		std::cout << f << std::endl;						// never printed
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << "[FORM HIGH] " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << "[FORM LOW] " << e.what() << std::endl;
	}

	std::cout << std::endl << "*** * * * TEST 3: invalid Form (execGrade 151) * * * ***" << std::endl;
	try
	{
		Form f("Bad Low", 50, 151);
		std::cout << f << std::endl;						// never printed
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << "[FORM HIGH] " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << "[FORM LOW] " << e.what() << std::endl;
	}

	std::cout << std::endl << "*** * * * TEST 4: grade 10 signs Form(50) -> OK * * * ***" << std::endl;
	try
	{
		Bureaucrat	b("Charlie", 10);
		Form		f("Permit", 50, 25);
		std::cout << b << std::endl;
		std::cout << "Before: " << f << std::endl;
		b.signForm(f);
		std::cout << "After:  " << f << std::endl;			// signed
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "*** * * * TEST 5: grade 100 signs Form(50) -> FAIL * * * ***" << std::endl;
	try
	{
		Bureaucrat	b("Eve", 100);
		Form		f("Permit", 50, 25);
		std::cout << b << std::endl;
		std::cout << "Before: " << f << std::endl;
		b.signForm(f);										// no throw here: caught inside signForm
		std::cout << "After:  " << f << std::endl;			// still unsigned
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "*** * * * TEST 6: grade 50 signs Form(50) -> edge OK * * * ***" << std::endl;
	try
	{
		Bureaucrat	b("Frank", 50);
		Form		f("Permit", 50, 25);
		std::cout << b << std::endl;
		std::cout << "Before: " << f << std::endl;
		b.signForm(f);
		std::cout << "After:  " << f << std::endl;			// signed
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "*** * * * TEST 7: copy & assignment * * * ***" << std::endl;
	try
	{
		Bureaucrat	boss("Boss", 1);
		Form		a("Original form", 30, 20);
		boss.signForm(a);
		Form		b(a);									// copy constructor
		Form		c("Other form", 100, 100);
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c before: " << c << std::endl;
		c = a;												// operator= : only _isSigned copied
		std::cout << "c after:  " << c << std::endl;		// Other form (100, 100) signed: true
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}