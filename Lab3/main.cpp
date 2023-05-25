#include <iostream>
#include "fraction.h"

using namespace std;

int main() {
    string str;
    cout << "请输入一个形如1.414的小数:" << endl;
    cin >> str;
    Fraction frac1(str);
    cout << "从字符串转化得到:" << frac1 << endl;

    int numerator, denominator;
    cout << "请输入两个非零整数:" << endl;
    cin >> numerator >> denominator;
    Fraction frac2(numerator, denominator);
    cout << "从两个整数构造得到:" << frac2 << endl;

    cout << "请以形如2/3格式直接输入一个分数:" << endl;
    Fraction frac3;
    cin >> frac3;
    cout << "从输入流中直接读取得到:" << frac3 << endl;

    Fraction frac4;
    cout << "默认构造函数的结果是:" << frac4 << endl;

    Fraction frac5(frac1);
    cout << "拷贝构造第一个分数的结果是:" << frac5 << endl;
    cout << "第一个分数转换为double的结果是:" << double(frac1) << endl;
    cout << "第一个分数转换为string的结果是:" << string(frac1) << endl;

    cout << "下面是对四则运算的重载:" << endl;
    cout << frac2 << " + " << frac3 << "=" << frac2+frac3 << endl;
    cout << frac2 << " - " << frac3 << "=" << frac2-frac3 << endl;
    cout << frac2 << " * " << frac3 << "=" << frac2*frac3 << endl;
    cout << frac2 << " / " << frac3 << "=" << frac2/frac3 << endl;
    cout << "下面是对关系运算的重载:" << endl;
    cout << frac2 << " >  " << frac3 << "=" << (frac2>frac3) << endl;
    cout << frac2 << " >= " << frac3 << "=" << (frac2>=frac3) << endl;
    cout << frac2 << " == " << frac3 << "=" << (frac2==frac3) << endl;
    cout << frac2 << " != " << frac3 << "=" << (frac2!=frac3) << endl;
    cout << frac2 << " <  " << frac3 << "=" << (frac2<frac3) << endl;
    cout << frac2 << " <= " << frac3 << "=" << (frac2<=frac3) << endl;
}
