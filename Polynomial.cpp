#include "Polynomial.h"

Polynomial::Polynomial() {}
Polynomial::Polynomial(Polynomial&) {}
Polynomial::Polynomial(vector<CxDouble>) {}
Polynomial::Polynomial(CxDouble*) {}
Polynomial::~Polynomial() {}

CxDouble Polynomial::calc(CxDouble) {}
CxDouble Polynomial::operator()(CxDouble) {}
Polynomial& Polynomial::operator+=(Polynomial&) {}
Polynomial& Polynomial::operator-=(Polynomial&) {}
Polynomial& Polynomial::operator+(Polynomial&) {}
Polynomial& Polynomial::operator-(Polynomial&) {}

string Polynomial::ToString() {}
void Polynomial::fromString(string) {
}