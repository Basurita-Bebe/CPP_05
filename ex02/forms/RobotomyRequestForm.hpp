#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

/*
** RobotomyRequestForm — Concrete form: sign 72, exec 45.
*/
class   RobotomyRequestForm : public AForm
{
    private:
        const std::string _target;

    protected:
        // Drilling noises, then 50% success / 50% failure.
        // Requires std::srand() called ONCE in main.
        void executeAction() const;

    public:
        /* OCF */
        RobotomyRequestForm();
        // Passes name + grades to AForm; only the target is chose by the caller.
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        // Calls AForm::operator= (copies _isSigned), _target is const.
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();

        /* GETTERS */
        std::string getTarget() const;
};

#endif