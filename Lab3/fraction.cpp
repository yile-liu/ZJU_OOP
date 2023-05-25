#include <system_error>
#include <iostream>
#include <sstream>
#include "fraction.h"


using namespace std;

int BCD(int n1, int n2) {
    int temp = 0;
    if (n1 == 0 || n2 == 0) {
        return 1;
    }

    n1 = n1 < 0 ? -n1 : n1;
    n2 = n2 < 0 ? -n2 : n2;
    if (n1 < n2) {
        temp = n1;
        n1 = n2;
        n2 = temp;
    }

    while (n1 % n2) {
        temp = n1 % n2;
        n1 = n2;
        n2 = temp;
    }
    return n2;
}

void Fraction::simplify() {
    if (numerator == 0) {
        denominator = 1;
    } else if (denominator == 0) {
        exit(1);
    } else {
        int temp = BCD(denominator, numerator);
        denominator /= temp;
        numerator /= temp;
    }
}

//ctor from 2 integers
Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
    simplify();
}

//copy ctor
Fraction::Fraction(const Fraction &frac) {
    this->numerator = frac.numerator;
    this->denominator = frac.denominator;
    simplify();
}

Fraction Fraction::operator*(int mul) {
    Fraction res = *this;
    res.numerator *= mul;
    res.simplify();
    return res;
}

Fraction Fraction::operator/(int div) {
    Fraction res = *this;
    res.denominator *= div;
    res.simplify();
    return res;
}

Fraction Fraction::operator*(const Fraction &frac) {
    Fraction res = *this;
    res.numerator *= frac.numerator;
    res.denominator *= frac.denominator;
    res.simplify();
    return res;
}

Fraction Fraction::operator/(const Fraction &frac) {
    Fraction res = *this;
    res.numerator *= frac.denominator;
    res.denominator *= frac.numerator;
    res.simplify();
    return res;
}

Fraction Fraction::operator+(const Fraction &frac) {
    Fraction res = *this;
    res.numerator *= frac.denominator;
    res.denominator *= frac.denominator;
    res.numerator += frac.numerator * this->denominator;
    res.simplify();
    return res;
}

Fraction Fraction::operator+(int add) {
    Fraction res = *this;
    res.numerator += add * this->denominator;
    res.simplify();
    return res;
}

Fraction Fraction::operator-(const Fraction &frac) {
    Fraction res = *this;
    res.numerator *= frac.denominator;
    res.denominator *= frac.denominator;
    res.numerator -= frac.numerator * this->denominator;
    res.simplify();
    return res;
}

Fraction Fraction::operator-(int sub) {
    Fraction res = *this;
    res.numerator -= sub * this->denominator;
    res.simplify();
    return res;
}


bool Fraction::operator<(const Fraction &frac) {
    int numerator1 = this->numerator * frac.denominator;
    int numerator2 = this->denominator * frac.numerator;
    return numerator1 < numerator2;
}

bool Fraction::operator<=(const Fraction &frac) {
    int numerator1 = this->numerator * frac.denominator;
    int numerator2 = this->denominator * frac.numerator;
    return numerator1 <= numerator2;
}

bool Fraction::operator==(const Fraction &frac) {
    int numerator1 = this->numerator * frac.denominator;
    int numerator2 = this->denominator * frac.numerator;
    return numerator1 == numerator2;
}

bool Fraction::operator!=(const Fraction &frac) {
    int numerator1 = this->numerator * frac.denominator;
    int numerator2 = this->denominator * frac.numerator;
    return numerator1 != numerator2;
}

bool Fraction::operator>(const Fraction &frac) {
    int numerator1 = this->numerator * frac.denominator;
    int numerator2 = this->denominator * frac.numerator;
    return numerator1 > numerator2;
}

bool Fraction::operator>=(const Fraction &frac) {
    int numerator1 = this->numerator * frac.denominator;
    int numerator2 = this->denominator * frac.numerator;
    return numerator1 >= numerator2;
}

Fraction::operator double() {
    this->simplify();
    return 1.00 * numerator / denominator;
}

Fraction::operator std::string() {
    stringstream ss;
    string str;
    ss << *this;
    ss >> str;
    return str;
}

ostream &operator<<(std::ostream &output, const Fraction &frac) {
    cout << frac.numerator << '/' << frac.denominator;
    return cout;
}

istream &operator>>(istream &in, Fraction &frac) {
    char ch;
    while (1) {
        cin >> frac.numerator >> ch >> frac.denominator;
        if (frac.denominator == 0)
            cerr << "分母为0, 请重新输入\n";
        else if (ch != '/')
            cerr << "格式错误 应该形如m/n! 请重新输入\n";
        else
            break;
    }
    frac.simplify();
    return cin;
}

Fraction::Fraction(const string &str) {
    stringstream ss;
    char dot;
    int integer_part, decimal_part, radix = 1, temp;
    ss << str;
    ss >> integer_part >> dot >> decimal_part;
    if (dot == '.') {
        temp = decimal_part;
        while (temp > 0) {
            temp /= 10;
            integer_part *= 10;
            radix *=10;
        }
        this->numerator = integer_part + decimal_part;
        this->denominator = radix;
        this->simplify();
    } else {
        cerr << "Fraction::Fraction(const string &str) str格式错误 应该形如xx.xxx!\n";
    }
}
