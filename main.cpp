#include <iostream>

#if __has_include(<QApplication>)
#include <QApplication>
#elif __has_include(<QtGui/QApplication>)
// Qt4
#include <QtGui/QApplication>
#elif __has_include(<QtWidgets/QApplication>)
// Qt5
#include <QtWidgets/QApplication>
#else
#define QT_BROKEN
#warning "Include Qt failed"
#endif

#ifndef QT_BROKEN

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    return app.exec();
}

#else
int main() {
    std::cout << "Error: Built without Qt" << std::endl;
    return 1;
}
#endif