#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class   ShrubberyCreationForm : public AForm
{
    private:
        const std::string _target;

    protected:
        void executeAction() const;                         // the override

    public:
        // OCF
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();

        // Getters
        std::string getTarget() const;

        // EXCEPTIONS
        class   FileopenException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif