#include "FComplex.h"

FComplex::FComplex() : real(0), imag(0) {}
FComplex::FComplex(string s) : FComplex() {
    int pos = -1, i = -1;
    if (s[0] == '(')
        s = s.substr(1, s.size()-2);
    pos = s.find('-');
    if (pos >= 0)
        s.insert(pos, "+");
    pos = s.find('+');
    if (pos < 0) {
        i = s.find('i');
        if (i < 0)
            real = atof(s.data());
        else {
            if (s.size() == 1)
                imag = 1;
            else
                imag = atof(s.substr(0, s.size()-1).data());
        }
    }
    else {
        real = atof(s.substr(0,pos).data());
        imag = atof(s.substr(pos+1, s.size()-2-pos).data());
    }
}
FComplex::FComplex(double v) : real(v), imag(0) {}
FComplex::FComplex(double r, double i, bool euler) {
    set(r, i, euler);
}
FComplex::FComplex(const FComplex& z) {
    real = z.Real();
    imag = z.Imag();
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
    mul.real = real * z.real - imag * z.imag;
    mul.imag = real * z.imag + z.real * imag;
    return mul;
}
FComplex FComplex::operator/(const FComplex& z) const {
    FComplex mul{*this};
    mul.real = (real * z.real + imag * z.imag) / pow(z.R(), 2);
    mul.imag = (imag * z.real - real * z.imag) / pow(z.R(), 2);
    return mul;
}

FComplex FComplex::power(const FComplex& z) const {
    if (R() == 0)
        return 0;
    if (z.R() == 0)
        return 1;
    FComplex pwr;
    pwr.set( exp(z.real*log(R()) - Fi()*z.imag), z.imag*log(R()) + Fi()*z.real, true);
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
    if (imag >= 0)
        s.push_back('+');
    s.append(to_string(imag));
    s.append("i)");
    return s;
}

FComplex::operator string() {
    return ToString();
}