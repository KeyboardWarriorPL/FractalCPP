#include "Polynomial.h"

Polynomial::Polynomial() : factors(vector<FComplex>{}) {}
Polynomial::Polynomial(const Polynomial& p) : Polynomial() {
    factors.reserve(p.factors.size());
    for (auto i : p.factors)
        factors.push_back(i);
}
Polynomial::Polynomial(vector<FComplex> v) : factors(v) {}
Polynomial::Polynomial(const FComplex* a, size_t l) : factors({}) {
    factors.reserve(l);
    for (size_t i = 0; i < l; i++) {
        factors.push_back(a[i]);
    }
}
Polynomial::Polynomial(const FComplex a) : factors({}) {
    factors.push_back(a);
}
Polynomial::Polynomial(string s) {
    fromString(s);
}
Polynomial::~Polynomial() {
    delete [] factors.data();
    factors.clear();
}

FComplex Polynomial::calc(const FComplex x) const {
    FComplex sum = 0;
    for (size_t i = 0; i < factors.size(); i++) {
        sum += factors.at(i) * x.pow(i);
    }
    return sum;
}
FComplex Polynomial::operator()(const FComplex x) const {
    return calc(x);
}
Polynomial& Polynomial::operator+=(const Polynomial& p) {
    for (size_t i = 0; i < p.factors.size(); i++) {
        if (factors.size() > i)
            factors.at(i) += p.factors.at(i);
        else
            factors.push_back(p.factors.at(i));
    }
    return *this;
}
Polynomial& Polynomial::operator-=(const Polynomial& p) {
    return *this += p * (-1);
}
Polynomial Polynomial::operator+(const Polynomial& p) const {
    Polynomial sum{*this};
    for (int i = 0; i < p.factors.size(); i++) {
        if (sum.factors.size() > i)
            sum.factors.at(i) += p.factors.at(i);
        else
            sum.factors.push_back(p.factors.at(i));
    }
    return sum;
}
Polynomial Polynomial::operator-(const Polynomial& p) const {
    return (*this) + (p * (-1));
}

Polynomial& Polynomial::operator*=(const FComplex v) {
    for (int i = 0; i < factors.size(); i++) {
        factors.at(i) *= v;
    }
    return *this;
}
Polynomial& Polynomial::operator+=(const FComplex v) {
    if (factors.size() > 0)
        factors.at(0) += v;
    else
        factors.push_back(v);
    return *this;
}
Polynomial& Polynomial::operator-=(const FComplex v) {
    if (factors.size() > 0)
        factors.at(0) -= v;
    else
        factors.push_back(v*(-1));
    return *this;
}
Polynomial Polynomial::operator*(const FComplex v) const {
    Polynomial mul{*this};
    for (size_t i = 0; i < mul.factors.size(); i++)
        mul.factors.at(i) *= v;
    return mul;
}
Polynomial Polynomial::operator+(const FComplex v) const {
    Polynomial sum{*this};
    if (sum.factors.size() > 0)
        sum.factors.at(0) += v;
    else
        sum.factors.push_back(v);
    return sum;
}
Polynomial Polynomial::operator-(const FComplex v) const {
    return (*this) + (v*(-1));
}

string Polynomial::ToString() const {
    if (factors.empty())
        return "";
    string s;
    for (int i = factors.size()-1; i > 0; i++) {
        s.append(factors.at(i).ToString());
        s.append("z^");
        s.append(to_string(i));
        s.append(" + ");
    }
    s.append(factors.at(0).ToString());
    return s;
}
void Polynomial::fromString(const string) {
    // external lib? hell no!
}