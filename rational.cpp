#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

//function declaration
unsigned int FindNOD(int a, int b);


//class of the rational numbers
class Rational{
	public:
		Rational(int numerator = 0, int denominator = 1);
		~Rational(){}
		
		Rational& operator= (const Rational&);
		Rational operator+ (const Rational);
		Rational operator- (const Rational);
		Rational operator* (const Rational);
		Rational operator/ (const Rational);
	
		bool operator== (const Rational) const;
		bool operator!= (const Rational) const;
		bool operator< (const Rational) const;
		bool operator> (const Rational) const;
		bool operator<= (const Rational) const;
		bool operator>= (const Rational) const;
		
		friend ostream& operator<< (ostream&, const Rational&);
		friend istream& operator>> (istream&, Rational&);
	
	private:
		int p;
		unsigned int q;
};


//constructor
Rational::Rational(int numerator, int denominator)
{
	if(denominator == 0)
	{
		cout << "Impossible enter: denominator cannot be equal to zero" << endl;
		cout << "So, the new number will be equated to 0/1" << endl;
		numerator = 0;
		denominator = 1;
	}
	else
	{
		if(numerator == 0)
			denominator = 1;
		else
		{
			int NOD = FindNOD(numerator, denominator);
			numerator /= NOD;
			denominator /= NOD;
			
			if(denominator < 0)
			{
				denominator *= (-1);
				numerator *= (-1);
			}
		}
	}
	
	this -> p = numerator;
	this -> q = denominator;
}


//assignment operator
Rational& Rational::operator= (const Rational& A)
{
	this -> p = A.p;
	this -> q = A.q;
	
	return (*this);
}


//arithmetic operators
Rational Rational::operator+ (const Rational A)
{
	int numerator, denominator;
	numerator = (p * A.q) + (q * A.p);		//reduction to a common denominator
	denominator = q * A.q;
	
	Rational sum(numerator, denominator);
	
	return sum;
}

Rational Rational::operator- (const Rational A)
{
	int numerator, denominator;
	numerator = (p * A.q) - (q * A.p);
	denominator = q * A.q;
	
	Rational sub(numerator, denominator);
	
	return sub;
}

Rational Rational::operator* (const Rational A)
{
	int numerator, denominator;
	numerator = p * A.p;
	denominator = q * A.q;
	
	Rational mult(numerator, denominator);
	
	return mult;
}

Rational Rational::operator/ (const Rational A)
{
	int numerator, denominator;
	numerator = p * A.q;
	denominator = q * A.p;
	
	Rational dev(numerator, denominator);
	
	return dev;
}


//comparison operators
bool Rational::operator== (const Rational A) const
{
	if((this -> p) == A.p)
		if((this -> q) == A.q)
			return true;
			
	return false;
}

bool Rational::operator!= (const Rational A) const
{
	if((this -> p) != A.p)
		return true;
	
	if((this -> q) != A.q)
		return true;
			
	return false;
}

bool Rational::operator< (const Rational A) const
{			
	return (p * A.q) < (q * A.p);
}

bool Rational::operator> (const Rational A) const
{			
	return (p * A.q) > (q * A.p);
}

bool Rational::operator<= (const Rational A) const
{			
	return (p * A.q) <= (q * A.p);
}

bool Rational::operator>= (const Rational A) const
{			
	return (p * A.q) >= (q * A.p);
}


//input and output operators
ostream& operator<< (ostream& stream, const Rational& A)
{
	stream << A.p << "/" << A.q;			
	
	return stream;
}

istream& operator>> (istream& stream, Rational& A)
{
	int numerator, denominator;
	
	cout << "Numerator: "; 
	stream >> numerator;
	
	cout << "Denominator: "; 
	stream >> denominator;
	
	Rational tmp(numerator, denominator);
	A = tmp;
	
	return stream;
}


//function. seaching NOD by Euqlid's method
unsigned int FindNOD(int a, int b)
{
	a = abs(a);
	b = abs(b);
	
	while(a != b)
	{
		if(a > b)
			a -= b;
		else
			b -= a;
	}
	
	return a;
}


int main()
{
	/*DEMONSTRATION OF THE WORK WITH CLASS*/
	
	Rational A;				//by default A = 0/1 
	cout << "A = " << A;	//expected output "0/1"
	cout << endl;
	
	Rational B(6, 8);		//B = 6/8 = 3/4
	cout << "B = " << B;	//expected output "3/4"
	cout << endl;
	
	Rational C;
	cin >> C;
	cout << "C = " << C;
	cout << endl;			
	
	A = (B + C)*B;
	if(A > B)																//condition is true when C < 1/4
		cout << "(" << B << " + " << C << ")"<< "*" << B << " = " << A;		//it will be displayed, if A > B, i.e. if C < 1/4
		
	cout << endl;
	
	/*DEMONSTRAION OF USING CLASS' OBJECTS AS ELEMENTS OF MAP*/
	
	map < Rational, string > M;
	M[B] = "three-quarters";
	
	cout << "The name for " << A << ": ";
	cin >> M[A];
	
	cout << "The name for " << C << ": ";
	cin >> M[C];
	
	cout << M[A] << " " << M[B] << " " << M[C];
	cout << endl;
	
	return 0;
}
