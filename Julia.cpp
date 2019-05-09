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

QColor Julia::process(int iters, const FComplex& start, const FComplex& c) const {
    FComplex n{start};
    for (int i = 0; i < iters; i++) {
        n = f.calc(n) / g.calc(n) + c;
        if (n.R() > threshold)
            return getColor(i / iters);
    }
    return getColor(1);
}
QColor Julia::getColor(double progress) const {
    if (progress >= 1)
        return QColor{0, 0, 0};
    return QColor{(QRgb)(0xffffff * (1.0 - progress))};
}
QImage& Julia::paint(QImage& plot, int iterations, const FComplex& c) const {
    FComplex z;
    for (int x = 0; x < plot.width(); x++) {
        for (int y = 0; y < plot.height(); y++) {
            z.set((double)x/plot.width(), (double)y/plot.height());
            plot.setPixel(x, y, process(iterations, z, c).rgb());
        }
    }
    return plot;
}