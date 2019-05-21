#if __has_include(<QApplication>)
#include <QtGui>
#else
#warning "Using Qt4 direct including (not recommended)"
#include <QtGui/QApplication>
#include <QtGui/QtGui>
#endif
#include "FrontForm.h"

int main(int argc, char **argv) {
    QApplication app{argc, argv};
    QMainWindow *window = new QMainWindow;
    FrontForm form{window};
    form.show();
    return app.exec();
}