#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class   Intern
{
    private:
        static AForm *createShrubbery(std::string const &target);
        static AForm *createRobotomy(std::string const &target);
        static AForm *createPresidential(std::string const &target);
    
    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(std::string const &formName, std::string const &target) const;

        class   FormNotFoundException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif