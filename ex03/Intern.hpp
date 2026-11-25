#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

/*
** Intern — no name, no grade. Creates forms by name using a lookup table
** (names[] + array of pointers to member functions) instead of an if/else chain.
*/
class   Intern
{
    private:
        /* CREATORS */
        // One per form. Called through an array of pointers to member functions.
        AForm *createShrubbery(std::string const &target) const;
        AForm *createRobotomy(std::string const &target) const;
        AForm *createPresidential(std::string const &target) const;

    public:
        /* OCF */
        // No attributes: nothing to initialize or copy.
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        /* MEMBER FUNCTIONS */
        // Returns a new form (caller must delete it), or prints an error and
        // returns NULL if formName is unknown.
        AForm *makeForm(std::string const &formName, std::string const &target) const;
};

#endif
