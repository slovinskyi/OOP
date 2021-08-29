#include "Polynomial.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
    std::vector<std::string> cmdLineArgs(argv, argv + argc);

    for(auto& arg : cmdLineArgs)
    {
        if(arg == "--help" || arg == "-h")
        {
            std::ifstream file("help.txt");
 
            if(file)
            {
                std::string line;  
                while (getline(file, line))
                {
                    std::cout << line << std::endl;
                }
            }
            else
            {
                std::cout << "ERROR: nie można otworzyć pliku do odczytu." << std::endl;
            }
            return 0;
        }
    }

    Polynomial a, b, c, w;
    a.enterTerms();
    b.enterTerms();
    w = a;
    std::cout << std::endl;
    std::cout << "Pierwszy wielomian            ";
    a.printPolynomial();
    std::cout << "Drugi wielomian               ";
    b.printPolynomial();
    std::cout << std::endl;

    std::cout << "Suma wielomianow              ";
    c = a + b;
    c.printPolynomial();

    std::cout << "Przypisanie sumy (+=)         ";
    a += b;
    a.printPolynomial();
    std::cout << std::endl;

    std::cout << "Roznica wielomianow           ";
    a = w; 
    c = a - b;
    c.printPolynomial();

    std::cout << "Przypisanie roznicy (-=)      ";
    a -= b;
    a.printPolynomial();
    std::cout << std::endl;

    std::cout << "Iloczyn wielomianow           ";
    a = w;
    c = a * b;
    c.printPolynomial();

    std::cout << "Przypisanie iloczynu (*=)     ";
    a *= b;
    a.printPolynomial();
    std::cout << std::endl;

    return 0;
}