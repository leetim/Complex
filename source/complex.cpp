#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <sstream>

#include <complex.h>

#define SQR(x) ((x)*(x))
#define EPSILON 0.0000001

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////
//fuctions
//Проверка на равенство 2-х комплексных чисел с заданной точностью
bool complex_eq(const Complex& fir, const Complex& sec, double eps){
	double fr = fir.real();
	double fi = fir.imaginary(); 
	double sr = sec.real();
	double si = sec.imaginary(); 
	return (abs(fr - sr) < eps) && 
		   (abs(fi - si) < eps);
}

//Равенство 2-х комплексных чисел с точностью EPSILON
bool operator==(const Complex& first, const Complex& second){
	return complex_eq(first, second, EPSILON);
}

//Сравнение 2-х чисел
//Вообще говоря это не математический порядок,
//Нужен лишь для использования в set и map и для прочих сортировок
bool operator<(const Complex& first, const Complex& second){
	if (first.real() != second.real()){	
		return first.real() < second.real();
	}
	else{
		return first.imaginary() < second.imaginary();
	}  
}

//////////////////////////////////////////////////////////////////////////////////////////////
//Complex
//Стандартный конструктор
Complex::Complex(){
	real_part = 0.0;
	imaginary_part = 0.0;
}

//Конструктор из действительного числа
Complex::Complex(const double& v){
	real_part = v;
	imaginary_part = 0.0;
}

//Конструктор с мнимой и действительной частью
Complex::Complex(const double& v, const double& r){
	real_part = v;
	imaginary_part = r;
}

//Конструктор копирования комплексного числа в другом представлении
Complex::Complex(const Complex& v){
	real_part = v.real();
	imaginary_part = v.imaginary();
}

//Получение сопряженного комплексного числа
Complex Complex::conjugate() const{
	return Complex(real_part, -imaginary_part);
}

//получение обратного относительно сложения
Complex Complex::operator-() const{
	return Complex(-real_part, -imaginary_part);
}

//Возведение в степень
Complex Complex::pow(const int& expn) const{
	double m = std::pow(abs(), expn);
	double a = angle() * expn;
	return Complex(m * cos(a), m * sin(a));
}

//Действительная часть числа
double Complex::real() const{
	return real_part;
}

//Мнимая часть числа
double Complex::imaginary() const{
	return imaginary_part;
}

//Модуль числа
double Complex::abs() const{
	return sqrt(SQR(real_part) + SQR(imaginary_part));
}

//Квадрат модуля числа
double Complex::abs2() const{
	return SQR(real_part) + SQR(imaginary_part);
}

//Угол в полярном предствалении
double Complex::angle() const{
	if (abs() == 0.0){
		return 0.0;
	} 
	return atan2(imaginary_part, real_part);
}

//Преобразование к строке
string Complex::to_s(){
	std::stringstream ss;
	ss << "(" << real_part << ") + (" << imaginary_part << ")i";
	return ss.str();
}

//////////////////////////////////////////////////////////////////////////////////////////////
//ComplexPolar
//Стандартный конструктор
ComplexPolar::ComplexPolar(){
	abs_part = 0.0;
	angle_part = 0.0;
}

//конструктор из действительного числа
ComplexPolar::ComplexPolar(const double& val){
	abs_part = val;
	angle_part = 0.0;
}

//конструктор из полярных координат
ComplexPolar::ComplexPolar(const double& abs, const double& angle){
	abs_part = abs;
	if (abs == 0.0){
		angle_part = 0.0;
		return;
	}
	angle_part = angle;
}

//Конструктор копирования
ComplexPolar::ComplexPolar(const ComplexPolar& val){
	abs_part = val.abs();
	angle_part = val.angle();
}

//Конструктор копирования комплексного числа в другом представлении
ComplexPolar::ComplexPolar(const Complex& val){
	abs_part = val.abs();
	angle_part = val.angle();
}

//полярное сопряженное
ComplexPolar ComplexPolar::conjugate() const{
	return ComplexPolar(abs(), -angle());
}

//получение обратного числа относительно сложения
ComplexPolar ComplexPolar::operator-() const{
	return ComplexPolar(abs(), angle() + M_PI);
}

