#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>
#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& copy);
        Intern& operator=(const Intern& copy);
        ~Intern();
        AForm* makeForm(std::string formName, std::string target);
        class formNotFound : public std::exception
        {
            public:
                const char* what() const throw();
        };
};
#endif