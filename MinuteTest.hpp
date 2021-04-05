#ifndef __MINUTE_TEST_HPP__
#define __MINUTE_TEST_HPP__

#include "gtest/gtest.h"
#include "Minute.hpp"
#include <string>

using std::string;

TEST(MinuteTestSet, invalidInput1) {

    Minute min;

    min.parse("12:70 pm");

    EXPECT_EQ(min.getMinute(), -1);
}

TEST(MinuteTestSet, invalidInput2) {

    Minute min;

    min.parse("13:70 pm");

    EXPECT_EQ(min.getMinute(), -1);
}

TEST(MinuteTestSet, invalidInput3) {

    Minute min;

    min.parse("15:50 pm");

    EXPECT_EQ(min.getMinute(), -1);
}

TEST(MinuteTestSet, invalidInput4) {

    Minute min;

    min.parse(":70 pm");

    EXPECT_EQ(min.getMinute(), -1);
}

TEST(MinuteTestSet, invalidInput5) {

    Minute min;

    min.parse("12:5 pm");

    EXPECT_EQ(min.getMinute(), -1);
}

TEST(MinuteTestSet, invalidInput6) {

    Minute min;

    min.parse("14 pm");

    EXPECT_EQ(min.getMinute(), -1);
}

TEST(MinuteTestSet, invalidInput7) {

    Minute min;

    min.parse("18:94 pm");

    EXPECT_EQ(min.getMinute(), -1);
}

TEST(MinuteTestSet, invalidInput8) {

    Minute min;

    min.parse("1:9 pm");

    EXPECT_EQ(min.getMinute(), -1);
}
TEST(MinuteTestSet, invalidInput9) {

    Minute min;

    min.parse("-1:43 pm");

    EXPECT_EQ(min.getMinute(), -1);
}
TEST(MinuteTestSet, invalidInput10) {

    Minute min;

    min.parse("AB:30 pm");

    EXPECT_EQ(min.getMinute(), -1);
}
TEST(MinuteTestSet, invalidInput11) {

    Minute min;

    min.parse("50:CD0 pm");

    EXPECT_EQ(min.getMinute(), -1);
}

TEST(MinuteTestSet, invalidInput12) {

    Minute min;

    min.parse("5:Y0 pm");

    EXPECT_EQ(min.getMinute(), -1);
}

TEST(MinuteTestSet, lower1) {

    Minute min;

    min.parse("12:50 pm");

    EXPECT_EQ(min.getMinute(), 770);
}

TEST(MinuteTestSet, lower2) {

    Minute min;

    min.parse("12:50 am");

    EXPECT_EQ(min.getMinute(), 50);
}

TEST(MinuteTestSet, NoAMPM1) {

    Minute min;

    min.parse("12:00");

    EXPECT_EQ(min.getMinute(), -1);
}
TEST(MinuteTestSet, NoAMPM2) {

    Minute min;

    min.parse("5:40");

    EXPECT_EQ(min.getMinute(), -1);
}
TEST(MinuteTestSet, NoAMPM3) {

    Minute min;

    min.parse("7");

    EXPECT_EQ(min.getMinute(), -1);
}

TEST(MinuteTestSet, Military1) {

    Minute min;

    min.parse("17:00");

    EXPECT_EQ(min.getMinute(), -1);
}
TEST(MinuteTestSet, Military2) {

    Minute min;

    min.parse("19:45");

    EXPECT_EQ(min.getMinute(), -1);
}
TEST(MinuteTestSet, Military3) {

    Minute min;

    min.parse("23");

    EXPECT_EQ(min.getMinute(), -1);
}

TEST(MinuteTestSet, NoMin1) {

    Minute min;

    min.parse("5 AM");

    EXPECT_EQ(min.getMinute(), 300);
}
TEST(MinuteTestSet, NoMin2) {

    Minute min;

    min.parse("5 PM");

    EXPECT_EQ(min.getMinute(), 1020);
}
TEST(MinuteTestSet, Proper1) {

    Minute min;

    min.parse("5:00 AM");

    EXPECT_EQ(min.getMinute(), 300);
}
TEST(MinuteTestSet, Proper2) {

    Minute min;

    min.parse("5:00 PM");

    EXPECT_EQ(min.getMinute(), 1020);
}
TEST(MinuteTestSet, NoSpace1) {

    Minute min;

    min.parse("5:00AM");

    EXPECT_EQ(min.getMinute(), 300);
}
TEST(MinuteTestSet, NoSpace2) {

    Minute min;

    min.parse("5:00PM");

    EXPECT_EQ(min.getMinute(), 1020);
}

TEST(MinuteTestSet, Midnight1) {

    Minute min;

    min.parse("0:00AM");

    EXPECT_EQ(min.getMinute(), 0);
}
TEST(MinuteTestSet, Midnight2) {

    Minute min;

    min.parse("12:00AM");

    EXPECT_EQ(min.getMinute(), 0);
}
TEST(MinuteTestSet, Midnight3) {

    Minute min;

    min.parse("0 AM");

    EXPECT_EQ(min.getMinute(), 0);
}
TEST(MinuteTestSet, Midnight4) {

    Minute min;

    min.parse("12 AM");

    EXPECT_EQ(min.getMinute(), 0);
}

TEST(MinuteTestSet, Noon1) {

    Minute min;

    min.parse("0:00 PM");

    EXPECT_EQ(min.getMinute(), 720);
}
TEST(MinuteTestSet, Noon2) {

    Minute min;

    min.parse("12:00 PM");

    EXPECT_EQ(min.getMinute(), 720);
}
TEST(MinuteTestSet, Noon3) {

    Minute min;

    min.parse("0 PM");

    EXPECT_EQ(min.getMinute(), 720);
}
TEST(MinuteTestSet, Noon4) {

    Minute min;

    min.parse("12 PM");

    EXPECT_EQ(min.getMinute(), 720);
}

#endif
