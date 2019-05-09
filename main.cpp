#include <iostream>
#include <QApplication>
#include "Julia.h"

int main(int argc, char **argv) {
    QApplication app{argc, argv};
    // QWidget window;
    // window.setWindowFilePath("main.ui");
    // window.show();
    Julia j{};
    j.set(Polynomial{new FComplex[2] {0, 1}, 2}, Polynomial{1});
    QImage test = j.calc(2, FComplex{0.234, 0.84});
    test.save("welcome.png");
    return app.exec();
}