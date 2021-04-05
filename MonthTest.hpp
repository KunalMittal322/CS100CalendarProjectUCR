#ifndef MONTH_TEST_HPP
#define MONTH_TEST_HPP

#include "gtest/gtest.h"
#include "MonthIndex.hpp"

TEST(MonthTestSet, NormalTest) {
    MonthIndex test;
    double val = test.calculate(280,1);
    EXPECT_EQ(val, 10);
}

TEST(MonthTestSet, NegMinTest) {
    MonthIndex test;
    double val = test.calculate(-10,1);
    EXPECT_EQ(val, 0);
}

TEST(MonthTestSet, NegEventTest) {
    MonthIndex test;
    double val = test.calculate(10,-1);
    EXPECT_EQ(val, 0);
}
#endif


