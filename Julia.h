#pragma once
#include "Polynomial.h"
#include "FComplex.h"
#if __has_include(<QApplication>)
#include <QImage>
#else
#include <QtGui/QImage>
#endif
#include <iostream>

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

    void set(const Polynomial&, const Polynomial&);
    void rescale(double);
    QImage& paint(QImage&, int, const FComplex&) const;
};