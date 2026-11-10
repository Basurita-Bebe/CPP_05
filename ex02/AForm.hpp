#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

// Forward declaration: avoids circular include with Bureaucrat.hpp
class   Bureaucrat;

/*
**  AForm - abstract base for all forms (renamed from Form).
**  execute() checks signed + grade ONCE, then calls executeAction(),
**  which each concrete form implements (Templete Method pattern).
*/
class   AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _execGrade;

    protected:
        // Form-specific action. called only by execute(), after all checks pass.
        virtual void        executeAction() const = 0; 
        
    public:
        /* OCF */
        AForm();
        // Throws GradeTooHigh/LowException is grade is outside [1, 150].
        AForm(std::string name, int signGrade, int execGrade);
        AForm(const AForm &other);
        // Copies only _isSigned: the other attributes are const.
        AForm &operator=(const AForm &other);
        // Virtual: deleting through an AForm* also runs the child destructor.
        virtual ~AForm();

        /* GETTERS */
        std::string getName() const;
        bool        getIsSigned() const;
        int         getSignGrade() const;
        int         getExecGrade() const;

        /* MEMBER FUNCTIONS */
        // Signs the form. Throws GradeTooLowException if bureaucrat's grade > _signgrade.
        void            beSigned(const Bureaucrat &bureaucrat);
        // Throws FormNotSignedException or GradeTooLowException, else runs executeAction().
        void            execute(const Bureaucrat &executor) const;

        /* EXCEPTIONS */
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

// Prints: "Form: <name> (signed: <bool>, sign grade: <n>, exec grade: <n>)"
std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif