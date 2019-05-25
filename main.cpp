#if __has_include(<QApplication>)
#include <QtGui>
#else
#warning "Using Qt4 direct including (not recommended)"
#include <QtGui/QApplication>
#include <QtGui/QtGui>
#endif

#include <gtest/gtest.h>
#include "FrontForm.h"

// Uncomment the line below to switch to googletest build
#define TESTSBUILD

#ifndef TESTSBUILD
// Qt main function
int main(int argc, char **argv) {
    QApplication app{argc, argv};
    QMainWindow *window = new QMainWindow;
    FrontForm form{window};
    form.show();
    return app.exec();
}
#else
// googletest main function
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif