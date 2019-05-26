#pragma once
#include "FComplex.h"
#include <string>
#include <regex>

using namespace std;

/// Polynomial implementation with basic from string conversion
class Polynomial {
    size_t size;
    FComplex *factors;

    void fromString(const string&);

    public:
    Polynomial();
    Polynomial(const Polynomial&);
    Polynomial(FComplex*);
    Polynomial(const initializer_list<FComplex>);
    explicit Polynomial(const char*);
    ~Polynomial();

    Polynomial& push_back(const FComplex&);
    void set(const FComplex&, size_t degree);
    FComplex get(size_t degree) const;
    void resize(size_t nsize);

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
    bool operator==(const Polynomial&);
    bool operator!=(const Polynomial&);

    string ToString() const;
    operator string();

    FComplex* begin();
    FComplex* end();
};