#include "Polynomial.h"

Polynomial::Polynomial() : factors(new vector<FComplex>{}) {}
Polynomial::Polynomial(const Polynomial& p) : Polynomial() {
    factors->reserve(p.factors->size());
    for (auto i : *p.factors)
        factors->push_back(i);
}
Polynomial::Polynomial(vector<FComplex> *v) : factors(v) {}
Polynomial::Polynomial(const initializer_list<double> a) : factors(new vector<FComplex>{}) {
    factors->reserve(a.size());
    for (auto i : a) {
        factors->push_back(i);
    }
}
Polynomial::Polynomial(const FComplex& a) : factors(new vector<FComplex>{}) {
    factors->reserve(2);
    factors->push_back(a);
}
Polynomial::Polynomial(string s) {
    fromString(s);
}
Polynomial::~Polynomial() {
    delete [] factors->data();
    factors->clear();
}

Polynomial& Polynomial::push_back(const FComplex& z) {
    factors->push_back(z);
    return *this;
}
void Polynomial::set(const FComplex& z, size_t degree) {
    if (degree >= factors->size()) {
        factors->reserve(degree+1);
        while (degree >= factors->size())
            factors->push_back({});
    }
    factors->assign(degree, z);
}

FComplex Polynomial::calc(const FComplex& x) const {
    FComplex sum = 0;
    for (auto i = 0; i < factors->size(); i++) {
        sum += factors->at(i) * x.power(i);
    }
    return sum;
}
FComplex Polynomial::operator()(const FComplex& x) const {
    return calc(x);
}
Polynomial& Polynomial::operator+=(const Polynomial& p) {
    for (auto i = 0; i < p.factors->size(); i++) {
        if (factors->size() > i)
            factors->at(i) += p.factors->at(i);
        else
            factors->push_back(p.factors->at(i));
    }
    return *this;
}
Polynomial& Polynomial::operator-=(const Polynomial& p) {
    return *this += p * (-1);
}
Polynomial Polynomial::operator+(const Polynomial& p) const {
    Polynomial sum{*this};
    for (auto i = 0; i < p.factors->size(); i++) {
        if (sum.factors->size() > i)
            sum.factors->at(i) += p.factors->at(i);
        else
            sum.factors->push_back(p.factors->at(i));
    }
    return sum;
}
Polynomial Polynomial::operator-(const Polynomial& p) const {
    return (*this) + (p * (-1));
}

Polynomial& Polynomial::operator*=(const FComplex& v) {
    for (auto i = 0; i < factors->size(); i++) {
        factors->at(i) *= v;
    }
    return *this;
}
Polynomial& Polynomial::operator+=(const FComplex& v) {
    if (factors->size() > 0)
        factors->at(0) += v;
    else
        factors->push_back(v);
    return *this;
}
Polynomial& Polynomial::operator-=(const FComplex& v) {
    if (factors->size() > 0)
        factors->at(0) -= v;
    else
        factors->push_back(v*(-1));
    return *this;
}
Polynomial Polynomial::operator*(const FComplex& v) const {
    Polynomial mul{*this};
    for (auto i = 0; i < mul.factors->size(); i++)
        mul.factors->at(i) *= v;
    return mul;
}
Polynomial Polynomial::operator+(const FComplex& v) const {
    Polynomial sum{*this};
    if (sum.factors->size() > 0)
        sum.factors->at(0) += v;
    else
        sum.factors->push_back(v);
    return sum;
}
Polynomial Polynomial::operator-(const FComplex& v) const {
    return (*this) + (v*(-1));
}

string Polynomial::ToString() const {
    if (factors->empty())
        return "";
    string s;
    for (auto i = factors->size()-1; i > 0; i++) {
        s.append(factors->at(i).ToString());
        s.append("z^");
        s.append(to_string(i));
        s.append(" + ");
    }
    s.append(factors->at(0).ToString());
    return s;
}
void Polynomial::fromString(const string) {
    // external lib? hell no! or regex maybe
}