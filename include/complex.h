#pragma once
#include <string>

class ComplexBase{
public:
	friend bool complex_eq(const ComplexBase& first, const ComplexBase& second, double epsilon);
	friend bool operator==(const ComplexBase& first, const ComplexBase& second);
	friend bool operator<(const ComplexBase& first, const ComplexBase& second);
	virtual double real() const =0;
	virtual double imaginary() const =0;
	virtual double mod() const =0;
	virtual double angle() const =0;
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
	double mod() const;
	double angle() const;
protected:
	double real_part;
	double imaginary_part;
};

class ComplexPolar: public ComplexBase{
public:
	ComplexPolar();
	ComplexPolar(const double& val);
	ComplexPolar(const double& mode, const double& angle);
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
	double mod() const;
	double angle() const;
private:
	double mod_part;
	double angle_part;
};
