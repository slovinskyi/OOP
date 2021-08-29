#include "TwoDayPackage.h"
#include "OvernightPackage.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
 
int main(int argc, char *argv[])
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

        else if(arg == "example")
        {
            OvernightPackage item1("Jan Kowalski", "Florianska 10", "Krakow", 
                "Malopolskie", "31-021", "Kamil Nowak", "Jerozolimskie 65", "Warszawa", "Mazowieckie", 
                "00-697", 15.00, 1.50, 1.10);
            TwoDayPackage item2("Karolina Wisniewska", "Piotrkowska 217", "Lodz", 
                "Lodzkie", "90-451", "Anna Wojcik", "Olawska 9", "Wroclaw", "Dolnoslaskie", 
                "50-529", 20.00, 1.05, 8.00);
 
            cout << fixed << setprecision(2);
            cout << "***************************************\n";
            cout << "Dostawa ekspresowa (Overnight Delivery)\n";
            cout << "Nadawca       " << item1.getsender_name() << "\n";
            cout << "              " << item1.getsender_address() << "\n";
            cout << "              " << item1.getsender_ZIP() << " " << 
                item1.getSendCity() << " " << item1.getsender_state() << "\n";
            cout << "\n";
            cout << "Adresat       " << item1.getrecipient_name()<< "\n";
            cout << "              " << item1.getrecipient_address() << "\n";
            cout << "              " << item1.getrecipient_ZIP()  << " " <<
                item1.getrecipient_city() << " " << item1.getrecipient_state() << "\n";
            cout << "Cena          PLN " <<item1.calculateCost() <<"\n";
            cout << "***************************************\n";

            cout << "\n\n";
            cout << "***************************************\n";
            cout << "Dostawa w ciagu 2 dni (Two Day Delivery)\n";
            cout << "Nadawca       " << item2.getsender_name()<< "\n";
            cout << "              " << item2.getsender_address() << "\n";
            cout << "              " << item2.getsender_ZIP() << " " << 
                item2.getSendCity() << " " << item2.getsender_state() << "\n";
            cout << "\n";
            cout << "Adresat       " << item2.getrecipient_name()<< "\n";
            cout << "              " << item2.getsender_address() << "\n";
            cout << "              " << item2.getrecipient_ZIP() << " " << 
                item2.getrecipient_city() << " " << item2.getrecipient_state() << "\n";
            cout << "Cena          PLN " <<item2.calculateCost()<<"\n";
	        cout << "***************************************\n";	

	        return 0;
        }
    }

    string s1, s2, s3, s4, s5;
    string r1, r2, r3, r4, r5;
    int n;

    ifstream file_1("sender.txt");
    getline(file_1, s1);
    getline(file_1, s2);
    getline(file_1, s3);
    getline(file_1, s4);
    getline(file_1, s5);

    ifstream file_2("recipient.txt");
    getline(file_2, r1);
    getline(file_2, r2);
    getline(file_2, r3);
    getline(file_2, r4);
    getline(file_2, r5);

    cout << "Prosze wybrac jedna z ponizszych opcji: \n" 
    << "1 = Dostawa ekspresowa (Overnight Delivery)\n" 
    << "2 = Dostawa w ciagu 2 dni (Two Day Delivery)\n";
    cout << "Dane osobowe zostana wczytane z plikow sender.txt oraz recipient.txt\n";
    cin >> n;

    if(n == 1)
    {
        double w = 15.00;
        cout << "Prosze podac mase przesylki (w uncjach): \n";
        cin >> w;
        OvernightPackage item1(s1, s2, s3, s4, s5, r1, r2, r3, r4, r5, w, 1.50, 1.10);

        cout << fixed << setprecision(2);
        cout << "\n***************************************\n";
        cout << "Dostawa ekspresowa (Overnight Delivery)\n";
        cout << "Nadawca       " << item1.getsender_name() << "\n";
        cout << "              " << item1.getsender_address() << "\n";
        cout << "              " << item1.getsender_ZIP() << " " << 
            item1.getSendCity() << " " << item1.getsender_state() << "\n";
        cout << "\n";
        cout << "Adresat       " << item1.getrecipient_name()<< "\n";
        cout << "              " << item1.getrecipient_address() << "\n";
        cout << "              " << item1.getrecipient_ZIP()  << " " <<
            item1.getrecipient_city() << " " << item1.getrecipient_state() << "\n";
        cout << "Cena          PLN " <<item1.calculateCost() <<"\n";
        cout << "***************************************\n";
        return 0;
    }

    else if(n == 2)
    {
        double w = 20.00;
        cout << "Prosze podac mase przesylki (w uncjach): \n";
        cin >> w;
        TwoDayPackage item2(s1, s2, s3, s4, s5, r1, r2, r3, r4, r5, w, 1.05, 8.00);
        cout << fixed << setprecision(2);
        cout << "\n***************************************\n";
        cout << "Dostawa w ciagu 2 dni (Two Day Delivery)\n";
        cout << "Nadawca       " << item2.getsender_name()<< "\n";
        cout << "              " << item2.getsender_address() << "\n";
        cout << "              " << item2.getsender_ZIP() << " " << 
            item2.getSendCity() << " " << item2.getsender_state() << "\n";
        cout << "\n";
        cout << "Adresat       " << item2.getrecipient_name()<< "\n";
        cout << "              " << item2.getrecipient_address() << "\n";
        cout << "              " << item2.getrecipient_ZIP() << " " << 
            item2.getrecipient_city() << " " << item2.getrecipient_state() << "\n";
        cout << "Cena          PLN " <<item2.calculateCost()<<"\n";
	    cout << "***************************************\n";	
	    return 0;
    }

    else 
    {
        cout << "Nie ma takiej opcji!" << endl;
        return 0;
    }
    return 0;
}