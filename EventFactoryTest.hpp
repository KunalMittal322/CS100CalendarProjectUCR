#ifndef __EVENT_FACTORY_TEST_HPP__
#define __EVENT_FACTORY_TEST_HPP__

#include "EventFactory.hpp"
#include "gtest/gtest.h"
using std::string;

TEST(EventFactoryTestSet, makeEvent1) {

	EventFactory Fac;

	Event* ev = Fac.createEvent(720, 780, "Doctor's Visit", "Yearly Checkup");


    EXPECT_EQ(ev->getTag(), "");
    EXPECT_EQ(ev->getStartMin(), 720);
    EXPECT_EQ(ev->getEndMin(), 780);
    EXPECT_EQ(ev->getName(), "Doctor's Visit");
    EXPECT_EQ(ev->getDescription(), "Yearly Checkup");
    EXPECT_EQ(ev->getDuration(), 60);
}

TEST(EventFactoryTestSet, makeEvent2) {

	EventFactory Fac;

	Event* ev = Fac.createEvent(660, 1125, "Physical Therapy", "I am the bone of my sword");


    EXPECT_EQ(ev->getTag(), "");
    EXPECT_EQ(ev->getStartMin(), 660);
    EXPECT_EQ(ev->getEndMin(), 1125);
    EXPECT_EQ(ev->getName(), "Physical Therapy");
    EXPECT_EQ(ev->getDescription(), "I am the bone of my sword");
    EXPECT_EQ(ev->getDuration(), 465);
}

TEST(EventFactoryTestSet, makeEvent3) {

    EventFactory Fac;

    Event* ev = Fac.createEvent(660, 1125, "Physical Therapy", "I am the bone of my sword");


    EXPECT_EQ(ev->getTag(), "");
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
    EXPECT_EQ(ev->getDetailed(), "Physical Therapy: 11:00 AM - 6:45 PM, Type: , I am the bone of my sword\n");
}
#endif