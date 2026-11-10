#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// OCF: nothing to copy, no attributes
Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }
Intern::~Intern() {}

// CREATORS
AForm *Intern::createShrubbery(std::string const &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(std::string const &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(std::string const &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) const
{
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(*creators[3])(std::string const &) = {createShrubbery, createRobotomy, createPresidential};

    for (int i = 0; i < 3; i++)
    {
        if (names[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }
    std::cerr << "Intern couldn't create \"" << formName << "\": unknown form." << std::endl;
    return NULL;
}

