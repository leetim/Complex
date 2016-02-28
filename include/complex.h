#pragma once
#include <string>

class ComplexBase{
public:
	ComplexBase();
	virtual double real() const;
	virtual double imaginary() const;
	virtual double abs() const;
	virtual double angle() const;
	virtual std::string to_s();
};

class ComplexDicart: public ComplexBase{
public:
	ComplexDicart();
	ComplexDicart(const double& val);
	ComplexDicart(const double& real, const double& imaginary);
	ComplexDicart(const ComplexBase& val);
	friend ComplexDicart operator+(const ComplexDicart& left, const ComplexDicart& right);
	friend ComplexDicart operator+(const double& left, const ComplexDicart& right);
	friend ComplexDicart operator+(const ComplexDicart& left, const double& right);
	friend ComplexDicart operator-(const ComplexDicart& left, const ComplexDicart& right);
	friend ComplexDicart operator-(const double& left, const ComplexDicart& right);
	friend ComplexDicart operator-(const ComplexDicart& left, const double& right);
	friend ComplexDicart operator*(const ComplexDicart& left, const ComplexDicart& right);
	friend ComplexDicart operator*(const double& left, const ComplexDicart& right);
	friend ComplexDicart operator*(const ComplexDicart& left, const double& right);
	friend ComplexDicart operator/(const ComplexDicart& left, const ComplexDicart& right);
	friend ComplexDicart operator/(const double& left, const ComplexDicart& right);
	friend ComplexDicart operator/(const ComplexDicart& left, const double& right);
	ComplexDicart conjugate() const;
	ComplexDicart operator-() const;
	ComplexDicart pow(const int& expn) const;
	std::string to_s();
	double real() const;
	double imaginary() const;
	double abs() const;
	double abs2() const;
	double angle() const;
protected:
	double real_part;
	double imaginary_part;
};

class ComplexPolar: public ComplexBase{
public:
	ComplexPolar();
	ComplexPolar(const double& val);
	ComplexPolar(const double& abse, const double& angle);
	ComplexPolar(const ComplexBase& val);
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

bool complex_eq(const ComplexBase& first, const ComplexBase& second, double epsilon);
bool operator==(const ComplexBase& first, const ComplexBase& second);
bool operator<(const ComplexBase& first, const ComplexBase& second);
