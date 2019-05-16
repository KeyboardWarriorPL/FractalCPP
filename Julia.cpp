#include "Julia.h"
#include <iostream>

Julia::Julia() : Julia(1) {}
Julia::Julia(double zoom) : Julia(zoom, Polynomial(), Polynomial({1})) {}
Julia::Julia(double zoom, const Polynomial& numerator, const Polynomial& denominator) : scale(zoom), cmap(0xffffff), f(numerator), g(denominator) {}

string Julia::ToString() const {
    string s = f.ToString();
    s.append(" / ");
    s.append(g.ToString());
    return s;
}
void Julia::set(const Polynomial& numerator, const Polynomial& denominator) {
    f = numerator;
    g = denominator;
}
void Julia::colormap(int c) {
    cmap = c;
}
void Julia::rescale(double zoom) {
    scale = zoom;
}

int Julia::process(int iters, const FComplex& start, const FComplex& c) const {
    FComplex n{start};
    for (int i = 0; i < iters; i++) {
        n = f(n) / g(n) + c;
        if (n.R() >= 4 / scale)
            return getColor((double)i / iters);
    }
    return getColor(1);
}
int Julia::getColor(double progress) const {
    if (progress >= 1)
        return 0;
    return cmap * exp(-progress);
}
void Julia::paint(QImage& plot, int iterations, const FComplex& c, QProgressBar* progress) const {
    int width = plot.width()-1, height = plot.height()-1;
    FComplex z;
    for (int y = 0; y <= height; y++) {
        for (int x = 0; x <= width; x++) {
            z.set(((double)x / width - 0.5) * 4.0 / scale, ((double)y / height - 0.5) * 4.0 / scale);
            plot.setPixel(x, y, process(iterations, z, c));
            if (progress != nullptr)
                progress->setValue(100.0*y / height);
        }
    }
    if (progress != nullptr)
        progress->setValue(100);
}