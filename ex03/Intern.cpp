#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()
{
    std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern& copy)
{
    (void)copy;
    std::cout << "Intern Copy Constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& copy)
{
    (void)copy;
    std::cout << "Intern Copy Assignment Operator called" << std::endl;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern Destructor called" << std::endl;
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    std::string formTypes[3] = 
    {
        "shrubbery creation",
        "presidential pardon",
        "robotomy request"
    };
    AForm*(*Forms[3])(std::string) = 
    {
        ShrubberyCreationForm::makeShrubbery,
        PresidentialPardonForm::makePresidnetial,
        RobotomyRequestForm::makeRobotomy
    };
    for (int i = 0; i < 3; i++)
    {
        if (formName == formTypes[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (Forms[i](target));
        }
    }
    throw (Intern::formNotFound());
}

const char* Intern::formNotFound::what() const throw()
{
    return("Cannot find this form");
}