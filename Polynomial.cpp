#include "Polynomial.h"
#include <iostream>

Polynomial::Polynomial() : factors(new vector<FComplex>{}) {}
Polynomial::Polynomial(const Polynomial& p) : Polynomial() {
    factors->reserve(p.factors->size());
    for (auto i : *p.factors)
        factors->push_back(i);
}
Polynomial::Polynomial(vector<FComplex> *v) : factors(v) {}
Polynomial::Polynomial(const initializer_list<FComplex> a) : factors(new vector<FComplex>{}) {
    factors->reserve(a.size());
    for (auto i : a)
        factors->push_back(i);
}
Polynomial::Polynomial(const string& s) : Polynomial() {
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
    factors->at(degree) = z;
}

FComplex Polynomial::calc(const FComplex& x) const {
    FComplex sum = 0;
    for (int i = 0; i < factors->size(); i++) {
        sum += factors->at(i) * x.power(i);
    }
    return sum;
}
FComplex Polynomial::operator()(const FComplex& x) const {
    return calc(x);
}
Polynomial& Polynomial::operator+=(const Polynomial& p) {
    for (int i = 0; i < p.factors->size(); i++) {
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
    for (int i = 0; i < p.factors->size(); i++) {
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
    for (int i = 0; i < factors->size(); i++) {
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
    for (int i = 0; i < mul.factors->size(); i++)
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

Polynomial& Polynomial::operator=(const Polynomial& p) {
    delete factors;
    factors = new vector<FComplex>;
    factors->reserve(p.factors->size());
    for (auto i : *p.factors)
        factors->push_back(i);
    return *this;
}

string Polynomial::ToString() const {
    if (factors->empty())
        return "";
    string s;
    for (int i = factors->size()-1; i > 0; i--) {
        if (factors->at(i).R()==0)
            continue;
        s.append(factors->at(i).ToString());
        s.append("z^");
        s.append(to_string(i));
        s.append(" + ");
    }
    s.append(factors->at(0).ToString());
    return s;
}
void Polynomial::fromString(const string& src) {
    string cpy;
    cpy.reserve(src.size());
    for (auto c : src) {
        if (c == 'x')
            cpy.push_back('z');
        else if (c == '-') {
            cpy.push_back('+');
            cpy.push_back('-');
        }
        else if (c != ' ')
            cpy.push_back(c);
    }
    regex rgx{"[0-9i().-+]*z[^][0-9]+"};
    smatch mch;
    for (auto z : mch) {
        cout << z << endl;
    }
    regex_search(cpy, mch, rgx);
}
/*void Polynomial::fromString(const string& src) {
    string cpy;
    cpy.reserve(src.size());
    for (auto c : src) {
        if (c == 'x')
            cpy.push_back('z');
        else if (c == '-') {
            cpy.push_back('+');
            cpy.push_back('-');
        }
        else if (c != ' ')
            cpy.push_back(c);
    }
    int pos = 0, plus = 0;
    vector<string> parts;
    while (plus > -1 && pos < cpy.size()) {
        plus = cpy.find("+", pos);
        if (plus < 0)
            parts.push_back(cpy.substr(pos));
        else {
            parts.push_back(cpy.substr(pos, plus-pos));
            pos = plus+1;
        }
    }
    int degree;
    for (auto s : parts) {
        if (s.size() <= 0)
            continue;
        degree = 0;
        pos = s.find('^');
        if (pos >= 0)
            degree = atoi(s.substr(pos+1).data());
        pos = s.find('z');
        if (pos >= 0) {
            if (degree <= 0)
                degree++;
            if (pos > 0)
                set(FComplex{s.substr(0, pos)}, degree);
            else
                set(1, degree);
        }
        else
            set(FComplex{s}, degree);
    }
}
*/

Polynomial::operator string() {
    return ToString();
}

vector<FComplex>::iterator Polynomial::begin() {
    return factors->begin();
}
vector<FComplex>::iterator Polynomial::end() {
    return factors->end();
}