//Возведение в степень
ComplexPolar ComplexPolar::pow(const int& expn) const{
	double m = std::pow(abs(), expn);
	double a = angle() * expn;
	return ComplexPolar(m, a);
}

//Преобразование к строке
string ComplexPolar::to_s(){
	stringstream ss;
	ss << abs() << "(cos(" << angle() << ")+i sin(" << angle() << "))";
	return ss.str();
}

//Действительная часть
double ComplexPolar::real() const{
	return abs() * cos(angle());
}

//Мнимая часть
double ComplexPolar::imaginary() const{
	return abs() * sin(angle());
}

//Модуль числа
double ComplexPolar::abs() const{
	return abs_part;
}

//Квадрат модуля числа
double ComplexPolar::abs2() const{
	return SQR(abs_part);
}

//Угло в полярных координатах
double ComplexPolar::angle() const{
	if (std::abs(angle_part) > M_PI){
		return atan2(sin(angle_part), cos(angle_part));
	}
	return angle_part;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//Complex friend function
//Сложение
Complex operator+(const Complex& left, const Complex& right){
	double r = left.real() + right.real();
	double i = left.imaginary() + right.imaginary();
	return Complex(r, i);
}

//Сложение с double слева
Complex operator+(const double& left, const Complex& right){
	return Complex(left + right.real(), right.imaginary());
}

//Сложение с double справа
Complex operator+(const Complex& left, const double& right){
	return right + left;
}

//Вычитание
Complex operator-(const Complex& left, const Complex& right){
	return left + (-right);
}

//Вычитание из double
Complex operator-(const double& left, const Complex& right){
	return left + (-right);
}

//Вычитание double
Complex operator-(const Complex& left, const double& right){
	return left + (-right);
}

//Умножение
Complex operator*(const Complex& left, const Complex& right){
	double lr = left.real();
	double li = left.imaginary();
	double rr = right.real();
	double ri = right.imaginary();
	return Complex(lr * rr - li * ri, lr * ri + li * rr);
}

//Умножение на double слева
Complex operator*(const double& left, const Complex& right){
	return Complex(left * right.real(), left * right.imaginary());
}

//Умножение на double справа
Complex operator*(const Complex& left, const double& right){
	return right * left;
}

//Деление
Complex operator/(const Complex& left, const Complex& right){
	return left * right.conjugate() / right.abs2();
}

//Деление действительного числа
Complex operator/(const double& left, const Complex& right){
	return Complex(left) / right;
}

//Деление на действительное число
Complex operator/(const Complex& left, const double& right){
	return Complex(left.real() / right, left.imaginary() / right);
}

//////////////////////////////////////////////////////////////////////////////////////////////
//ComplexPolar friend functions
//Сложение
ComplexPolar operator+(const ComplexPolar& left, const ComplexPolar& right){
	Complex t1 = left;
	Complex t2 = right;
	return ComplexPolar(t1 + t2);
}

//Сложение с double слева
ComplexPolar operator+(const double& left, const ComplexPolar& right){
	Complex t = right;
	return ComplexPolar(left + t);
}

//Сложение с double справа
ComplexPolar operator+(const ComplexPolar& left, const double& right){
	return right + left;
}

//Разность
ComplexPolar operator-(const ComplexPolar& left, const ComplexPolar& right){
	Complex t1 = left;
	Complex t2 = right;
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
	return ComplexPolar(left.abs() * right.abs(), left.angle() + right.angle());
}

//Умножение на double слева
ComplexPolar operator*(const double& left, const ComplexPolar& right){
	return ComplexPolar(left * right.abs(), right.angle());
}

//Умножение на double справа
ComplexPolar operator*(const ComplexPolar& left, const double& right){
	return right * left;
}

//Деление
ComplexPolar operator/(const ComplexPolar& left, const ComplexPolar& right){
	return ComplexPolar(left.abs() / right.abs(), left.angle() - right.angle());
}

//Деление double
ComplexPolar operator/(const double& left, const ComplexPolar& right){
	return ComplexPolar(left / right.abs(), -right.angle());
}

//Деление на double
ComplexPolar operator/(const ComplexPolar& left, const double& right){
	return ComplexPolar(left.abs() / right, left.angle());
}
