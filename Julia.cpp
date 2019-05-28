#include "Julia.h"

const double Julia::XRANGE = 4.0, Julia::YRANGE = 4.0;

Julia::Julia() : Julia(1) {}
Julia::Julia(double zoom) : Julia(zoom, Polynomial(), Polynomial({1})) {}
Julia::Julia(double zoom, const Polynomial& numerator, const Polynomial& denominator) : scale(zoom), offset{0, 0}, cmap(0xffffff), mapshift(0), f(numerator), g(denominator) {}

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
    mapshift = s-1;
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
        if (n.R() >= sqrt(XRANGE*XRANGE+YRANGE*YRANGE))
            return getColor((double)i / iters);
    }
    return getColor(1);
}
int Julia::getColor(double progress) const {
    if (progress >= 1)
        return 0;
    return reshiftMap(reshiftMap(cmap, mapshift) * exp(-progress), 6-mapshift);
}
int Julia::reshiftMap(int map, int shift) const {
    if (shift % 6 == 0)
        return map;
    int tmp[6];
    tmp[0] = map % 16;
    for (int i = 1; i < 6; i++)
        tmp[i] = (map >> (4*i)) % 16;
    map = 0;
    for (int i = 0; i < 6; i++) {
        if ((i+shift) % 6 != 0)
            map += tmp[i] << (4 * ((i+shift) % 6));
        else
            map += tmp[i];
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