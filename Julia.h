#pragma once
#include "Polynomial.h"
#include "FComplex.h"
#include <QtGui/QImage>
#include <QtGui/QProgressBar>

/// Julia set generator class
class Julia {
    static const double XRANGE, YRANGE;
    double scale, offset[2];
    int cmap, mapshift;
    Polynomial f, g;

    int process(int, const FComplex&, const FComplex&) const;
    int getColor(double) const;
    int reshiftMap(int, int) const;

    public:
    Julia();
    Julia(double);
    Julia(double, const Polynomial&, const Polynomial&);
    Julia(const Julia&) = delete;
    ~Julia() = default;

    string ToString() const;
    void set(const Polynomial&, const Polynomial&);
    void colormap(int, int);
    void reposition(double, double, bool set=false);
    void rescale(double);
    void paint(QImage&, int, const FComplex&, QProgressBar* progress=nullptr) const;
};