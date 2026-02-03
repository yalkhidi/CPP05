#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _executeGrade;
    public:
        Form();
        Form(const std::string name, const int gradeToSign, const int gradeToExecute);
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        ~Form();
        const std::string& getName() const;
        bool getSign() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        void beSigned(const Bureaucrat& bureaucrat);
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};
std::ostream& operator<<(std::ostream& out, const Form& form);
#endif