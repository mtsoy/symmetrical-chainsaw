#ifndef __STANDART_LIBRARIES__
#define __STANDART_LIBRARIES__

#include <iostream>
#include <cmath>

#endif

#ifndef __USER_COMPLEX__
#define __USER_COMPLEX__

//class
template <class T>
class Complex{
	private:
		T re, im;
		
	public:
		//constructors
		Complex();
		Complex(T, T);
		
		//get,set
		T get_real() const;
		T get_imag() const;
		void set_real(T);
		void set_imag(T);
		
		//abs
		double abs() const;
		
		//arithmetic
		Complex<T>& operator= (const Complex<T>&);
		
		template <class U>
		friend Complex<U> operator+ (const Complex<U>, const Complex<U>);
		
		template <class U>
		friend Complex<U> operator- (const Complex<U>, const Complex<U>);
		
		template <class U>
		friend Complex<U> operator* (const Complex<U>, const Complex<U>);
		
		template <class U>
		friend Complex<U> operator* (const Complex<U>, const double);
		
		template <class U>
		friend Complex<U> operator* (const double, const Complex<U>);
		
		template <class U>
		friend Complex<U> operator- (const Complex<U>);
		
		//input output
		template <class U>
		friend std::ostream& operator<< (std::ostream&, const Complex<U>&);
		
		template <class U>
		friend std::istream& operator>> (std::istream&, Complex<U>&);
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

//input output
template <class T>
std::ostream& operator<< (std::ostream& stream, const Complex<T>& A)
{
	stream << "real: "<< A.re << "\n";
	stream << "imag: "<< A.im << "\n";
	return stream;
}

template <class T>
std::istream& operator>> (std::istream& stream, Complex<T>& A)
{
	stream >> A.re;	
	stream >> A.im;	
	return stream;
}

#endif
