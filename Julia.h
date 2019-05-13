#pragma once
#include "Polynomial.h"
#include "FComplex.h"
#include <vector>

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
    vector<int> paint(int, int, int, const FComplex&) const;
};