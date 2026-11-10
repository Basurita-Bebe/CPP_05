#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

// Forward declaration: avoids circular include with Bureaucrat.hpp
class   Bureaucrat;

/*
**  Form - a document with a name, a signed status and two grade requirements.
**  Grades follow Bureaucrat's rules: 1 (highest) to 150 (lowest).
*/
class   Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _execGrade;
    public:
        /* OCF */
        Form();
        // Throws GradeTooHigh/LowException if grade is outside [1, 150].
        Form(std::string name, int signGrade, int execGrade);
        Form(const Form &other);
        // Copies only _isSigned: the other attributes are const.
        Form &operator=(const Form &other);
        ~Form();

        /* GETTERS */
        std::string getName() const;
        bool        getIsSigned() const;
        int         getSignGrade() const;
        int         getExecGrade() const;

        /* MEMBER FUNCTIONS */
        // Signes the form. Throws GradeTooLowException is bureaucrat's grade > _signGrade.
        void        beSigned(const Bureaucrat &bureaucrat);

        /* EXCEPTIONS CLASSES */
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        }; 
};

// Prints: "Form: <name> (signed: <bool>, sign grade: <n>, exec grade: <n>)"
std::ostream &operator<<(std::ostream &out, const Form &form);

#endif