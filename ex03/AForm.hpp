#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _executeGrade;
    public:
        AForm();
        AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        virtual ~AForm();
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
        class FormNotSinedException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        virtual void execute(Bureaucrat const& executor) const = 0;
};
std::ostream& operator<<(std::ostream& out, const AForm& form);
#endif