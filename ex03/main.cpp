#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <cstdlib>

int main()
{
    {
        try
        {
            Bureaucrat bureaucrat("Bob", 44);
            Intern intern;
            AForm* rob = intern.makeForm("shrubbery creation", "Tax");
            rob->beSigned(bureaucrat);
            rob->execute(bureaucrat);
            delete(rob);
        }
        catch( std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "-------------------------------------------------" << std::endl;
    {
        srand(time(NULL));
        try
        {
            Bureaucrat bureaucrat("Bob", 44);
            Intern intern;
            AForm* rob = intern.makeForm("robotomy request", "Tax");
            rob->beSigned(bureaucrat);
            rob->execute(bureaucrat);
            delete(rob);
        }
        catch( std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "-------------------------------------------------" << std::endl;
    {
        AForm* rob = NULL;
        try
        {
            Bureaucrat bureaucrat("Bob", 44);
            Intern intern;
            rob = intern.makeForm("presidential pardon", "Tax");
            rob->beSigned(bureaucrat);
            rob->execute(bureaucrat);
            delete (rob);
        }
        catch( std::exception& e)
        {
            delete (rob);
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "-------------------------------------------------" << std::endl;
    {
        try
        {
            Bureaucrat bureaucrat("Bob", 44);
            Intern intern;
            AForm* rob = intern.makeForm("custom form", "Tax");
            rob->beSigned(bureaucrat);
            rob->execute(bureaucrat);
            delete(rob);
        }
        catch( std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "-------------------------------------------------" << std::endl;
}
