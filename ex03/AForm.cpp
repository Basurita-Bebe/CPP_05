#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* OCF */
AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(1), _execGrade(1) {}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

/* GETTERS */
std::string AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getSignGrade() const
{
    return _signGrade;
}

int AForm::getExecGrade() const
{
    return _execGrade;
}

/* MEMBER FUNCTIONS */
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

void    AForm::execute(const Bureaucrat &executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _execGrade)
        throw GradeTooLowException();
    executeAction();
}

/* EXCEPTION CLASSES */
const char *AForm::GradeTooHighException::what() const throw()
{
    return "form grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "form grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "form is not signed";
}

/* OVERLOAD << OPERATOR */
std::ostream &operator<<(std::ostream &out, const AForm &Aform)
{
    out << "AForm: " << Aform.getName()
        << " (signed: " << (Aform.getIsSigned() ? "true" : "false")
        << ", sign grade: " << Aform.getSignGrade()
        << ", exec grade: " << Aform.getExecGrade() << ")";
    return out;
}