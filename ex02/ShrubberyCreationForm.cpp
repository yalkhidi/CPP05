#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
    _target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
    std::cout << "ShrubberyCreationForm Parameterized constructor called" << std::endl;
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy)
{
    std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
    _target = copy._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    std::cout << "ShrubberyCreationForm Copy Assignment Operator called" << std::endl;
    if (this != &copy)
    {
        AForm::operator=(copy);
        _target = copy._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (!this->getSign())
        throw AForm::FormNotSinedException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();
    std::ofstream shrubbery_file;
    std::string filename = _target + "_shrubbery";
    shrubbery_file.open(filename.c_str());
    if (!shrubbery_file.is_open())
        throw std::runtime_error("ShrubberyCreationForm: failed to open output file");    shrubbery_file << "    *" << std::endl;
    shrubbery_file << "   ***" << std::endl;
    shrubbery_file << "  *****" << std::endl;
    shrubbery_file << "   ***" << std::endl;
    shrubbery_file << "  *****" << std::endl;
    shrubbery_file << " *******" << std::endl;
    shrubbery_file << "   ***" << std::endl;
    shrubbery_file << "  *****" << std::endl;
    shrubbery_file << " *******" << std::endl;
    shrubbery_file << "*********" << std::endl;
    shrubbery_file << "   ||" << std::endl;

    shrubbery_file << std::endl << std::endl;
    
    shrubbery_file << "       _-_" << std::endl;
    shrubbery_file << "    /~~   ~~\\" << std::endl;
    shrubbery_file << " /~~         ~~\\" << std::endl;
    shrubbery_file << "{               }" << std::endl;
    shrubbery_file << " \\  _-     -_  /" << std::endl;
    shrubbery_file << "   ~  \\ //  ~" << std::endl;
    shrubbery_file << "_- -   | | _- _" << std::endl;
    shrubbery_file << "  _ -  | |   -_" << std::endl;
    shrubbery_file << "      // \\" << std::endl;
    shrubbery_file.close();


}
