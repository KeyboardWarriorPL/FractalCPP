#pragma once
#include "FComplex.h"
#if __has_include(<QApplication>)
#include <QVector>
#include <QString>
#else
#include <QtCore/QVector>
#include <QtCore/QString>
#endif

using namespace std;

class Polynomial {
    QVector<FComplex> factors;

    public:
    Polynomial();
    Polynomial(const Polynomial&);
    Polynomial(QVector<FComplex>);
    Polynomial(const initializer_list<double>);
    Polynomial(const FComplex);
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

    QString ToString() const;
};