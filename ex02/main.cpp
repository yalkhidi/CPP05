#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    {
        try
        {
            Bureaucrat bob("Bob", 44);
            AForm *shub = new ShrubberyCreationForm("bob");
            bob.signForm(*shub);
            bob.executeForm(*shub);
        }
        catch( std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "-------------------------------------------------" << std::endl;
}
