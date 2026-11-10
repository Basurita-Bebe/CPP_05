#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

/*
** Intern — no name, no grade. Creates forms by name using a lookup table
** (names[] + creators[]) instead of an if/else chain.
*/
class   Intern
{
    private:
        /* CREATORS */
        // One per form. Static: no Intern data needed -> plain function pointers.
        static AForm *createShrubbery(std::string const &target);
        static AForm *createRobotomy(std::string const &target);
        static AForm *createPresidential(std::string const &target);
    
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