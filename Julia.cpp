#include "Julia.h"

const double Julia::XRANGE = 4.0, Julia::YRANGE = 4.0;

Julia::Julia() : Julia(1) {}
Julia::Julia(double zoom) : Julia(zoom, Polynomial(), Polynomial({1})) {}
Julia::Julia(double zoom, const Polynomial& numerator, const Polynomial& denominator) : scale(zoom), offset{0, 0}, cmap(0xffffff), mapshift(1), f(numerator), g(denominator) {}

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
void Julia::colormap(int c, int s) {
    cmap = c;
    mapshift = s;
}
void Julia::reposition(double x, double y, bool set) {
    if (set) {
        offset[0] = x;
        offset[1] = y;
    }
    else {
        offset[0] += x;
        offset[1] += y;
    }
}
void Julia::rescale(double zoom) {
    scale = zoom;
}

int Julia::process(int iters, const FComplex& start, const FComplex& c) const {
    FComplex n{start};
    for (int i = 0; i < iters; i++) {
        n = f(n) / g(n) + c;
        if (n.R() >= sqrt(XRANGE*YRANGE))
            return getColor((double)i / iters);
    }
    return getColor(1);
}
int Julia::getColor(double progress) const {
    if (progress >= 1)
        return 0;
    return unshiftMap(reshiftMap(cmap) * exp(-progress));
}
int Julia::reshiftMap(int map) const {
    int shift = mapshift;
    while (shift > 1) {
        int r,g,b;
        b = map%256;
        g = (map%(256*256) - b) >> 8;
        r = (map - g - b) >> 16;
        map = (g << 16) + (b << 8) + r;
        shift--;
    }
    return map;
}
int Julia::unshiftMap(int map) const {
    int shift = 1;
    while (shift < mapshift) {
        int r,g,b;
        b = map%256;
        g = (map%(256*256) - b) >> 8;
        r = (map - g - b) >> 16;
        map = (b << 16) + (r << 8) + g;
        shift++;
    }
    return map;
}
void Julia::paint(QImage& plot, int iterations, const FComplex& c, QProgressBar* progress) const {
    int width = plot.width()-1, height = plot.height()-1;
    FComplex z;
    for (int y = 0; y <= height; y++) {
        for (int x = 0; x <= width; x++) {
            z.set(((offset[0] + x) / width - 0.5) * XRANGE / scale, ((offset[1] + y) / height - 0.5) * YRANGE / scale);
            plot.setPixel(x, y, process(iterations, z, c));
            if (progress != nullptr)
                progress->setValue(100.0*y / height);
        }
    }
    if (progress != nullptr)
        progress->setValue(100);
}