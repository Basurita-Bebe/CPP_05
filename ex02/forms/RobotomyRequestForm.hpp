#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class   RobotomyRequestForm : public AForm
{
    private:
        const std::string _target;

    protected:
        void executeAction() const;                         // the override

    public:
        // OCF
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();

        // Getters
        std::string getTarget() const;
};

#endif