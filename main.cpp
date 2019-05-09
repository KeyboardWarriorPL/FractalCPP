#include <iostream>
#include <QApplication>
#include <QtGui>
#include "Julia.h"

int main(int argc, char **argv) {
    QApplication app{argc, argv};
    Julia j;
    j.set(Polynomial{new FComplex[2] {0, 1}, 2}, Polynomial{1});
    QImage test{128, 128, QImage::Format_RGB32};
    test.fill(QColor{255,255,255}.rgb());
    cout << "sad" << endl;
    j.paint(test, 2, FComplex{0.234, 0.84});
    cout << "sad" << endl;
    QLabel l{};
    cout << "sad" << endl;
    l.setPixmap(QPixmap::fromImage(test));
    cout << "sad" << endl;
    l.show();
    return app.exec();
}