#include <iostream>
#include <stdexcept>
#include "Array.hpp"
#include <vector>
#include <string>
#include <fstream>


using namespace std;

int main(int argc, char** argv)
{

    vector<string> cmdLineArgs(argv, argv + argc);

    for(auto& arg : cmdLineArgs)
    {
        if(arg == "--help" || arg == "-h")
        {
            ifstream file("help.txt");
 
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
        else if(arg == "double")
        {
            int i = 4, j = 8;
            cout << "Prosze wprowadzic rozmiary tablic: " << endl;
            cin >> i >> j;

            Array<double> tab_1(i);
            Array<double> tab_2(j);

            cout << "Rozmiar tablicy tab_1: " << tab_1.getSize() << "\nTablica po inicjalizacji:\n" << tab_1;
            cout << "\nRozmiar tablicy tab_2: " << tab_2.getSize() << "\nTablica po inicjalizacji:\n" << tab_2;
            cout << "\nProsze wprowadzic " << i + j << " liczby:" << endl;

            cin >> tab_1 >> tab_2;

            cout << "\nPo wprowadzeniu liczb:\n" << "tab_1:\n" << tab_1 << "tab_2:\n" << tab_2 ;
            cout << "\nSprawdzamy: tab_1 != tab_2" << endl;

            if (tab_1 != tab_2)
            cout << "tab_1 i tab_2 nie sa sobie rowne" << endl;
            else
            {
                cout << "tab_1 i tab_2 sa sobie rowne" << endl;
            }
            

            Array<double> tab_3(tab_1);

            cout << "\nRozmiar tablicy tab_3: " << tab_3.getSize() << "\nTablica po inicjalizacji:\n" << tab_3;
            cout << "\nPrzypisujemy tab_2 do tab_1:" << endl;
            tab_1 = tab_2;
            cout << "tab_1:\n" << tab_1 << "tab_2:\n" << tab_2;
            cout << "\nSprawdzamy: tab_1 == tab_2" << endl;

            if (tab_1 == tab_2)
            cout << "tab_1 i tab_2 sa sobie rowne" << endl;
            cout << "\ntab_1[" << j - 1 <<"] = " << tab_1[j - 1] ;
            cout << "\n\nPrzypisujemy 1000 do tab_1[" << j - 1 << "]" << endl;
            tab_1[j - 1] = 1000;
            cout << "tab_1:\n" << tab_1;
            cout << endl;
            try
            {
                cout << "\nProba przypisania 1000 do tab_1[15]" << endl;
                tab_1[15] = 1000;
            }
            catch (out_of_range &ex)
            {
                cout << "Wystapila sytuacji wyjatkowa: " << ex.what() << endl;
            }
            return 0;
        }

        else if(arg == "int")
        {
            int i = 4, j = 8;
            cout << "Prosze wprowadzic rozmiary tablic: " << endl;
            cin >> i >> j;

            Array<int> tab_1(i);
            Array<int> tab_2(j);

            cout << "Rozmiar tablicy tab_1: " << tab_1.getSize() << "\nTablica po inicjalizacji:\n" << tab_1;
            cout << "\nRozmiar tablicy tab_2: " << tab_2.getSize() << "\nTablica po inicjalizacji:\n" << tab_2;
            cout << "\nProsze wprowadzic " << i + j << " liczby:" << endl;

            cin >> tab_1 >> tab_2;

            cout << "\nPo wprowadzeniu liczb:\n" << "tab_1:\n" << tab_1 << "tab_2:\n" << tab_2 ;
            cout << "\nSprawdzamy: tab_1 != tab_2" << endl;

            if (tab_1 != tab_2)
            cout << "tab_1 i tab_2 nie sa sobie rowne" << endl;
            else
            {
                cout << "tab_1 i tab_2 sa sobie rowne" << endl;
            }
            

            Array<int> tab_3(tab_1);

            cout << "\nRozmiar tablicy tab_3: " << tab_3.getSize() << "\nTablica po inicjalizacji:\n" << tab_3;
            cout << "\nPrzypisujemy tab_2 do tab_1:" << endl;
            tab_1 = tab_2;
            cout << "tab_1:\n" << tab_1 << "tab_2:\n" << tab_2;
            cout << "\nSprawdzamy: tab_1 == tab_2" << endl;

            if (tab_1 == tab_2)
            cout << "tab_1 i tab_2 sa sobie rowne" << endl;
            cout << "\ntab_1[" << j - 1 <<"] = " << tab_1[j - 1] ;
            cout << "\n\nPrzypisujemy 1000 do tab_1[" << j - 1 << "]" << endl;
            tab_1[j - 1] = 1000;
            cout << "tab_1:\n" << tab_1;
            cout << endl;
            try
            {
                cout << "\nProba przypisania 1000 do tab_1[15]" << endl;
                tab_1[15] = 1000;
            }
            catch (out_of_range &ex)
            {
                cout << "Wystapila sytuacji wyjatkowa: " << ex.what() << endl;
            }
            return 0;
        }
    }

    int i = 4, j = 8;
    cout << "Prosze wprowadzic rozmiary tablic: " << endl;
    cin >> i >> j;

    Array<int> tab_1(i);
    Array<int> tab_2(j);

    cout << "Rozmiar tablicy tab_1: " << tab_1.getSize() << "\nTablica po inicjalizacji:\n" << tab_1;
    cout << "\nRozmiar tablicy tab_2: " << tab_2.getSize() << "\nTablica po inicjalizacji:\n" << tab_2;
    cout << "\nProsze wprowadzic " << i + j << " liczby:" << endl;

    cin >> tab_1 >> tab_2;

    cout << "\nPo wprowadzeniu liczb:\n" << "tab_1:\n" << tab_1 << "tab_2:\n" << tab_2 ;
    cout << "\nSprawdzamy: tab_1 != tab_2" << endl;

    if (tab_1 != tab_2)
    cout << "tab_1 i tab_2 nie sa sobie rowne" << endl;
    else
    {
        cout << "tab_1 i tab_2 sa sobie rowne" << endl;
    }
    

    Array<int> tab_3(tab_1);

    cout << "\nRozmiar tablicy tab_3: " << tab_3.getSize() << "\nTablica po inicjalizacji:\n" << tab_3;
    cout << "\nPrzypisujemy tab_2 do tab_1:" << endl;
    tab_1 = tab_2;
    cout << "tab_1:\n" << tab_1 << "tab_2:\n" << tab_2;
    cout << "\nSprawdzamy: tab_1 == tab_2" << endl;

    if (tab_1 == tab_2)
    cout << "tab_1 i tab_2 sa sobie rowne" << endl;
    cout << "\ntab_1[" << j - 1 <<"] = " << tab_1[j - 1] ;
    cout << "\n\nPrzypisujemy 1000 do tab_1[" << j - 1 << "]" << endl;
    tab_1[j - 1] = 1000;
    cout << "tab_1:\n" << tab_1;
    cout << endl;
    try
    {
        cout << "\nProba przypisania 1000 do tab_1[15]" << endl;
        tab_1[15] = 1000;
    }
    catch (out_of_range &ex)
    {
        cout << "Wystapila sytuacji wyjatkowa: " << ex.what() << endl;
    }
    return 0;
}