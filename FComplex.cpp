#include "FComplex.h"

FComplex::FComplex() : euler(false), imag(0), real(0) {}
FComplex::FComplex(double v) : euler(false), imag(0), real(v) {}
FComplex::FComplex(double r, double i, bool eulerform = false) : euler(eulerform) {
    set(r, i);
}
FComplex::FComplex(const FComplex& z) {
    real = z.real;
    imag = z.imag;
    setEuler(z.euler);
}
FComplex::FComplex(const complex<double>& z) : euler(false) {
    real = z.real();
    imag = z.imag();
}

void FComplex::set(double r, double i) {
    if (euler) {
        real = r * cos(i);
        imag = r * sin(i);
    }
    else {
        real = r;
        imag = i;
    }
}
void FComplex::setEuler(bool e) {
    euler = e;
}

double FComplex::Real() const {}
double FComplex::Imag() const {}
double FComplex::Fi() const {}
double FComplex::R() const {}

FComplex& FComplex::operator=(const FComplex&) {}

FComplex& FComplex::operator+=(const FComplex&) {}
FComplex& FComplex::operator-=(const FComplex&) {}
FComplex& FComplex::operator*=(const FComplex&) {}
FComplex& FComplex::operator/=(const FComplex&) {}

FComplex FComplex::operator+(const FComplex&) const {}
FComplex FComplex::operator-(const FComplex&) const {}
FComplex FComplex::operator*(const FComplex&) const {}
FComplex FComplex::operator/(const FComplex&) const {}

FComplex FComplex::pow(const FComplex&) const {}

string FComplex::ToString() const {
    if (euler) {
        string s = to_string(R());
        s.append("e^(i");
        s.append(to_string(Fi()));
        s.append(")");
        return s;
    }
    if (imag==0)
        return to_string(real);
    string s = "(";
    s.append(to_string(real));
    s.push_back('+');
    s.append(to_string(imag));
    s.append("i)");
    return s;
}