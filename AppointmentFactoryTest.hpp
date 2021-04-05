#ifndef __APPOINTMENT_FACTORY_TEST_HPP__
#define __APPOINTMENT_FACTORY_TEST_HPP__

#include "EventFactory.hpp"
#include "gtest/gtest.h"
#include "AppointmentFactory.hpp"
using std::string;

TEST(AppointmentFactoryTestSet, makeEvent1) {

	AppointmentFactory appFac;

	Event* ev = appFac.createEvent(720, 780, "Doctor's Visit", "Yearly Checkup");


    EXPECT_EQ(ev->getTag(), "Appointment");
    EXPECT_EQ(ev->getStartMin(), 720);
    EXPECT_EQ(ev->getEndMin(), 780);
    EXPECT_EQ(ev->getName(), "Doctor's Visit");
    EXPECT_EQ(ev->getDescription(), "Yearly Checkup");
    EXPECT_EQ(ev->getDuration(), 60);
}

TEST(AppointmentFactoryTestSet, makeEvent2) {

	AppointmentFactory appFac;

	Event* ev = appFac.createEvent(660, 1125, "Physical Therapy", "I am the bone of my sword");


    EXPECT_EQ(ev->getTag(), "Appointment");
    EXPECT_EQ(ev->getStartMin(), 660);
    EXPECT_EQ(ev->getEndMin(), 1125);
    EXPECT_EQ(ev->getName(), "Physical Therapy");
    EXPECT_EQ(ev->getDescription(), "I am the bone of my sword");
    EXPECT_EQ(ev->getDuration(), 465);
}


#endif 
