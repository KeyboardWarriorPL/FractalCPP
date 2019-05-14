#pragma once
#include "Polynomial.h"
#include "FComplex.h"
#include <QtGui/QImage>

class Julia {
    double scale, threshold;
    Polynomial f, g;

    int process(int, const FComplex&, const FComplex&) const;
    int getColor(double) const;

    public:
    Julia();
    Julia(double);
    Julia(double, const Polynomial&, const Polynomial&);
    Julia(const Julia&) = delete;
    ~Julia() = default;

    string ToString() const;
    void set(const Polynomial&, const Polynomial&);
    void rescale(double);
    QImage& paint(QImage&, int, const FComplex&) const;
};