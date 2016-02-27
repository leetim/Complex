#include <cmath>
#include <iostream>
#include <sstream>

#include <complex.h>

#define SQR(x) ((x)*(x))
#define EPSILON 0.0000001

using namespace std;

bool complex_eq(const ComplexBase& fir, const ComplexBase& sec, double eps){
	double fr = fir.real();
	double fi = fir.imaginary(); 
	double sr = sec.real();
	double si = sec.imaginary(); 
	return (abs(fr - sr) < eps) && 
		   (abs(fi - si) < eps);
}

bool operator==(const ComplexBase& first, const ComplexBase& second){
	return complex_eq(first, second, EPSILON);
}

bool operator<(const ComplexBase& first, const ComplexBase& second){
	if (first.real() != second.real()){	
		return first.real() < second.real();
	}
	else{
		return first.imaginary() < second.imaginary();
	}  
}

double ComplexBase::real() const{
	return real_part;
}

double ComplexBase::imaginary() const{
	return imaginary_part;
}

double ComplexBase::mod() const{
	return sqrt(SQR(real_part) + SQR(imaginary_part));
}

double ComplexBase::angle() const{
	if (mod() == 0.0){
		return 0.0;
	}
	return atan2(imaginary_part, real_part);
}

string ComplexBase::to_s(){
	std::stringstream ss;
	ss << "(" << real_part << ") + (" << imaginary_part << ")i";
	return ss.str();
}

ComplexDicart::ComplexDicart(){
	real_part = 0.0;
	imaginary_part = 0.0;
}

ComplexDicart::ComplexDicart(const double& v){
	real_part = v;
	imaginary_part = 0.0;
}

ComplexDicart::ComplexDicart(const double& v, const double& r){
	real_part = v;
	imaginary_part = r;
}

ComplexDicart::ComplexDicart(const ComplexBase& v){
	real_part = v.real();
	imaginary_part = v.imaginary();
}

ComplexDicart ComplexDicart::conjugate() const{
	return ComplexDicart(real_part, -imaginary_part);
}

ComplexDicart ComplexDicart::operator-() const{
	return ComplexDicart(-real_part, -imaginary_part);
}

ComplexDicart ComplexDicart::pow(const unsigned int& expn) const{
	double m = std::pow(mod(), expn);
	double a = angle() * expn;
	return ComplexDicart(m * cos(a), m * sin(a));
}


// ComplexPolar::ComplexPolar(){
// 	mod_part = 0.0;
// 	angle_part = 0.0;
// }

// ComplexPolar::ComplexPolar(const double& val){
// 	mod_part = val;
// 	angle_part = 0.0;
// }

// ComplexPolar::ComplexPolar(const double& mode, const double& angle){
// 	mod_part = mode;
// 	angle_part = angle;
// }

// ComplexPolar::ComplexPolar(const ComplexBase& val){
// 	mod_part = val.mod();
// 	angle_part = val.angle();
// }

// ComplexPolar ComplexPolar::operator-() const{
// 	return ComplexPolar();
// }

