#pragma once 

#include "Package.h"

class TwoDayPackage : public Package
{
private:
	double two_day_delivery_fee;

public:
	TwoDayPackage(string sender_n, string sender_addr, string 
		sender_c, string sender_s, string sender_Z, string recipient_n, 
		string recipient_addr,string recipient_c,string recipient_s, 
		string recipient_Z,double wei, double cost, double delivery_fee);
		
	double gettwo_day_delivery_fee();
	void settwo_day_delivery_fee(double delivery_fee);
	double calculateCost();

	~TwoDayPackage() = default;
};