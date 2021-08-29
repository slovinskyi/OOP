#include "Package.h"

Package::Package(string sender_n, string sender_addr, string sender_c, string 
	sender_s, string sender_Z, string recipient_n, string recipient_addr,string 
	recipient_c,string recipient_s, string recipient_Z, double wei, 
	double cost)
{	
	sender_name = sender_n;
	sender_address = sender_addr;
	sender_city = sender_c;
	sender_state = sender_s;
	sender_ZIP = sender_Z;
	
	recipient_name = recipient_n;
	recipient_address = recipient_addr;
	recipient_city = recipient_c;
	recipient_state = recipient_s;
	recipient_ZIP = recipient_Z;
		
	if(wei > 0.0 && cost > 0.0)
	{
		weight = wei;
		costperounce = cost;
	}
	else
	{
		weight = 0.0;
		costperounce = 0.0;
	}	
	
}
 
void Package::setsender_name(string sender_n)
{
	sender_name = sender_n;
}

string Package::getsender_name()
{
	return sender_name;
}
    
void Package::setsender_address(string sender_addr)
{
	sender_address = sender_addr;
}

string Package::getsender_address()
{
	return sender_address;
}
 
void Package::setsender_city(string sender_c)
{
	sender_city = sender_c;
}
 
string Package::getSendCity()
{
	return sender_city;
}
 
void Package::setsender_state(string sender_s)
{
	sender_state = sender_s;
}
string Package::getsender_state()
{
	return sender_state;
}
 
void Package::setsender_ZIP(string sender_Z)
{
	sender_ZIP = sender_Z;
}

string Package::getsender_ZIP()
{
	return sender_ZIP;
}
    
void Package::setrecipient_name(string recipient_n)
{
	recipient_name = recipient_n;
}

string Package::getrecipient_name()
{
	return recipient_name;
}
 
void Package::setrecipient_address(string recipient_addr)
{
	recipient_address = recipient_addr;
}

string Package::getrecipient_address()
{
	return recipient_address;
}
 
void Package::setrecipient_city(string recipient_c)
{
	recipient_city = recipient_c;
}

string Package::getrecipient_city()
{
	return recipient_city;
}
 
void Package::setrecipient_state(string recipient_s)
{
	recipient_state = recipient_s;
}

string Package::getrecipient_state()
{
	return recipient_state;
}
 
void Package::setrecipient_ZIP(string recipient_Z)
{
	recipient_ZIP = recipient_Z;
}

string Package::getrecipient_ZIP()
{
	return recipient_ZIP;
}
 
void Package::setweight(double w)
{
	 weight = (w < 0.0) ? 0.0 : w;
}
double Package::getweight()
{
	return weight;
}
 
void Package::setcostperounce(double cost)
{
	costperounce = ( cost < 0.0) ? 0.0 : cost;
}
 
double Package::getcostperounce()
{
	return costperounce;
}
 
double Package::calculateCost()
{
	double result;
	
	result = weight * costperounce;
	
	return result;
}
