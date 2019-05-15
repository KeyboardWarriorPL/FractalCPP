#include "FComplex.h"

FComplex::FComplex() : real(0), imag(0) {}
FComplex::FComplex(string s) {
    size_t pos = 0;
    s = s.substr(1, s.size()-2);
    pos = s.find('-');
    pos = s.find('+');
}
FComplex::FComplex(double v) : real(v), imag(0) {}
FComplex::FComplex(double r, double i, bool euler) {
    set(r, i, euler);
}
FComplex::FComplex(const FComplex& z) {
    real = z.real;
    imag = z.imag;
}
FComplex::FComplex(const complex<double>& z) {
    real = z.real();
    imag = z.imag();
}

FComplex& FComplex::set(double r, double i, bool euler) {
    if (euler) {
        real = r * cos(i);
        imag = r * sin(i);
    }
    else {
        real = r;
        imag = i;
    }
    return *this;
}

double FComplex::Real() const {
    return real;
}
double FComplex::Imag() const {
    return imag;
}
double FComplex::Fi() const {
    return atan(imag / real);
}
double FComplex::R() const {
    return sqrt(pow(real, 2) + pow(imag, 2));
}

FComplex& FComplex::operator=(const FComplex& z) {
    real = z.real;
    imag = z.imag;
    return *this;
}

FComplex& FComplex::operator+=(const FComplex& z) {
    real += z.real;
    imag += z.imag;
    return *this;
}
FComplex& FComplex::operator-=(const FComplex& z) {
    real -= z.real;
    imag -= z.imag;
    return *this;
}
FComplex& FComplex::operator*=(const FComplex& z) {
    real = real * z.real - imag * z.imag;
    imag = real * z.imag + z.real * imag;
    return *this;
}
FComplex& FComplex::operator/=(const FComplex& z) {
    real = (real * z.real + imag * z.imag) / pow(z.R(), 2);
    imag = (imag * z.real - real * z.imag) / pow(z.R(), 2);
    return *this;
}

FComplex FComplex::operator+(const FComplex& z) const {
    FComplex sum{*this};
    sum.real += z.real;
    sum.imag += z.imag;
    return sum;
}
FComplex FComplex::operator-(const FComplex& z) const {
    FComplex sum{*this};
    sum.real -= z.real;
    sum.imag -= z.imag;
    return sum;
}
FComplex FComplex::operator*(const FComplex& z) const {
    FComplex mul{*this};
    mul.real = mul.real * z.real - mul.imag * z.imag;
    mul.imag = mul.real * z.imag + z.real * mul.imag;
    return mul;
}
FComplex FComplex::operator/(const FComplex& z) const {
    FComplex mul{*this};
    mul.real = (mul.real * z.real + mul.imag * z.imag) / pow(z.R(), 2);
    mul.imag = (mul.imag * z.real - mul.real * z.imag) / pow(z.R(), 2);
    return mul;
}

FComplex FComplex::power(const FComplex& z) const {
    if (z.R() == 0)
        return FComplex{1};
    FComplex pwr = FComplex{log(R()), Fi()} * z;
    pwr.set(exp(pwr.real), pwr.imag, true);
    return pwr;
}

string FComplex::ToString(bool euler) const {
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