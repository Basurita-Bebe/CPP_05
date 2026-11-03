/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <bbeceiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 11:20:15 by bbeceiro          #+#    #+#             */
/*   Updated: 2026/11/03 12:09:54 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "*** * * * TEST 1: valid construction * * * ***" << std::endl;
	try
	{
		Bureaucrat b("Bob", 42);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "*** * * * TEST 2: grade too high (0) * * * ***" << std::endl;
	try
	{
		Bureaucrat b("Alice", 0);
		std::cout << b << std::endl;	                                            // never printed
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "[HIGH] " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "[LOW] " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "[OTHER] " << e.what() << std::endl;
	}

	std::cout << std::endl << "*** * * * TEST 3: grade too low (151) * * * ***" << std::endl;
	try
	{
		Bureaucrat b("Charlie", 151);
		std::cout << b << std::endl;	                                          // never printed
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "[HIGH] " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "[LOW] " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "[OTHER] " << e.what() << std::endl;
	}

	std::cout << std::endl << "*** * * * TEST 4: increment 3 -> 2 -> 1 -> boom * * * ***" << std::endl;
	{
		Bureaucrat b("Dave", 3);	                                           // declared OUTSIDE try: still alive after catch
		try
		{
			std::cout << b << std::endl;
			b.incrementGrade();
			std::cout << b << std::endl;
			b.incrementGrade();
			std::cout << b << std::endl;
			b.incrementGrade();                                               // throws
			std::cout << "never printed" << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << "[HIGH] " << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << "[LOW] " << e.what() << std::endl;
		}
		std::cout << "After exception: " << b << std::endl;                   // still 1
	}

	std::cout << std::endl << "*** * * * TEST 5: decrement 149 -> 150 -> boom * * * ***" << std::endl;
	{
		Bureaucrat b("Eve", 149);
		try
		{
			std::cout << b << std::endl;
			b.decrementGrade();
			std::cout << b << std::endl;
			b.decrementGrade();                                              // throws
			std::cout << "never printed" << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << "[HIGH] " << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << "[LOW] " << e.what() << std::endl;
		}
		std::cout << "After exception: " << b << std::endl;                  // still 150
	}

	std::cout << std::endl << "*** * * * TEST 6: copy constructor & assignment * * * ***" << std::endl;
	try
	{
		Bureaucrat a("Frank", 10);
		Bureaucrat b(a);                                                    // copy ctor
		Bureaucrat c("Grace", 100);
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c before: " << c << std::endl;
		c = a;                                                              // operator=
		std::cout << "c after:  " << c << std::endl;	                    // Grace keeps her name, grade 10
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}