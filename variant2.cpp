#include <iostream>
#include <cmath>
#include "Vector.hpp"

template <class T>
class Complex{
	private:
		T re, im;
		
	public:
		Complex();
		Complex(T, T);
		
		T get_real() const;
		T get_imag() const;
		void set_real(T);
		void set_imag(T);
		
		double abs() const;
		
		Complex<T>& operator= (const Complex&);
		friend Complex<T> operator+ (const Complex<T>, const Complex<T>);
		friend Complex<T> operator- (const Complex<T>, const Complex<T>);
		friend Complex<T> operator* (const Complex<T>, const Complex<T>);
		friend Complex<T> operator* (const Complex<T>, const double);
		friend Complex<T> operator* (const double, const Complex<T>);
		friend Complex<T> operator- (const Complex<T>);
};

//constructors
template <class T>
Complex<T>::Complex()
{
	re = 0.0;
	im = 0.0;
}

template <class T>
Complex<T>::Complex(T real, T imag)
{
	re = real;
	im = imag;
}

//get, set, abs
template <class T>
T Complex<T>::get_real() const
{
	return re;
}

template <class T>
T Complex<T>::get_imag() const
{
	return im;
}

template <class T>
void Complex<T>::set_real(T real)
{
	re = real;
}

template <class T>
void Complex<T>::set_imag(T imag)
{
	im = imag;
}

template <class T>
double Complex<T>::abs() const
{
	return sqrt((re * re) + (im * im));
}

//operators
template <class T>
Complex<T>& Complex<T>::operator= (const Complex& a)
{
	this -> re = a.re;
	this -> im = a.im;
	
	return (*this);
}

template <class T>
Complex<T> operator+ (const Complex<T> a, const Complex<T> b)
{
	double real = a.re + b.re;
	double imag = a.im + b.im;
	
	Complex<T> result(real, imag);
	
	return result;
}

template <class T>
Complex<T> operator- (const Complex<T> a, const Complex<T> b)
{
	double real = a.re - b.re;
	double imag = a.im - b.im;
	
	Complex<T> result(real, imag);
	
	return result;
}

template <class T>
Complex<T> operator* (const Complex<T> a, const Complex<T> b)
{
	double real = (a.re * b.re) - (a.im * b.im);
	double imag = (a.re * b.im) + (a.im * b.re);
	
	Complex<T> result(real, imag);
	
	return result;
}

template <class T>
Complex<T> operator* (const Complex<T> a, const double N)
{
	double real = N * a.re;
	double imag = N * a.im;
	
	Complex<T> result(real, imag);
	
	return result;
}

template <class T>
Complex<T> operator* (const double N, const Complex<T> a)
{
	double real = N * a.re;
	double imag = N * a.im;
	
	Complex<T> result(real, imag);
	
	return result;
}

template <class T>
Complex<T> operator- (const Complex<T> a)
{
	double real = -a.re;
	double imag = -a.im;
	
	Complex<T> result(real, imag);
	
	return result;
}



//check
int main()
{
	User_Vector a;
	Complex<User_Matrix> b(a, a);
	
	return 0;
}
