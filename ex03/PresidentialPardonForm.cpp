#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{
    std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
    _target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
    std::cout << "PresidentialPardonForm Parameterized constructor called" << std::endl;
    _target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy)
{
    std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
    _target = copy._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
    std::cout << "PresidentialPardonForm Copy Assignment Operator called" << std::endl;
    if (this != &copy)
    {
        AForm::operator=(copy);
        _target = copy._target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (!this->getSign())
        throw AForm::FormNotSinedException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();
    std::cout << "Hey " << _target << " you have been pardoned by Zaphod Beeblebrox" << std::endl;
}

AForm* PresidentialPardonForm::makePresidnetial(std::string target)
{
    return (new PresidentialPardonForm(target));
}
