#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

/*
** PresidentialPardonForm — Concrete form: sign 25, exec 5.
*/
class   PresidentialPardonForm : public AForm
{
    private:
        const std::string _target;

    protected:
        // The override. Prints: "<target> has been pardoned by Zaphod Beeblebrox."
        void executeAction() const;

    public:
        /* OCF */
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();

        /* GETTERS */
        std::string getTarget() const;
};

#endif