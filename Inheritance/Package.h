#pragma once 

#include <string>

using namespace std;

class Package
{
private:
	string sender_name;
	string sender_address;
	string sender_city;
	string sender_state;
	string sender_ZIP;
	
	string recipient_name;
	string recipient_address;
	string recipient_city;
	string recipient_state;
	string recipient_ZIP;
	
	double weight;
	double costperounce;

public: 
	Package(string sender_n, string sender_addr, string sender_c, 
        string sender_s, string sender_Z, string recipient_n, 
        string recipient_addr, string recipient_c,string recipient_s, 
        string recipient_Z, double wei, double cost);
		
	void setsender_name(string sender_n);
    string getsender_name();
 
    void setsender_address(string sender_addr);
    string getsender_address();
 
    void setsender_city(string sender_c);
    string getSendCity();
 
    void setsender_state(string sender_s);
    string getsender_state();
 
    void setsender_ZIP(string sender_Z);
    string getsender_ZIP();
    
    void setrecipient_name(string recipient_n);
    string getrecipient_name();
 
    void setrecipient_address(string recipient_addr);
    string getrecipient_address();
 
    void setrecipient_city(string recipient_c);
    string getrecipient_city();
 
    void setrecipient_state(string recipient_s);
    string getrecipient_state();
 
    void setrecipient_ZIP(string recipient_Z);
    string getrecipient_ZIP();
 
    void setweight(double w);
    double getweight();
 
    void setcostperounce(double cost);
    double getcostperounce();
 
    double calculateCost();

    ~Package() = default;
};