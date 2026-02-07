#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>

int main()
{
    {
        srand(time(NULL));
        try
        {
            Bureaucrat bob("Bob", 44);
            AForm *rob = new RobotomyRequestForm("Robot");
            bob.signForm(*rob);
            bob.executeForm(*rob);
            delete rob;
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
            Bureaucrat bob("Bob", 44);
            AForm *shub = new ShrubberyCreationForm("Creation");
            bob.signForm(*shub);
            bob.executeForm(*shub);
            delete shub;
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
            Bureaucrat bob("Bob", 4);
            AForm *president = new PresidentialPardonForm("Presidential");
            bob.signForm(*president);
            bob.executeForm(*president);
            delete president;
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
            Bureaucrat bob("Bob", 150);
            AForm *rob = new RobotomyRequestForm("Robot");
            bob.signForm(*rob);
            bob.executeForm(*rob);
            delete rob;
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
            Bureaucrat bob("Bob", 70);
            AForm *shub = new ShrubberyCreationForm("Creation");
            bob.signForm(*shub);
            bob.executeForm(*shub);
            delete shub;
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
            Bureaucrat bob("Bob", 4);
            AForm *president = new PresidentialPardonForm("Presidential");
            bob.executeForm(*president);
            delete president;
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
            Bureaucrat bob("Bob", 170);
            AForm *president = new PresidentialPardonForm("Presidential");
            bob.signForm(*president);
            bob.executeForm(*president);
            delete president;
        }
        catch( std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "-------------------------------------------------" << std::endl;
}
