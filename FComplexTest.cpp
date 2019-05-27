#ifndef TESTSBUILD
#include "FComplex.h"
#include <gtest/gtest.h>

TEST(ComplexAdd, ShouldAddComplex) {
    FComplex a{1,1};
    a += 2;
    EXPECT_TRUE(a == FComplex(3,1));
    EXPECT_TRUE(FComplex(1.2, 2.8) + FComplex(1.8, 1.2) == FComplex(3, 4));
    a -= FComplex(3,1);
    EXPECT_TRUE(a == FComplex(0.0));
    EXPECT_TRUE(FComplex(1, 2) - FComplex(1, 1) == FComplex(0, 1));
}

TEST(ComplexMultiply, ShouldMultiplyComplex) {
    FComplex a{1,1};
    a *= 2;
    EXPECT_TRUE(a == FComplex(2,2));
    EXPECT_TRUE(FComplex(1.2, 2.8) + FComplex(1.8, 1.2) == FComplex(3, 4));
    a /= FComplex(3,1);
    EXPECT_TRUE(a == FComplex(0.0));
    EXPECT_TRUE(FComplex(1, 2) - FComplex(1, 1) == FComplex(0, 1));
}
#endif