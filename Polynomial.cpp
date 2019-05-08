#include "Polynomial.h"

Polynomial::Polynomial() : factors(vector<CxDouble>{}) {}
Polynomial::Polynomial(const Polynomial& p) : Polynomial() {
    factors.reserve(p.factors.size());
    for (auto i : p.factors)
        factors.push_back(i);
}
Polynomial::Polynomial(vector<CxDouble> v) : factors(v) {}
Polynomial::Polynomial(const CxDouble* a) : factors({a}) {}
Polynomial::Polynomial(string s) {
    fromString(s);
}
Polynomial::~Polynomial() {
    delete [] factors.data();
    factors.clear();
}

CxDouble Polynomial::calc(const CxDouble x) const {
    CxDouble sum = 0;
    for (int i = 0; i < factors.size(); i++) {
        sum += factors[i] * pow(x, i);
    }
    return sum;
}
CxDouble Polynomial::operator()(const CxDouble x) const {
    return calc(x);
}
Polynomial& Polynomial::operator+=(const Polynomial& p) {
    for (int i = 0; i < p.factors.size(); i++) {
        if (factors.size() > i)
            factors[i] += p.factors[i];
        else
            factors.push_back(p.factors[i]);
    }
    return *this;
}
Polynomial& Polynomial::operator-=(const Polynomial& p) {
    return *this += p * (-1);
}
Polynomial Polynomial::operator+(const Polynomial& p) const {
    Polynomial sum{this};
    for (int i = 0; i < p.factors.size(); i++) {
        if (sum.factors.size() > i)
            sum.factors[i] += p.factors[i];
        else
            sum.factors.push_back(p.factors[i]);
    }
    return sum;
}
Polynomial Polynomial::operator-(const Polynomial& p) const {
    return (*this) + (p * (-1));
}

Polynomial& Polynomial::operator*=(const CxDouble v) {
    for (int i = 0; i < factors.size(); i++) {
        factors[i] *= v;
    }
    return *this;
}
Polynomial& Polynomial::operator+=(const CxDouble v) {
    if (factors.size() > 0)
        factors[0] += v;
    else
        factors.push_back(v);
    return *this;
}
Polynomial& Polynomial::operator-=(const CxDouble v) {
    if (factors.size() > 0)
        factors[0] -= v;
    else
        factors.push_back(-v);
    return *this;
}
Polynomial Polynomial::operator*(const CxDouble v) const {
    Polynomial mul{this};
    for (int i = 0; i < mul.factors.size(); i++)
        mul.factors[i] *= v;
    return mul;
}
Polynomial Polynomial::operator+(const CxDouble v) const {
    Polynomial sum{this};
    if (sum.factors.size() > 0)
        sum.factors[0] += v;
    else
        sum.factors.push_back(v);
    return sum;
}
Polynomial Polynomial::operator-(const CxDouble v) const {
    return (*this) + (-v);
}

string Polynomial::complexStr(const CxDouble v) const {
    if (v.imag()==0)
        return to_string(v.real());
    string s = "(";
    s.append(to_string(v.real()));
    s.push_back('+');
    s.append(to_string(v.imag()));
    s.append("i)");
    return s;
}
string Polynomial::ToString() const {
    if (factors.empty())
        return "";
    string s;
    for (int i = factors.size()-1; i > 0; i++) {
        s.append(complexStr(factors[i]));
        s.append("z^");
        s.append(to_string(i));
        s.append(" + ");
    }
    s.append(complexStr(factors[0]));
}
void Polynomial::fromString(const string) {
    // external lib?
}