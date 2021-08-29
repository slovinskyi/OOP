#include "OvernightPackage.h"

OvernightPackage::OvernightPackage(string sender_n, string sender_addr, 
	string sender_c, string sender_s, string sender_Z, string recipient_n, 
	string recipient_addr,string recipient_c,string recipient_s, 
	string recipient_Z, double wei, double cost, double delivery_fee)
	:Package(sender_n, sender_addr, sender_c, sender_s, sender_Z, recipient_n, 
	recipient_addr, recipient_c, recipient_s, recipient_Z,wei,cost)
{
	    setovernight_delivery_fee(delivery_fee);
}
 
double OvernightPackage::getovernight_delivery_fee()
{
	return overnight_delivery_fee;
}

void OvernightPackage::setovernight_delivery_fee(double delivery_fee)
{
	overnight_delivery_fee = delivery_fee;
}
 
double OvernightPackage::calculateCost()
{
	double result;
	result =  (getcostperounce() + overnight_delivery_fee) * getweight();
	return result;
}