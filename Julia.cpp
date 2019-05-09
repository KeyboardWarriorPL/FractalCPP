#include "Julia.h"

Julia::Julia() : Julia(128, 1) {}
Julia::Julia(int imgsize, double zoom) : Julia(imgsize, zoom, Polynomial{}, Polynomial{}) {}
Julia::Julia(int imgsize, double zoom, const Polynomial& numerator, const Polynomial& denominator) : size(imgsize), scale(zoom), threshold(100), f(Polynomial{numerator}), g(Polynomial{denominator}) {}

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
QImage Julia::calc(int iterations, const FComplex& c) const {
    QImage plot{size, size, QImage::Format_RGB32};
    FComplex z;
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            z.set(x, y);
            plot.setColor(plot.pixelIndex(x, y), process(iterations, z, c).rgb());
        }
    }
    return plot;
}