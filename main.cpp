#if __has_include(<QApplication>)
#include <QtGui>
#else
#warning "Using Qt4 direct including (not recommended)"
#include <QtGui/QApplication>
#include <QtGui/QtGui>
#endif
#include "FrontForm.h"

#if __has_include(<gtest/gtest.h>)
// Uncomment the line below to switch to googletest build
// #define TESTSBUILD
#include <gtest/gtest.h>
#else
#warning "gtest not found"
#endif

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
#include "FComplexTest.h"
#include "PolynomialTest.h"

// googletest main function
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif