#include "Form.hpp"
#include "Bureaucrat.hpp"

/* OCF */
Form::Form() : _name("Default"), _isSigned(false), _signGrade(1), _execGrade(1) {}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {}

/* GETTERS */
std::string Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

int Form::getSignGrade() const
{
    return _signGrade;
}

int Form::getExecGrade() const
{
    return _execGrade;
}

/* MEMBER FUNCTIONS */
void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

/* EXCEPTIONS CLASSES - WHAT */
const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

/* OVERLOAD << OPERATOR */
std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form: " << form.getName()
        << " (signed: " << (form.getIsSigned() ? "true" : "false")
        << ", sign grade: " << form.getSignGrade()
        << ", exec grade: " << form.getExecGrade() << ")";
    return out;
}