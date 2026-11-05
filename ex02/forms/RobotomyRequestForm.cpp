#include "RobotomyRequestForm.hpp"
#include <cstdlib>                              // for rand()

// OCF
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// MEMBER FUNCTIONS
void RobotomyRequestForm::executeAction() const
{
    std::cout << "Brrrrrrr... drilling noises..." << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully!" << std::endl << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "." << std::endl << std::endl;
}

// GETTERS
std::string RobotomyRequestForm::getTarget() const
{
    return _target;
}