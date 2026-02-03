#include "Bureaucrat.hpp"

int main()
{
    {
        try
        {
            Bureaucrat yumna("Yumna", 150);
            std::cout << yumna << std::endl;
            Bureaucrat bureaucrat("Yumna", 1);
            std::cout << bureaucrat << std::endl;
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
            const Bureaucrat bureau("Yumna", 45);
            std::cout << bureau << std::endl;
            Bureaucrat b2("Bob", -1);
        }
        catch(std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "-------------------------------------------------" << std::endl;
    {
        try
        {
            Bureaucrat b2("Bob", 160);
        }
        catch(std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "-------------------------------------------------" << std::endl;
    {
        try
        {
            Bureaucrat bob("Bob", 100);
            std::cout << bob << std::endl;
            Bureaucrat jane(bob);
            jane.incrementGrade();
            std::cout << jane << std::endl;
            for (int i = 0; i < 50; i++)
                bob.decrementGrade();
        }
        catch(std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "-------------------------------------------------" << std::endl;
    {
        try
        {
            Bureaucrat james("James", 34);
            std::cout << james << std::endl;
            Bureaucrat lisa;
            lisa = james;
            for (int i = 0; i < 10; i++)
                lisa.incrementGrade();
            std::cout << lisa << std::endl;
        }
        catch(std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
