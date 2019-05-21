#pragma once
#include <math.h>
#include <string>
#include <complex>

using namespace std;

/// Complex number implementation supporting Euler form parameters
class FComplex {
    double real, imag;

    public:
    FComplex();
    FComplex(string);
    FComplex(double);
    FComplex(double, double, bool euler=false);
    FComplex(const FComplex&);
    FComplex(const complex<double>&);
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

    string ToString(bool euler=false) const;
    operator string();
};