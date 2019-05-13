#include "Julia.h"

Julia::Julia() : Julia(1) {}
Julia::Julia(double zoom) : Julia(zoom, Polynomial{}, Polynomial{}) {}
Julia::Julia(double zoom, const Polynomial& numerator, const Polynomial& denominator) : scale(zoom), threshold(100), f(Polynomial{numerator}), g(Polynomial{denominator}) {}

void Julia::set(const Polynomial& numerator, const Polynomial& denominator) {
    f = numerator;
    g = denominator;
}
void Julia::rescale(double zoom) {
    scale = zoom;
}

int Julia::process(int iters, const FComplex& start, const FComplex& c) const {
    FComplex n{start};
    for (int i = 0; i < iters; i++) {
        n = f.calc(n) / g.calc(n) + c;
        if (n.R() > threshold)
            return getColor(i / iters);
    }
    return getColor(1);
}
int Julia::getColor(double progress) const {
    if (progress >= 1)
        return 0;
    return (0xffffff * (1.0 - progress));
}
vector<int> Julia::paint(int width, int height, int iterations, const FComplex& c) const {
    vector<int> plot;
    FComplex z;
    plot.reserve(width*height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            z.set((double)x/width, (double)y/height);
            plot.push_back(process(iterations, z, c));
        }
    }
    return plot;
}