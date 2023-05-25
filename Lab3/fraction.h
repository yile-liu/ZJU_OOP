#ifndef FRAC_FRACTION_H
#define FRAC_FRACTION_H
#include <string>

class Fraction {
public:
    Fraction() {
        numerator = 1;
        denominator = 1;
    }

    Fraction(int numerator, int denominator);

    Fraction(const Fraction &frac);

    explicit Fraction(const std::string &str);

    Fraction operator+(int add);

    Fraction operator+(const Fraction &frac);

    Fraction operator-(const Fraction &frac);

    Fraction operator-(int sub);

    Fraction operator*(const Fraction &frac);

    Fraction operator*(int mul);

    Fraction operator/(const Fraction &frac);

    Fraction operator/(int div);

    bool operator<(const Fraction &frac);

    bool operator<=(const Fraction &frac);

    bool operator==(const Fraction &frac);

    bool operator!=(const Fraction &frac);

    bool operator>(const Fraction &frac);

    bool operator>=(const Fraction &frac);

    explicit operator std::string();

    explicit operator double();

    friend std::istream &operator>>(std::istream &input, Fraction &frac);

    friend std::ostream &operator<<(std::ostream &output, const Fraction &frac);


private:
    int numerator;
    int denominator;
    void simplify();
};

#endif //FRAC_FRACTION_H
