#pragma once
#include <math.h>
#include <string>
#include <complex>

using namespace std;

/// A better implementation of complex number
class FComplex {
    double real, imag;
    // euler input flag
    bool euler;

    public:
    FComplex();
    FComplex(double);
    FComplex(double, double, bool);
    FComplex(const FComplex&);
    FComplex(const complex<double>&);

    void set(double, double);
    void setEuler(bool);

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

    FComplex pow(const FComplex&) const;

    string ToString() const;
};