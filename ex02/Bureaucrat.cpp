#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* OCF */
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

/* GETTERS */
std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

/* MEMBER FUNCTIONS */
void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << _name << " couldn't sign "
                  << form.getName() << " because " << e.what()
                  << "." <<std::endl;
    }
}

//                        1. Won't modify the form.
//                            |
//                            |             2. Won't modify the Bureaucrat (*this).
//                            |                  |
//                            v                  v
void Bureaucrat::executeForm(const AForm &form) const
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << _name << " couldn't execute "
                  << form.getName() << " because " << e.what()
                  << "." <<std::endl;
    }
}

/* EXCEPTIONS CLASSES */
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}

/* OVERLOAD << OPERATOR */
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}
