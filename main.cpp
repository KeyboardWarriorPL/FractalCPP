#include <iostream>
#if __has_include(<QApplication>)
#include <QtGui>
#else
#warning "Using Qt4 direct including (not recommended)"
#include <QtGui/QApplication>
#include <QtGui/QtGui>
#endif
#include "Julia.h"
#include "ui_front.h"

int main(int argc, char **argv) {
    QApplication app{argc, argv};
    QImage test{128,128, QImage::Format_RGB32};
    test.fill(qRgb(23,45,177));
    Julia j{1, Polynomial{{2,0}}, Polynomial{1}};
    test = j.paint(test, 8, 0.56);
    QLabel l;
    l.setPixmap(QPixmap::fromImage(test));
    l.show();
    // QWidget* window = new QWidget;
    // Ui::Main layout;
    // layout.setupUi(window);
    // window->show();
    return app.exec();
}