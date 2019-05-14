#pragma once
#include "FComplex.h"
#include <vector>
#include <string>
#include <regex>

using namespace std;

class Polynomial {
    vector<FComplex> *factors;

    void fromString(const string&);

    public:
    Polynomial();
    Polynomial(const Polynomial&);
    Polynomial(vector<FComplex>*);
    Polynomial(const initializer_list<FComplex>);
    Polynomial(const string&);
    ~Polynomial();

    Polynomial& push_back(const FComplex&);
    void set(const FComplex&, size_t degree);

    FComplex calc(const FComplex&) const;
    FComplex operator()(const FComplex&) const;
    Polynomial& operator+=(const Polynomial&);
    Polynomial& operator-=(const Polynomial&);
    Polynomial operator+(const Polynomial&) const;
    Polynomial operator-(const Polynomial&) const;

    Polynomial& operator*=(const FComplex&);
    Polynomial& operator+=(const FComplex&);
    Polynomial& operator-=(const FComplex&);
    Polynomial operator*(const FComplex&) const;
    Polynomial operator+(const FComplex&) const;
    Polynomial operator-(const FComplex&) const;

    Polynomial& operator=(const Polynomial&);

    string ToString() const;
};