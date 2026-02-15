#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(false), _signGrade(150), _executeGrade(150)
{
    std::cout << "AForm Default Constructer called" << std::endl;
}

AForm::AForm(const std::string name, const int signGrade, const int executeGrade) :
     _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    std::cout << "AForm Parameterized Constructer called" << std::endl;
    if (_signGrade < 1 || _executeGrade < 1)
        throw AForm::GradeTooHighException();
    if (_signGrade > 150 || _executeGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& copy) : 
    _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade)
{
    std::cout << "AForm Copy Constructer called" << std::endl;
}

AForm& AForm::operator=(const AForm& copy)
{
    std::cout << "AForm Copy Assignment Operator called" << std::endl;
    if (this != &copy)
    {
        _signed = copy._signed;
    }
    return (*this);
}

AForm::~AForm()
{
    std::cout << "AForm Destructer called" << std::endl;
}

const std::string& AForm::getName() const
{
    return (_name);
}

bool AForm::getSign() const
{
    return (_signed);
}

int AForm::getSignGrade() const
{
    return (_signGrade);
}

int AForm::getExecuteGrade() const
{
    return (_executeGrade);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= _signGrade)
        _signed = true;
    else
        throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char* AForm::FormNotSinedException ::what() const throw()
{
    return ("Form not signed");
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << "========== AForm info ==========" << std::endl;
    out << form.getName() << std::endl;
    out << form.getSign() << std::endl;
    out << form.getSignGrade() << std::endl;
    out << form.getExecuteGrade() << std::endl;
    return (out);
}