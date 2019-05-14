#pragma once
#include <math.h>
#if __has_include(<QApplication>)
#include <QString>
#else
#include <QtCore/QString>
#endif

using namespace std;

/// a better implementation of complex number
class FComplex {
    double real, imag;

    public:
    FComplex();
    FComplex(double);
    FComplex(double, double, bool euler=false);
    FComplex(const FComplex&);
    ~FComplex() = default;

    FComplex& set(double, double, bool euler=false);

    double Real() const;
    double Imag() const;
    double Fi() const;
    double R() const;

    FComplex& operator=(const FComplex&);

    FComplex& operator+=(const FComplex&);
    FComplex& operator-=(const FComplex&);
    FComplex& operator*=(const FComplex&);
    FComplex& operator/=(const FComplex&);

    FComplex operator+(const FComplex&) const;
    FComplex operator-(const FComplex&) const;
    FComplex operator*(const FComplex&) const;
    FComplex operator/(const FComplex&) const;

    FComplex power(const FComplex&) const;

    QString ToString(bool euler=false) const;
};