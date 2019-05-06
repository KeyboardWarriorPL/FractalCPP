#include <iostream>

#if __has_include(<QApplication>)
#include <QApplication>
#else
// Qt4
#include <QtGui/QApplication>
#endif

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    return app.exec();
}