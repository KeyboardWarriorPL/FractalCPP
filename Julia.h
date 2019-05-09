#pragma once
#include "Polynomial.h"
#include "FComplex.h"
#include <QColor>
#include <QImage>

class Julia {
    int size;
    double scale, threshold;
    Polynomial f, g;

    QColor process(int, const FComplex&, const FComplex&) const;
    QColor getColor(double) const;

    public:
    Julia();
    Julia(int, double);
    Julia(int, double, const Polynomial&, const Polynomial&);
    Julia(const Julia&) = delete;
    ~Julia() = default;

    void set(const Polynomial&, const Polynomial&);
    void rescale(double);
    QImage calc(int, const FComplex&) const;
};