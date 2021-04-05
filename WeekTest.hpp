#ifndef WEEK_TEST_HPP
#define WEEK_TEST_HPP

#include "gtest/gtest.h"
#include "WeekIndex.hpp"

TEST(WeekTestSet, NormalTest) {
    WeekIndex test;
    double val = test.calculate(10,1);
    EXPECT_NEAR(val, 1.5, .4);
}
TEST(WeekTestSet, NegMinTest) {
    WeekIndex test;
    double val = test.calculate(-10,1);
    EXPECT_NEAR(val, 0, 0);
}
TEST(WeekTestSet, NegEventTest) {
    WeekIndex test;
    double val = test.calculate(10,-1);
    EXPECT_NEAR(val, 0, 0);
}
#endif