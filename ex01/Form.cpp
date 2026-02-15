#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _signed(false), _signGrade(150), _executeGrade(150)
{
    std::cout << "Form Default Constructer called" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int executeGrade) :
     _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    std::cout << "Form Parameterized Constructer called" << std::endl;
    if (_signGrade < 1 || _executeGrade < 1)
        throw Form::GradeTooHighException();
    if (_signGrade > 150 || _executeGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& copy) : 
    _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade)
{
    std::cout << "Form Copy Constructer called" << std::endl;
}

Form& Form::operator=(const Form& copy)
{
    std::cout << "Form Copy Assignment Operator called" << std::endl;
    if (this != &copy)
    {
        _signed = copy._signed;
    }
    return (*this);
}

Form::~Form()
{
    std::cout << "Form Destructer called" << std::endl;
}

const std::string& Form::getName() const
{
    return (_name);
}

bool Form::getSign() const
{
    return (_signed);
}

int Form::getSignGrade() const
{
    return (_signGrade);
}

int Form::getExecuteGrade() const
{
    return (_executeGrade);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= _signGrade)
        _signed = true;
    else
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form grade is too low");
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << "========== Form info ==========" << std::endl;
    out << form.getName() << std::endl;
    out << form.getSign() << std::endl;
    out << form.getSignGrade() << std::endl;
    out << form.getExecuteGrade() << std::endl;
    return (out);
}