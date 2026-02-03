#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    {
        try
        {
            Bureaucrat bob("Bob", 44);
            Form tax("Tax Form", 45, 56);
            bob.signForm(tax);
            std::cout << tax ;
        }
        catch( std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "-------------------------------------------------" << std::endl;
    {
        try
        {
            Bureaucrat bob("Bob", 100);
            Form tax("Tax Form", 45, 56);
            bob.signForm(tax);
            std::cout << tax ;
        }
        catch( std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "-------------------------------------------------" << std::endl;
    {
        try
        {
            Bureaucrat bob("Bob", 100);
            Form tax("Tax Form", 170, 56);
            bob.signForm(tax);
            std::cout << tax ;
        }
        catch( std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "-------------------------------------------------" << std::endl;
}
