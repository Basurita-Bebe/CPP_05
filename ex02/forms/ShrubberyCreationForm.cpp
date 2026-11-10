#include "ShrubberyCreationForm.hpp"
#include <fstream>                              // for std::ofstream

/* OCF */
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* MEMEBER FUNCTION */
void ShrubberyCreationForm::executeAction() const
{
    std::string     filename = _target + "_shrubbery";
    std::ofstream   ofile(filename.c_str());
    if (!ofile)
        throw FileOpenException();
    ofile << "       _-_" << std::endl;
    ofile << "    /~~   ~~\\" << std::endl;
    ofile << " /~~         ~~\\" << std::endl;
    ofile << "{               }" << std::endl;
    ofile << " \\  _-     -_  /" << std::endl;
    ofile << "   ~  \\\\ //  ~" << std::endl;
    ofile << "_- -   | | _- _" << std::endl;
    ofile << "  _ -  | |   -_" << std::endl;
    ofile << "      // \\\\" << std::endl;
}

/* GETTERS */
std::string ShrubberyCreationForm::getTarget() const
{
    return _target;
}

/* EXCEPTION CLASS */
const char *ShrubberyCreationForm::FileOpenException::what() const throw()
{
    return "could not open the shrubbery file";
}