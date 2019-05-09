#pragma once
#include "Polynomial.h"
#include "FComplex.h"
#include <QColor>
#include <QImage>

class Julia {
    double scale, threshold;
    Polynomial f, g;

    QColor process(int, const FComplex&, const FComplex&) const;
    QColor getColor(double) const;

    public:
    Julia();
    Julia(double);
    Julia(double, const Polynomial&, const Polynomial&);
    Julia(const Julia&) = delete;
    ~Julia() = default;

    void set(const Polynomial&, const Polynomial&);
    void rescale(double);
    QImage& paint(QImage&, int, const FComplex&) const;
};