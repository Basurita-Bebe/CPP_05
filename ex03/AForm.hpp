#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class   Bureaucrat;

class   AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _execGrade;

    protected:
        virtual void        executeAction() const = 0; 
        
    public:
        /* OCF */
        AForm();
        AForm(std::string name, int signGrade, int execGrade);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        /* GETTERS */
        std::string getName() const;
        bool        getIsSigned() const;
        int         getSignGrade() const;
        int         getExecGrade() const;

        /* MEMBER FUNCTIONS */
        void            beSigned(const Bureaucrat &bureaucrat);
        void            execute(const Bureaucrat &executor) const;

        /* EXCEPTIONS CLASSES */
        class   GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class   GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class   FormNotSignedException : public std::exception
        {
            public:
                const char *what() const throw();
        }; 
};

/* OVERLOAD << OPERATOR */
std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif