/**
 * Complex - class to represent a complex number 
 * 
 */
#ifndef COMPLEX_H
#define COMPLEX_H

#include <string>
#include <iostream>
#include <limits>

class Complex
{
public:
	/**
	* Constructors geting double or default which is set to 0
	*/
	Complex(const double  &value = 0);
	/**
	* Constructors geting real and imaginary part
	*/
	Complex(const double  &real, const double &imaginary);
	/**
	* Constructors by string "<real> + <imaginary>i"
	*/

/**
	* copy Constructor
	*/
	Complex(const Complex &other);
	

	const Complex conj() const;
	/**
	 * Returns the real part
	 */
	 double getReal() const;
	/**
	 * Returns the imaginary part
	 */
	 double getImaginary() const;

	/**
	 * Summing two Complexs
	 */
	const Complex operator+(const Complex &other) const;
	 Complex& operator+=(const Complex &other) ;
	 const Complex operator-(const Complex &other) const;
	 Complex& operator-=(const Complex &other) ;
	
	/**
	 * Multiplying operator for Complex
	 */
	const Complex operator*(const Complex &other) const;
Complex& operator*=(const Complex &other) ;
	/**
	 * operator<< for stream insertion
	 * The format is <real> + <img>i
	 */
	friend std::ostream& operator<<(std::ostream &os, const Complex &number);

	/**
	 * ==
	 */

	 bool operator==(const Complex &other) const;
	 bool operator!=(const Complex &other) const;

private:
	double _real;
	double _imaginary;

};

#endif
