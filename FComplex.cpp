#include "FComplex.h"

FComplex::FComplex() : real(0), imag(0) {}
FComplex::FComplex(const char* text) : FComplex() {
    string s{text};
    size_t pos = -1, i = -1;
    if (s[0] == '(')
        s = s.substr(1, s.size()-2);
    pos = s.find('-');
    if (pos != string::npos && pos > 0)
        s.insert(pos, "+");
    pos = s.find('+');
    if (pos == string::npos) {
        i = s.find('i');
        if (i == string::npos)
            real = atof(s.data());
        else {
            if (s.size() == 1)
                imag = 1;
            else
                imag = atof(s.substr(0, s.size()-2).data());
        }
    }
    else {
        real = atof(s.substr(0,pos).data());
        imag = atof(s.substr(pos+1,s.size()-pos-2).data());
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

bool FComplex::operator==(const FComplex& z) {
    return z.real == real && z.imag == imag;
}
bool FComplex::operator!=(const FComplex& z) {
    return !(*this == z);
}

FComplex& FComplex::operator=(const FComplex& z) {
    real = z.Real();
    imag = z.Imag();
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
    double newreal;
    newreal = real * z.real - imag * z.imag;
    imag = real * z.imag + z.real * imag;
    real = newreal;
    return *this;
}
FComplex& FComplex::operator/=(const FComplex& z) {
    double rsq = pow(z.real, 2.0) + pow(z.imag, 2.0), newreal;
    newreal = (real * z.real + imag * z.imag) / rsq;
    imag = (imag * z.real - real * z.imag) / rsq;
    real = newreal;
    return *this;
}

FComplex FComplex::operator+(const FComplex& z) const {
    FComplex sum{*this};
    sum += z;
    return sum;
}
FComplex FComplex::operator-(const FComplex& z) const {
    FComplex sum{*this};
    sum -= z;
    return sum;
}
FComplex FComplex::operator*(const FComplex& z) const {
    FComplex mul{*this};
    mul *= z;
    return mul;
}
FComplex FComplex::operator/(const FComplex& z) const {
    FComplex mul{*this};
    mul /= z;
    return mul;
}

FComplex FComplex::power(const FComplex& z) const {
    if (z.R() == 0)
        return 1;
    if (R() == 0)
        return 0;
    FComplex pwr;
    pwr.set(exp(z.real*log(R()) - Fi()*z.imag), z.imag*log(R()) + Fi()*z.real, true);
    // apply sign correction if negative
    if (real < 0)
        pwr *= pow(-1.0, z.R());
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