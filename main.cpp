#include <iostream>
#include <QtGui/QtGui>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowFilePath("main.ui");
    window.show();
    return app.exec();
}