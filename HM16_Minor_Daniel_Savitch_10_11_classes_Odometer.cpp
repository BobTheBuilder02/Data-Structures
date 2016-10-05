/*Define a class called Odometer that will be used to track fuel and mileage for an 
automotive vehicle.  Include private member variables to track the miles driven and the 
fuel efficiency of the vehicle in miles per gallon.  The class should have a constructor that 
initializes these values to zero.  Include a member function to reset the odometer to zero 
miles, a member function to set the fuel efficiency, a member function that accepts miles 
driven for a trip and adds it to the odometer’s total, and a member function that returns 
the number of gallons of gasoline that the vehicle has consumed since the odometer was 
last reset.*/

/*Names: Daniel Minor
Date:2/17/2016
Homework # 16
Problem # (Savitch problem 10-11)
The source code in this program is my own work and not the work of anyone else. */
//Your signature:                            
//
#include<iostream>
using namespace std;
class Odometer {
	
public:
	Odometer(double num_miles, double fuel_efficiency); //constructor that itializes miles driven and fuel efficiency to zero.
	Odometer() {}
	void reset();
	void setFuelEfficiency(double fuel_efficiency);
	void logMiles(double num_miles);
	double gasConsumed();
private:
	double num_miles;
	double fuel_efficency;
};



int main()
{
	// Two test trips
	Odometer trip1;
	Odometer trip2;
	/*
	void setFuelEfficiency(double newEfficiency);
	void reset();
	void logMiles(int additionalMiles);
	double gasConsumed();
	*/
	trip1.reset();
	trip1.setFuelEfficiency(45);
	trip1.logMiles(100);
	cout << "For your fuel-efficient small car:" << endl;
	cout << "After 100 miles, " << trip1.gasConsumed() << " gallons used." << endl;
	trip1.logMiles(50);
	cout << "After another 50 miles, " << trip1.gasConsumed() <<" gallons used." << endl;
	cout << endl;

	trip2.reset();
	trip2.setFuelEfficiency(13);
	trip2.logMiles(100);
	cout << "For your gas guzzler:" << endl;
	cout << "After 100 miles, " << trip2.gasConsumed() << " gallons used." << endl;
	trip2.logMiles(50);
	cout << "After another 50 miles, " << trip2.gasConsumed() << " gallons used." << endl << endl;
	
	trip1.reset();
	double fuel_efficiency = 0;
	cout << " Enter the fuel efficiency of the vehicle " << endl;
	cin >> fuel_efficiency;
	trip1.setFuelEfficiency(fuel_efficiency);
	int num_miles = 0;
	cout << "Now enter the number of miles you will travel initially. " << endl;
	cin >> num_miles;
	trip1.logMiles(num_miles);
	cout << "For your car:" << endl;
	cout << "After 100 miles, " << trip1.gasConsumed() << " gallons used." << endl;
	cout << "Now enter the additional number of miles you will travel. " << endl;
	cin >> num_miles;
	trip1.logMiles(num_miles);
	cout << "After another " << num_miles << " miles, " << trip1.gasConsumed() << " gallons consumed." << endl;
	cout << endl;
	char dummy;
	cout << "Enter any key to quit" << endl;
	cin >> dummy;
	return 0;
}

Odometer::Odometer(double miles, double fuelefficiency)
{
	while((miles < 0) || (fuelefficiency < 0))
	{
		cout << "Illegal values entered. values must be greater than or equal to zero" << endl;
		cout << "Program ending" << endl;
		exit(1);
	}
	num_miles = miles;
	fuel_efficency = fuelefficiency;
}

/*Odometer::Odometer() //constructor that initializes values to zero.
{
	num_miles =0;
	fuel_efficency=0;
}*/

void Odometer::reset()
{
	num_miles = 0;
	fuel_efficency = 0;
}

void Odometer::setFuelEfficiency(double fuelefficiency)
{
	fuel_efficency = fuelefficiency;

}
void Odometer::logMiles(double nummiles)
{
	num_miles = num_miles + nummiles;
}
double Odometer::gasConsumed()
{
	double gas_consumed;
	gas_consumed = num_miles/fuel_efficency;
	return gas_consumed;
}