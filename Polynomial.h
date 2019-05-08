#pragma once
#include <complex>
#include <vector>
#include <string>

typedef complex<double> CxDouble;

using namespace std;

class Polynomial {
    vector<CxDouble> factors;

    void fromString(const string);
    string complexStr(const CxDouble) const;

    public:
    Polynomial();
    Polynomial(const Polynomial&);
    Polynomial(vector<CxDouble>);
    Polynomial(const CxDouble*);
    Polynomial(string);
    ~Polynomial();

    CxDouble calc(const CxDouble) const;
    CxDouble operator()(const CxDouble) const;
    Polynomial& operator+=(const Polynomial&);
    Polynomial& operator-=(const Polynomial&);
    Polynomial operator+(const Polynomial&) const;
    Polynomial operator-(const Polynomial&) const;

    Polynomial& operator*=(const CxDouble);
    Polynomial& operator+=(const CxDouble);
    Polynomial& operator-=(const CxDouble);
    Polynomial operator*(const CxDouble) const;
    Polynomial operator+(const CxDouble) const;
    Polynomial operator-(const CxDouble) const;

    string ToString() const;
};