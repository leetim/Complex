#pragma once
#include <string>

class ComplexBase{
public:
	friend bool complex_eq(const ComplexBase& first, const ComplexBase& second, double epsilon);
	friend bool operator==(const ComplexBase& first, const ComplexBase& second);
	friend bool operator<(const ComplexBase& first, const ComplexBase& second);
	virtual double real() const;
	virtual double imaginary() const;
	virtual double mod() const;
	virtual double angle() const;
	virtual std::string to_s();
protected:
	double real_part;
	double imaginary_part;
};

class ComplexDicart: public ComplexBase{
public:
	ComplexDicart();
	ComplexDicart(const double& val);
	ComplexDicart(const double& real, const double& imaginary);
	ComplexDicart(const ComplexBase& val);
	// friend ComplexDicart operator+(const ComplexBase& left, const ComplexBase& right);
	// friend ComplexDicart operator+(const double& left, const ComplexBase& right);
	// friend ComplexDicart operator+(const ComplexBase& left, const double& right);
	// friend ComplexDicart operator-(const ComplexBase& left, const ComplexBase& right);
	// friend ComplexDicart operator-(const double& left, const ComplexBase& right);
	// friend ComplexDicart operator-(const ComplexBase& left, const double& right);
	// friend ComplexDicart operator*(const ComplexBase& left, const ComplexBase& right);
	// friend ComplexDicart operator*(const double& left, const ComplexBase& right);
	// friend ComplexDicart operator*(const ComplexBase& left, const double& right);
	// friend ComplexDicart operator/(const ComplexBase& left, const ComplexBase& right);
	// friend ComplexDicart operator/(const double& left, const ComplexBase& right);
	// friend ComplexDicart operator/(const ComplexBase& left, const double& right);
	ComplexDicart conjugate() const;
	ComplexDicart operator-() const;
	ComplexDicart pow(const unsigned int& exp) const;
};

class ComplexPolar: public ComplexBase{
public:
	ComplexPolar();
	ComplexPolar(const double& val);
	ComplexPolar(const double& mode, const double& angle);
	ComplexPolar(const ComplexBase& val);
	// friend ComplexPolar operator+(const ComplexBase& left, const ComplexBase& right);
	// friend ComplexPolar operator+(const double& left, const ComplexBase& right);
	// friend ComplexPolar operator+(const ComplexBase& left, const double& right);
	// friend ComplexPolar operator-(const ComplexBase& left, const ComplexBase& right);
	// friend ComplexPolar operator-(const double& left, const ComplexBase& right);
	// friend ComplexPolar operator-(const ComplexBase& left, const double& right);
	// friend ComplexPolar operator*(const ComplexBase& left, const ComplexBase& right);
	// friend ComplexPolar operator*(const double& left, const ComplexBase& right);
	// friend ComplexPolar operator*(const ComplexBase& left, const double& right);
	// friend ComplexPolar operator/(const ComplexBase& left, const ComplexBase& right);
	// friend ComplexPolar operator/(const double& left, const ComplexBase& right);
	// friend ComplexPolar operator/(const ComplexBase& left, const double& right);
	ComplexPolar operator-() const;
	ComplexPolar pow(const unsigned int& exp) const;
	std::string to_s();
	double real() const;
	double imaginary() const;
	double mod() const;
	double angle() const;
private:
	double mod_part;
	double angle_part;
};
