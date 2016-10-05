#include<iostream>
#include<cmath>
#include<vector>

//Names: Daniel Minor
//Date: 2/27/16
//Homework # 17
//Problem # (Savitch problem 11-04)
//The source code in this program is my own work and not the work of anyone else. 
//Your signature:

using namespace std;
class Rational
{
public:
	Rational();																							//Default constructor that initializes values to zero
	Rational(int whole_number);																			//Constructor taking in one argument that sets a whole_number properly 															 
	Rational(int num, int denom);																		//Constructor that sets the private variables to any two legitimate values
	friend Rational operator*(const Rational& rational1, const Rational& rational2);					//overloading the * to tell class rational how to multiply properly
	friend Rational operator/(const Rational& rational1, const Rational& rational2);					//overloading the / to tell class rational how to divide properly
	friend Rational operator+(const Rational& rational1, const Rational& rational2);					//overloading the + to tell class rational how to add properly
	friend Rational operator-(const Rational& rational1, const Rational& rational2);					//overloading the - to tell class Rational how to subtract properly
	friend bool operator==(const Rational& rational1, const Rational& rational2);						//overloading the == to tell class Rational how to check for eqality properly
	friend bool operator>(const Rational& rational1, const Rational& rational2);						//overloading the > to tell class Rational how to check if something is greater than properly
	friend bool operator>=(const Rational& rational1, const Rational& rational2);						//overloading the >= to tell class Rational how to check if something is greater than or equal to properly
	friend bool operator<(const Rational& rational1, const Rational& rational2);						//overloading the < to tell class Rational how to check if something is less than properly
	friend bool operator<=(const Rational& rational1, const Rational& rational2);						//overloading the <= to tell class Rational how to check if something is less than or equal to properly
	friend ostream& operator<<(ostream& stream, const Rational& stuff); 								// Overloading the output operator to tell class Rational how to output objects properly. 
	friend istream& operator>>(istream& inputstream,Rational& stuff); 									//Overloading the insertion operator to tell Class Rational how to read in objects of type Rational properly
private:
	int numerator;																						//Int allows for numerator to be aloud to be both positive and negative
	int denominator;																					//Int allows for denominator to be aloud to be both positive and negative
	void reduce();
};

int main()
{
	cout << "Testing declarations" << endl;
	cout << "Rational x, y(2), z(-5,-6), w(1,-3);" << endl;
	Rational x, y(2), z(-5, -6), w(1, -3);
	cout << "z = " << z << ", y = " << y << ",  z = " << z << ", w = " << w << endl;
	cout << "Testing >> overloading. Enter a fraction in the format integer_numerator/integer_denominator" << endl;
	cin >> x;
	cout << "You entered the equivalent of: " << x << endl;
	cout << z << " -  (" << w << ") = " << z - w << endl;
	
	cout << "Testing the constructor and normalization routines: " << endl;
	y = Rational(-128, -48);
	cout << "y = Rational(-128,-48) outputs as " << y << endl;
	y = Rational(-128, 48);
	cout << "y = Rational(-128, 48) outputs as " << y << endl;
	y = Rational(128, -48);
	cout << "y = Rational(128, -48) outputs as " << y << endl;
	Rational a(1, 1);
	cout << "Rational a(1,1); a outputs as: " << a << endl;
	Rational ww = y*a;
	cout << y << " * " << a << " = " << ww << endl;
	w = Rational(25, 9);
	z = Rational(3, 5);
	
	cout << "Testing arithmetic and relational operator overloading" << endl;
	cout << w << " * " << z << " = " << w * z << endl;
	cout << w << " + " << z << " = " << w + z << endl;
	cout << w << " - " << z << " = " << w - z << endl;
	cout << w << " / " << z << " = " << w / z << endl;
	cout << w << " <  " << z << " = " << (w < z) << endl;
	cout << w << " < " << w << " = " << (w < w) << endl;
	cout << w << " <= " << z << " = " << (w <= z) << endl;
	cout << w << " <= " << w << " = " << (w <= w) << endl;
	cout << w << " >  " << z << " = " << (w > z) << endl;
	cout << w << " > " << w << " = " << (w > w) << endl;
	cout << w << " >= " << z << " = " << (w >= z) << endl;
	cout << w << " >= " << w << " = " << (w >= w) << endl;
	
	w = Rational(-21, 9);
	z = Rational(3, 5);
	cout << w << " * " << z << " = " << w * z << endl;
	cout << w << " + " << z << " = " << w + z << endl;
	cout << w << " - " << z << " = " << w - z << endl;
	cout << w << " / " << z << " = " << w / z << endl;
	cout << w << " <  " << z << " = " << (w < z) << endl;
	cout << w << " < " << w << " = " << (w < w) << endl;
	cout << w << " <= " << z << " = " << (w <= z) << endl;
	cout << w << " <= " << w << " = " << (w <= w) << endl;
	cout << w << " >  " << z << " = " << (w > z) << endl;
	cout << w << " > " << w << " = " << (w > w) << endl;
	cout << w << " >= " << z << " = " << (w >= z) << endl;
	cout << w << " >= " << w << " = " << (w >= w) << endl;
	
	cout << endl;
	char dummy;
	cout << "Enter any key to quit." << endl;
	cin >> dummy;
	return 0;
}

