#ifdef TESTSBUILD
#include "FComplex.h"
#include <gtest/gtest.h>

TEST(ComplexAdd, ShouldAddComplex) {
    FComplex a{1,1};
    a += 2;
    EXPECT_TRUE(a == FComplex(3,1)) << a.ToString();
    a = FComplex(1.2, 2.8) + FComplex(1.8, 1.2);
    EXPECT_TRUE(a == FComplex(3, 4)) << a.ToString();
    a.set(3,1);
    a -= FComplex(3,1);
    EXPECT_TRUE(a == FComplex(0.0)) << a.ToString();
    a = FComplex(1, 2) - FComplex(1, 1);
    EXPECT_TRUE(a == FComplex(0, 1)) << a.ToString();
}

TEST(ComplexMultiply, ShouldMultiplyComplex) {
    FComplex a{1,1};
    a *= 2;
    EXPECT_TRUE(a == FComplex(2,2)) << a.ToString();
    a = FComplex(4, 8) * FComplex(4, 2);
    EXPECT_TRUE(a == FComplex(0, 40)) << a.ToString();
    a.set(2, 2);
    a /= FComplex(2,1);
    EXPECT_TRUE(a == FComplex(1.2, 0.4)) << a.ToString();
    a = FComplex(1, 2) / FComplex(1, 1);
    EXPECT_TRUE(a == FComplex(1.5, 0.5)) << a.ToString();
}

TEST(ComplexPower, ShouldPowerComplex) {
    FComplex a{-2,0}, b;
    b = a.power(1);
    EXPECT_TRUE(b == -2) << b.ToString();
    b = a.power(2);
    EXPECT_TRUE(b == 4) << b.ToString();
    b = a.power(3);
    EXPECT_TRUE(b.Real() <= (1e-14)-8 && b.Real() >= (-1e-14)-8) << b.ToString();
}

TEST(ComplexFromStr, ShouldParseStrComplex) {
    FComplex a("2.25-3.1i"), b("(+-9.1i)");
    EXPECT_TRUE(a == FComplex(2.25, -3.1)) << a.ToString();
    EXPECT_TRUE(b == FComplex(0, -9.1)) << b.ToString();
}
#endif