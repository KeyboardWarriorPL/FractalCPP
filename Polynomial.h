#pragma once
#include <complex>
#include <vector>
#include <string>

typedef complex<double> CxDouble;

using namespace std;

class Polynomial {
    vector<CxDouble> factors;

    void fromString(string);

    public:
    Polynomial();
    Polynomial(Polynomial&);
    Polynomial(vector<CxDouble>);
    Polynomial(CxDouble*);
    ~Polynomial();

    CxDouble calc(CxDouble);
    CxDouble operator()(CxDouble);
    Polynomial& operator+=(Polynomial&);
    Polynomial& operator-=(Polynomial&);
    Polynomial& operator+(Polynomial&);
    Polynomial& operator-(Polynomial&);

    string ToString();
};