#ifdef TESTSBUILD
#include "Polynomial.h"
#include <gtest/gtest.h>

TEST(PolyCalc, ShouldCalcPoly) {
    Polynomial f{1.0, 1.0, 1.0};
    EXPECT_DOUBLE_EQ(f(0.0), 1.0);
    EXPECT_DOUBLE_EQ(f(1.0), 3.0);
    EXPECT_DOUBLE_EQ(f(-4.0), 13.0);
}

TEST(PolyAdd, ShouldAddPoly) {
    Polynomial f{1.0, 1.0};
    f += 2.0;
    EXPECT_TRUE(f == Polynomial{3.0, 1.0});
    EXPECT_TRUE(Polynomial{0.0, 3.0, 1.0} + Polynomial{5.0, -1.0} == Polynomial{5.0, 2.0, 1.0});
    f -= Polynomial{0.0, 1.0, 5.0};
    EXPECT_TRUE(f == Polynomial{3.0, 0.0, -5.0});
    EXPECT_TRUE(Polynomial{1.0, 1.0, 1.0} - Polynomial{2.0, 2.0} == Polynomial{-1.0, -1.0, 1.0});
}

TEST(PolyMultiply, ShouldMultiplyPoly) {
    Polynomial f{1.0, 1.0};
    f *= 2.0;
    EXPECT_TRUE(f == Polynomial{2.0, 2.0});
    EXPECT_TRUE(Polynomial{0.0, 3.0, 1.0} * 5.0 == Polynomial{0.0, 15.0, 5.0});
}

TEST(PolyFromStr, ShouldParsePoly) {
    Polynomial g("2,5z^2 + z + (5-3i)z^3 - 2,2");
    // Polynomial g("2.5z^2 + z + (5-3i)z^3 - 2.2"); // US version
    EXPECT_TRUE(g == Polynomial{-2.2, 1.0, 2.5, FComplex(5,-3)});
}
#endif