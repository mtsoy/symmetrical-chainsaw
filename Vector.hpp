#ifndef __STANDART_LIBRARIES__
#define __STANDART_LIBRARIES__

#include <iostream>
#include <cmath>

#endif

#ifndef __USER_VECTOR__
#define __USER_VECTOR__

//class
class User_Vector{
	public:
		User_Vector();
		User_Vector(int);
		User_Vector(const User_Vector&);
		~User_Vector();
		
		int get_size() const;
		void set_size(int);
		
		User_Vector& operator= (const User_Vector&);
		User_Vector& operator= (const float&);
		User_Vector operator+ (const User_Vector);
		User_Vector operator- (const User_Vector);
		float operator* (const User_Vector);
		float  Norma();
		
		friend std::ostream& operator<< (std::ostream&, const User_Vector&);
		friend std::istream& operator>> (std::istream&, User_Vector&);
	
	private:
		int size;
		float *vec;
};

//constructors and destructor
User_Vector::User_Vector()
{
	size = 1;
	
	vec = new float[size];
	vec[0] = 0.0;
}

User_Vector::User_Vector(int Size)
{
	size = Size;
	
	vec = new float[size];
	for(int i = 0; i < size; ++i)
		vec[i] = 0.0;
}

User_Vector::User_Vector(const User_Vector& A)
{
	set_size(A.size);
	for(int i = 0; i < size; ++i)
		vec[i] = A.vec[i];
}

User_Vector::~User_Vector()
{
	delete[] vec;
}

//get set
int User_Vector::get_size() const
{
	return size;
}

void User_Vector::set_size(int S)
{	
	size = S;
	vec = new float[size];
	for(int i = 0; i < size; ++i)
		vec[i] = 0.0;
}

//arithmetic
User_Vector& User_Vector::operator= (const User_Vector& A)
{
	if(this == &A)
		return *this;
		
	set_size(A.size);
	for(int i = 0; i < (this -> size); ++i)
		(this -> vec)[i] = A.vec[i];
	
	return *this;
}

User_Vector& User_Vector::operator= (const float& A)
{
	for(int i = 0; i < (this -> size); ++i)
		(this -> vec)[i] = A;
	
	return *this;
}

User_Vector User_Vector::operator+ (const User_Vector A)
{
	if((this -> size) != A.size)
		return (*this);
		
	User_Vector result(this -> size);
	
	for(int i = 0; i < (this -> size); ++i)
		result.vec[i] = (this -> vec)[i] + A.vec[i];
	
	return result;
}


User_Vector User_Vector::operator- (const User_Vector A)
{
	if((this -> size) != A.size)
		return (*this);
		
	User_Vector result(this -> size);
	
	for(int i = 0; i < (this -> size); ++i)
		result.vec[i] = (this -> vec)[i] - A.vec[i];
	
	return result;
}


float User_Vector::operator* (const User_Vector A)
{
	if((this -> size) != A.size)
		return 0.0;
		
	float result = 0.0;
	
	for(int i = 0; i < (this -> size); ++i)
		result += (this -> vec)[i] * A.vec[i];
	
	return result;
}

float  User_Vector::Norma()
{
	float result = 0.0;
	
	for(int i = 0; i < size; ++i)
		result += vec[i] * vec[i];
		
	result = sqrt(result);
	
	return result;
}

std::ostream& operator<< (std::ostream& stream, const User_Vector& A)
{
	for(int i = 0; i < A.size; ++i)
		stream << A.vec[i];
		
	return stream;
}

std::istream& operator>> (std::istream& stream, User_Vector& A)
{
	for(int i = 0; i < A.size; ++i)
		stream >> A.vec[i];
		
	return stream;
}

#endif
