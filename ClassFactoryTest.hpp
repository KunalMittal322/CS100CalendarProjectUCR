#ifndef __CLASS_FACTORY_TEST_HPP__
#define __CLASS_FACTORY_TEST_HPP__

#include "EventFactory.hpp"
#include "gtest/gtest.h"
#include "ClassFactory.hpp"
using std::string;

TEST(ClassFactoryTestSet, makeEvent1) {

	ClassFactory classFac;

	Event* ev = classFac.createEvent(1140, 1190, "CS100 Lecture", "In Class Ex Today");


    EXPECT_EQ(ev->getTag(), "Class");
    EXPECT_EQ(ev->getStartMin(), 1140);
    EXPECT_EQ(ev->getEndMin(), 1190);
    EXPECT_EQ(ev->getName(), "CS100 Lecture");
    EXPECT_EQ(ev->getDescription(), "In Class Ex Today");
    EXPECT_EQ(ev->getDuration(), 50);
}

TEST(ClassFactoryTestSet, makeEvent2) {

	ClassFactory classFac;

	Event* ev = classFac.createEvent(100, 200, "Physics Disc", "Newton Lab");


    EXPECT_EQ(ev->getTag(), "Class");
    EXPECT_EQ(ev->getStartMin(), 100);
    EXPECT_EQ(ev->getEndMin(), 200);
    EXPECT_EQ(ev->getName(), "Physics Disc");
    EXPECT_EQ(ev->getDescription(), "Newton Lab");
    EXPECT_EQ(ev->getDuration(), 100);
}

TEST(ClassFactoryTestSet, makeEvent3) {

    ClassFactory Fac;

    Event* ev = Fac.createEvent(660, 1125, "Physical Therapy", "I am the bone of my sword");


    EXPECT_EQ(ev->getTag(), "Class");
    EXPECT_EQ(ev->getStartMin(), 660);
    EXPECT_EQ(ev->getEndMin(), 1125);
    EXPECT_EQ(ev->getName(), "Physical Therapy");
    EXPECT_EQ(ev->getDescription(), "I am the bone of my sword");
    EXPECT_EQ(ev->getDuration(), 465);
    EXPECT_EQ(ev->numToTime(660), "11:00 AM");
    EXPECT_EQ(ev->numToTime(0), "12:00 AM");
    EXPECT_EQ(ev->numToTime(720), "12:00 PM");
    EXPECT_EQ(ev->numToTime(1080), "6:00 PM");
    EXPECT_EQ(ev->numToTime(585), "9:45 AM");
    EXPECT_EQ(ev->numToTime(1305), "9:45 PM");
    EXPECT_EQ(ev->getDetailed(), "Physical Therapy: 11:00 AM - 6:45 PM, Type: Class, I am the bone of my sword\n");
}

#endif
