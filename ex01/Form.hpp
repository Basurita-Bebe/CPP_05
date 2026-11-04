#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class   Bureaucrat;

class   Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _execGrade;
    public:
        // Canonic form
        Form();
        Form(std::string name, int signGrade, int execGrade);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        // Getters
        std::string getName() const;
        bool        getIsSigned() const;
        int         getSignGrade() const;
        int         getExecGrade() const;

        // Member functions
        void        beSigned(const Bureaucrat &bureaucrat);

        // Exceptions
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

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif