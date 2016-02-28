#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <sstream>

#include <complex.h>

#define SQR(x) ((x)*(x))
#define EPSILON 0.0000001

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////
//ComplexBase
//Проверка на равенство 2-х комплексных чисел с заданной точностью
bool complex_eq(const ComplexBase& fir, const ComplexBase& sec, double eps){
	double fr = fir.real();
	double fi = fir.imaginary(); 
	double sr = sec.real();
	double si = sec.imaginary(); 
	return (abs(fr - sr) < eps) && 
		   (abs(fi - si) < eps);
}

//Равенство 2-х комплексных чисел с точностью EPSILON
bool operator==(const ComplexBase& first, const ComplexBase& second){
	return complex_eq(first, second, EPSILON);
}

//Сравнение 2-х чисел
//Вообще говоря это не математический порядок,
//Нужен лишь для использования в set и map и для прочих сортировок
bool operator<(const ComplexBase& first, const ComplexBase& second){
	if (first.real() != second.real()){	
		return first.real() < second.real();
	}
	else{
		return first.imaginary() < second.imaginary();
	}  
}

ComplexBase::ComplexBase(){

}

double ComplexBase::real() const{
	return 0.0;
}

double ComplexBase::imaginary() const{
	return 0.0;
}

double ComplexBase::mod() const{
	return 0.0;
}

double ComplexBase::angle() const{
	return 0.0;
}

string ComplexBase::to_s(){
	return "";
}

//////////////////////////////////////////////////////////////////////////////////////////////
//ComplexDicart
//Стандартный конструктор
ComplexDicart::ComplexDicart(){
	real_part = 0.0;
	imaginary_part = 0.0;
}

//Конструктор из действительного числа
ComplexDicart::ComplexDicart(const double& v){
	real_part = v;
	imaginary_part = 0.0;
}

//Конструктор с мнимой и действительной частью
ComplexDicart::ComplexDicart(const double& v, const double& r){
	real_part = v;
	imaginary_part = r;
}

//Конструктор копирования
ComplexDicart::ComplexDicart(const ComplexBase& v){
	real_part = v.real();
	imaginary_part = v.imaginary();
}

//Получение сопряженного комплексного числа
ComplexDicart ComplexDicart::conjugate() const{
	return ComplexDicart(real_part, -imaginary_part);
}

//получение обратного относительно сложения
ComplexDicart ComplexDicart::operator-() const{
	return ComplexDicart(-real_part, -imaginary_part);
}

//Возведение в степень
ComplexDicart ComplexDicart::pow(const int& expn) const{
	double m = std::pow(mod(), expn);
	double a = angle() * expn;
	return ComplexDicart(m * cos(a), m * sin(a));
}

//Действительная часть числа
double ComplexDicart::real() const{
	return real_part;
}

//Мнимая часть числа
double ComplexDicart::imaginary() const{
	return imaginary_part;
}

//Модуль числа
double ComplexDicart::mod() const{
	return sqrt(SQR(real_part) + SQR(imaginary_part));
}

//Угол в полярном предствалении
double ComplexDicart::angle() const{
	if (mod() == 0.0){
		return 0.0;
	}
	return atan2(imaginary_part, real_part);
}

//Преобразование к строке
string ComplexDicart::to_s(){
	std::stringstream ss;
	ss << "(" << real_part << ") + (" << imaginary_part << ")i";
	return ss.str();
}

//////////////////////////////////////////////////////////////////////////////////////////////
//ComplexPolar
//Стандартный конструктор
ComplexPolar::ComplexPolar(){
	mod_part = 0.0;
	angle_part = 0.0;
}

//конструктор из действительного числа
ComplexPolar::ComplexPolar(const double& val){
	mod_part = val;
	angle_part = 0.0;
}

//конструктор из полярных координат
ComplexPolar::ComplexPolar(const double& mod, const double& angle){
	mod_part = mod;
	if (mod == 0.0){
		angle_part = 0.0;
		return;
	}
	angle_part = angle;
}

//Конструктор копирования
ComplexPolar::ComplexPolar(const ComplexBase& val){
	mod_part = val.mod();
	angle_part = val.angle();
}

//полярное сопряженное
ComplexPolar ComplexPolar::conjugate() const{
	return ComplexPolar(mod(), -angle());
}

//получение обратного числа относительно сложения
ComplexPolar ComplexPolar::operator-() const{
	return ComplexPolar(mod(), angle() + M_PI);
}

//Возведение в степень
ComplexPolar ComplexPolar::pow(const int& expn) const{
	double m = std::pow(mod(), expn);
	double a = angle() * expn;
	return ComplexPolar(m, a);
}

//Преобразование к строке
string ComplexPolar::to_s(){
	stringstream ss;
	ss << mod() << "(cos(" << angle() << ")+i sin(" << angle() << "))";
	return ss.str();
}

//Действительная часть
double ComplexPolar::real() const{
	return mod() * cos(angle());
}

//Мнимая часть
double ComplexPolar::imaginary() const{
	return mod() * sin(angle());
}

//Модуль числа
double ComplexPolar::mod() const{
	return mod_part;
}

//Угло в полярных координатах
double ComplexPolar::angle() const{
	return angle_part;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//ComplexDicart friend function
//Сложение
ComplexDicart operator+(const ComplexDicart& left, const ComplexDicart& right){
	double r = left.real() + right.real();
	double i = left.imaginary() + right.imaginary();
	return ComplexDicart(r, i);
}

//Сложение с double слева
ComplexDicart operator+(const double& left, const ComplexDicart& right){
	return ComplexDicart(left + right.real(), right.imaginary());
}

//Сложение с double справа
ComplexDicart operator+(const ComplexDicart& left, const double& right){
	return right + left;
}

//Вычитание
ComplexDicart operator-(const ComplexDicart& left, const ComplexDicart& right){
	return left + (-right);
}

//Вычитание из double
ComplexDicart operator-(const double& left, const ComplexDicart& right){
	return left + (-right);
}

//Вычитание double
ComplexDicart operator-(const ComplexDicart& left, const double& right){
	return left + (-right);
}

//Умножение
ComplexDicart operator*(const ComplexDicart& left, const ComplexDicart& right){
	double lr = left.real();
	double li = left.imaginary();
	double rr = right.real();
	double ri = right.imaginary();
	return ComplexDicart(lr * rr - li * ri, lr * ri + li * rr);
}

//Умножение на double слева
ComplexDicart operator*(const double& left, const ComplexDicart& right){
	return ComplexDicart(left * right.real(), left * right.imaginary());
}

//Умножение на double справа
ComplexDicart operator*(const ComplexDicart& left, const double& right){
	return right * left;
}

//Деление
ComplexDicart operator/(const ComplexDicart& left, const ComplexDicart& right){
	return left * right.conjugate() / right.mod();
}

//Деление действительного числа
ComplexDicart operator/(const double& left, const ComplexDicart& right){
	return ComplexDicart(left) / right;
}

//Деление на действительное число
ComplexDicart operator/(const ComplexDicart& left, const double& right){
	return ComplexDicart(left.real() / right, left.imaginary() / right);
}

//////////////////////////////////////////////////////////////////////////////////////////////
//ComplexPolar friend functions
//Сложение
ComplexPolar operator+(const ComplexPolar& left, const ComplexPolar& right){
	ComplexDicart t1 = left;
	ComplexDicart t2 = right;
	return ComplexPolar(t1 + t2);
}

//Сложение с double слева
ComplexPolar operator+(const double& left, const ComplexPolar& right){
	ComplexDicart t = right;
	return ComplexPolar(left + t);
}

//Сложение с double справа
ComplexPolar operator+(const ComplexPolar& left, const double& right){
	return right + left;
}

//Разность
ComplexPolar operator-(const ComplexPolar& left, const ComplexPolar& right){
	ComplexDicart t1 = left;
	ComplexDicart t2 = right;
	return ComplexPolar(t1 - t2);
}

//Вычитание из double
ComplexPolar operator-(const double& left, const ComplexPolar& right){
	return ComplexPolar(left) - right;
}

//Вычитание double
ComplexPolar operator-(const ComplexPolar& left, const double& right){
	return left - ComplexPolar(right);
}

//Умножение
ComplexPolar operator*(const ComplexPolar& left, const ComplexPolar& right){
	return ComplexPolar(left.mod() * right.mod(), left.angle() + right.angle());
}

//Умножение на double слева
ComplexPolar operator*(const double& left, const ComplexPolar& right){
	return ComplexPolar(left * right.mod(), right.angle());
}

//Умножение на double справа
ComplexPolar operator*(const ComplexPolar& left, const double& right){
	return right * left;
}

//Деление
ComplexPolar operator/(const ComplexPolar& left, const ComplexPolar& right){
	return ComplexPolar(left.mod() / right.mod(), left.angle() - right.angle());
}

//Деление double
ComplexPolar operator/(const double& left, const ComplexPolar& right){
	return ComplexPolar(left / right.mod(), -right.angle());
}

//Деление на double
ComplexPolar operator/(const ComplexPolar& left, const double& right){
	return ComplexPolar(left.mod() / right, left.mod());
}
