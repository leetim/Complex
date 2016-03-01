#pragma once
#include <string>

class Complex{
public:
	Complex();
	Complex(const double& val);
	Complex(const double& real, const double& imaginary);
	Complex(const Complex& val);
	friend Complex operator+(const Complex& left, const Complex& right);
	friend Complex operator+(const double& left, const Complex& right);
	friend Complex operator+(const Complex& left, const double& right);
	friend Complex operator-(const Complex& left, const Complex& right);
	friend Complex operator-(const double& left, const Complex& right);
	friend Complex operator-(const Complex& left, const double& right);
	friend Complex operator*(const Complex& left, const Complex& right);
	friend Complex operator*(const double& left, const Complex& right);
	friend Complex operator*(const Complex& left, const double& right);
	friend Complex operator/(const Complex& left, const Complex& right);
	friend Complex operator/(const double& left, const Complex& right);
	friend Complex operator/(const Complex& left, const double& right);
	Complex conjugate() const;
	Complex operator-() const;
	Complex pow(const int& expn) const;
	std::string to_s();
	virtual double real() const;
	virtual double imaginary() const;
	virtual double abs() const;
	virtual double abs2() const;
	virtual double angle() const;
private:
	double real_part;
	double imaginary_part;
};

typedef Complex ComplexBase; 
typedef Complex ComplexDicart;

class ComplexPolar: public Complex{
public:
	ComplexPolar();
	ComplexPolar(const double& val);
	ComplexPolar(const double& abse, const double& angle);
	ComplexPolar(const ComplexPolar& val);
	ComplexPolar(const Complex& val);
	friend ComplexPolar operator+(const ComplexPolar& left, const ComplexPolar& right);
	friend ComplexPolar operator+(const double& left, const ComplexPolar& right);
	friend ComplexPolar operator+(const ComplexPolar& left, const double& right);
	friend ComplexPolar operator-(const ComplexPolar& left, const ComplexPolar& right);
	friend ComplexPolar operator-(const double& left, const ComplexPolar& right);
	friend ComplexPolar operator-(const ComplexPolar& left, const double& right);
	friend ComplexPolar operator*(const ComplexPolar& left, const ComplexPolar& right);
	friend ComplexPolar operator*(const double& left, const ComplexPolar& right);
	friend ComplexPolar operator*(const ComplexPolar& left, const double& right);
	friend ComplexPolar operator/(const ComplexPolar& left, const ComplexPolar& right);
	friend ComplexPolar operator/(const double& left, const ComplexPolar& right);
	friend ComplexPolar operator/(const ComplexPolar& left, const double& right);
	ComplexPolar conjugate() const;
	ComplexPolar operator-() const;
	ComplexPolar pow(const int& expn) const;
	std::string to_s();
	double real() const;
	double imaginary() const;
	double abs() const;
	double abs2() const;
	double angle() const;
private:
	double abs_part;
	double angle_part;
};

bool complex_eq(const Complex& first, const Complex& second, double epsilon);
bool operator==(const Complex& first, const Complex& second);
bool operator<(const Complex& first, const Complex& second);