Rational::Rational()
{
	int numerator = 0;
	int denominator = 1;
}

Rational::Rational(int whole_number)
{
	numerator = whole_number;
	denominator = 1;

}

Rational::Rational(int num, int denom)
{
	numerator = num;
	denominator = denom;
	
	if (denominator < 0)
	{
		denominator *= -1;
		numerator *= -1;
	}

	int remainder = numerator%denominator;
	int old = denominator;
	while (remainder != 0)
	{
		int temp = remainder;
		remainder = old%remainder;
		old = temp;
	}
	numerator = numerator / old;
	denominator = denominator / old;
}

Rational operator*(const Rational& rational1, const Rational& rational2)
{
	Rational ret;
	ret.numerator = rational1.numerator * rational2.numerator;
	ret.denominator = rational1.denominator * rational2.denominator;
	ret.reduce();
	return ret;
}

Rational operator/(const Rational& rational1, const Rational& rational2)
{
	Rational ret;
	int temp_rational2_denom;
	int temp_rational2_num;
	temp_rational2_num = rational2.denominator;
	temp_rational2_denom = rational2.numerator;
	ret.numerator = rational1.numerator * temp_rational2_num;
	ret.denominator = rational1.denominator * temp_rational2_denom;
	ret.reduce();
	return ret;
}

Rational operator+(const Rational& rational1, const Rational& rational2)
{
	Rational ret;
	int temp1_num;
	int temp2_num;
	temp1_num = rational1.numerator * rational2.denominator;
	temp2_num = rational1.denominator * rational2.numerator;
	ret.numerator = temp1_num + temp2_num;
	ret.denominator = rational1.denominator * rational2.denominator;
	ret.reduce();
	return ret;
}

Rational operator-(const Rational& rational1, const Rational& rational2)
{
	Rational ret;
	ret.numerator = (rational1.numerator*rational2.denominator) - (rational2.numerator * rational1.denominator);
	ret.denominator = rational1.denominator * rational2.denominator;
	ret.reduce();
	return ret;
}

bool operator==(const Rational& rational1, const Rational& rational2)
{
	if ((rational1.numerator * rational2.denominator) == (rational1.denominator * rational2.numerator))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator>(const Rational& rational1, const Rational& rational2)
{
	if (((rational2.numerator * rational1.denominator) < (rational1.numerator*rational2.denominator)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator>=(const Rational& rational1, const Rational& rational2)		
{
	if ((rational2.numerator * rational1.denominator) < (rational1.numerator*rational2.denominator))
	{
		return true;
	}
	else if ((rational1.numerator * rational2.denominator) == (rational1.denominator * rational2.numerator))
		{
			return true;
		}
	else
	{
		return false;
	}
}

bool operator<(const Rational& rational1, const Rational& rational2)
{
	if (((rational1.numerator*rational2.denominator) < (rational2.numerator * rational1.denominator) ))
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool operator<=(const Rational& rational1, const Rational& rational2)
{
	if ((rational1.numerator*rational2.denominator) < (rational2.numerator * rational1.denominator))
	{
		return true;
	}
	else if ((rational1.numerator * rational2.denominator) == (rational1.denominator * rational2.numerator))
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream& stream, const Rational& stuff) 
{
	stream << stuff.numerator << "/" << stuff.denominator; 
	return stream;
}

istream& operator>>(istream& inputstream, Rational& stuff) 
{
	char dummy;
	inputstream >> stuff.numerator >> dummy >> stuff.denominator;
	return inputstream;
}

void Rational::reduce()
{
	int remainder = numerator%denominator;
	int old = denominator;
	while (remainder != 0)
	{
		int temp = remainder;
		remainder = old%remainder;
		old = temp;
	}
	numerator = numerator / old;
	denominator = denominator / old;
}



