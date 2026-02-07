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
        srand(time(NULL));
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
}
