#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm()
{
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
    _target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
    std::cout << "RobotomyRequestForm Parameterized constructor called" << std::endl;
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy)
{
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
    _target = copy._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
    std::cout << "RobotomyRequestForm Copy Assignment Operator called" << std::endl;
    if (this != &copy)
    {
        AForm::operator=(copy);
        _target = copy._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (this->getSign())
        throw AForm::FormNotSinedException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();
    std::cout << "Hey " << _target << " you been robotomized successfully 50% of the time" << std::endl;
}
