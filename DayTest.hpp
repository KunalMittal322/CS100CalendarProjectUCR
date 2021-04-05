#ifndef DAY_TEST_HPP
#define DAY_TEST_HPP

#include "gtest/gtest.h"
#include "DayIndex.hpp"

TEST(DayTestSet, NormalTest) {
    DayIndex test;
    double val = test.calculate(10,1);
    EXPECT_EQ(val, 10);
}

TEST(DayTestSet, NegMinTest) {
    DayIndex test;
    double val = test.calculate(-10,1);
    EXPECT_EQ(val, 0);
}

TEST(DayTestSet, NegEventTest) {
    DayIndex test;
    double val = test.calculate(10,-1);
    EXPECT_EQ(val, 0);
}

#endif
