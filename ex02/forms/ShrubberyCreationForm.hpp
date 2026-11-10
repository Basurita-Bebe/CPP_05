#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"


/*
** ShrubberyCreationForm — Concrete form: sign 145, exec 137.
*/
class   ShrubberyCreationForm : public AForm
{
    private:
        const std::string _target;

    protected:
        // Creates "<target>_shrubbery" and writes ASCII trees in it.
        // Throws FileOpenException if the file can't be created.
        void executeAction() const;   

    public:
        /* OCF */
        ShrubberyCreationForm();
        // Passes name + grade to AForm; only target is chose by the caller.
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        // Calls AForm::operator= (copies _isSigned), _target is const.
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();

        /* GETTERS */
        std::string getTarget() const;

        /* EXCEPTION CLASS*/
        // Thrown by executeAction() when the output file can't be opened
        // (e.g. missing directory, no write permission). Caught in executeForm().
        class   FileOpenException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif