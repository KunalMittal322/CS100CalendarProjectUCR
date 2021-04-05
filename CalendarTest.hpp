#ifndef CALENDAR_TEST_HPP
#define CALENDAR_TEST_HPP


#include "gtest/gtest.h"
#include "Calendar.hpp"

TEST(CalendarTest, NormalTest) {
    Calendar C;
    AppointmentFactory fac;
    Event *first = fac.createEvent(0, 100, "test", "test2");
    C.addEvent(0, first);
    ASSERT_EQ(C.getDay(0).size(),1);
}

TEST(CalendarTestSet, ConstructorTest1) {
	Calendar c;
	EXPECT_TRUE(c.empty());
}

TEST(CalendarTestSet, ConstructorTest2) {
	Calendar c;
	Event* ev = new Event(0, 1, "Dummy1", "DummyDescr", "");
	c.addEvent(0, ev);
	EXPECT_TRUE(!c.empty());
}

TEST(CalendarTestSet, emptyTest1) {
	Calendar c;
	EXPECT_TRUE(c.empty());
}

TEST(CalendarTestSet, emptyTest2) {
	Calendar c;
	Event* ev = new Event(0, 1, "Dummy1", "DummyDescr", "");
	c.addEvent(0, ev);
	EXPECT_TRUE(!c.empty());
}

TEST(CalendarTestSet, addEventTest1) {
	Calendar c;
	Event* ev1 = new Event(0, 1, "Dummy1", "DummyDescr", "");
	c.addEvent(0, ev1);

	EXPECT_EQ(c.getEvent(0, 0, 1, "Dummy1", "DummyDescr"), ev1);
	
	EXPECT_TRUE(!c.empty());
}

TEST(CalendarTestSet, addEventTest2) {
	Calendar c;
	Event* ev1 = new Event(0, 1, "Dummy1", "DummyDescr1", "");
	Event* ev2 = new Event(100, 200, "Dummy2", "DummyDescr2", "");
	c.addEvent(0, ev1);
	c.addEvent(0, ev2);

	EXPECT_EQ(c.getEvent(0, 0, 1, "Dummy1", "DummyDescr1"), ev1);
	EXPECT_EQ(c.getEvent(0, 100, 200, "Dummy2", "DummyDescr2"), ev2);
	

	EXPECT_TRUE(!c.empty());
}

TEST(CalendarTestSet, addEventTest3) {
	Calendar c;
	Event* ev1 = new Event(0, 1, "Dummy1", "DummyDescr1", "");
	Event* ev2 = new Event(0, 100, "Dummy2", "DummyDescr2", "");
	Event* ev3 = new Event(500, 600, "Dummy3", "DummyDescr3", "");
	c.addEvent(0, ev1);
	c.addEvent(0, ev2);
	c.addEvent(1, ev3);

	EXPECT_EQ(c.getEvent(0, 0, 1, "Dummy1", "DummyDescr1"), ev1);
	EXPECT_EQ(c.getEvent(0, 0, 100, "Dummy2", "DummyDescr2"), ev2);
	EXPECT_EQ(c.getEvent(1, 500, 600, "Dummy3", "DummyDescr3"), ev3);

	EXPECT_TRUE(!c.empty());
}

TEST(CalendarTestSet, removeEventTest1) {
	Calendar c;
	Event* ev1 = new Event(0, 1, "Dummy1", "DummyDescr", "");
	c.addEvent(0, ev1);

	EXPECT_EQ(c.getEvent(0, 0, 1, "Dummy1", "DummyDescr"), ev1);
	c.removeEvent(0, 1);


	EXPECT_TRUE(c.empty());
}

TEST(CalendarTestSet, removeEventTest2) {
	Calendar c;
	Event* ev1 = new Event(0, 1, "Dummy1", "DummyDescr1", "");
	Event* ev2 = new Event(100, 200, "Dummy2", "DummyDescr2", "");
	c.addEvent(0, ev1);
	c.addEvent(0, ev2);

	EXPECT_EQ(c.getEvent(0, 0, 1, "Dummy1", "DummyDescr1"), ev1);
	EXPECT_EQ(c.getEvent(0, 100, 200, "Dummy2", "DummyDescr2"), ev2);
	
	c.removeEvent(0, 2);
	EXPECT_EQ(c.getEvent(0, 1), ev1);

	EXPECT_TRUE(!c.empty());
}

TEST(CalendarTestSet, removeEventTest2_1) {
	Calendar c;
	Event* ev1 = new Event(0, 1, "Dummy1", "DummyDescr1", "");
	Event* ev2 = new Event(100, 200, "Dummy2", "DummyDescr2", "");
	c.addEvent(0, ev1);
	c.addEvent(0, ev2);

	EXPECT_EQ(c.getEvent(0, 0, 1, "Dummy1", "DummyDescr1"), ev1);
	EXPECT_EQ(c.getEvent(0, 100, 200, "Dummy2", "DummyDescr2"), ev2);
	
	c.removeEvent(0, 1);

	EXPECT_EQ(c.getEvent(0, 1), ev2);

	EXPECT_TRUE(!c.empty());

	c.removeEvent(0, 1);
	EXPECT_TRUE(c.empty());
}

TEST(CalendarTestSet, removeEventTest3) {
	Calendar c;
	Event* ev1 = new Event(0, 1, "Dummy1", "DummyDescr1", "");
	Event* ev2 = new Event(0, 100, "Dummy2", "DummyDescr2", "");
	Event* ev3 = new Event(500, 600, "Dummy3", "DummyDescr3", "");
	c.addEvent(0, ev1);
	c.addEvent(0, ev2);
	c.addEvent(1, ev3);

	EXPECT_EQ(c.getEvent(0, 0, 1, "Dummy1", "DummyDescr1"), ev1);
	EXPECT_EQ(c.getEvent(0, 0, 100, "Dummy2", "DummyDescr2"), ev2);
	EXPECT_EQ(c.getEvent(1, 500, 600, "Dummy3", "DummyDescr3"), ev3);

	EXPECT_TRUE(!c.empty());

	c.removeEvent(0, 2);

	EXPECT_EQ(c.getEvent(0, 1), ev1);
	c.removeEvent(0, 1);

	EXPECT_TRUE(!c.empty());
}

TEST(CalendarTestSet, removeEventTest4) {
	Calendar c;
	Event* ev1 = new Event(0, 1, "Dummy1", "DummyDescr1", "");
	Event* ev2 = new Event(0, 100, "Dummy2", "DummyDescr2", "");
	Event* ev3 = new Event(500, 600, "Dummy3", "DummyDescr3", "");
	c.addEvent(0, ev1);
	c.addEvent(0, ev2);
	c.addEvent(0, ev3);

	EXPECT_EQ(c.getEvent(0, 0, 1, "Dummy1", "DummyDescr1"), ev1);
	EXPECT_EQ(c.getEvent(0, 0, 100, "Dummy2", "DummyDescr2"), ev2);
	EXPECT_EQ(c.getEvent(0, 500, 600, "Dummy3", "DummyDescr3"), ev3);

	EXPECT_TRUE(!c.empty());

	c.removeEvent(0, 2);

	EXPECT_EQ(c.getEvent(0, 2), ev3);
	EXPECT_EQ(c.getEvent(0, 1), ev1);
	c.removeEvent(0, 1);

	EXPECT_EQ(c.getEvent(0, 1), ev3);


	EXPECT_TRUE(!c.empty());
}


TEST(CalendarTestSet, getEvent1) {
	Calendar c;
	Event* ev1 = new Event(0, 1, "Dummy1", "DummyDescr", "");
	c.addEvent(0, ev1);

	EXPECT_EQ(c.getEvent(0, 0, 1, "Dummy1", "DummyDescr"), ev1);
	EXPECT_TRUE(!c.empty());
}

TEST(CalendarTestSet, getEvent2) {
	Calendar c;
	Event* ev1 = new Event(0, 1, "Dummy1", "DummyDescr1", "");
	Event* ev2 = new Event(100, 200, "Dummy2", "DummyDescr2", "");
	c.addEvent(0, ev1);
	c.addEvent(0, ev2);

	EXPECT_EQ(c.getEvent(0, 0, 1, "Dummy1", "DummyDescr1"), ev1);
	EXPECT_EQ(c.getEvent(0, 100, 200, "Dummy2", "DummyDescr2"), ev2);
	

	EXPECT_TRUE(!c.empty());
}

TEST(CalendarTestSet, getEvent3) {
	Calendar c;
	Event* ev1 = new Event(0, 1, "Dummy1", "DummyDescr1", "");
	Event* ev2 = new Event(0, 100, "Dummy2", "DummyDescr2", "");
	Event* ev3 = new Event(500, 600, "Dummy3", "DummyDescr3", "");
	c.addEvent(0, ev1);
	c.addEvent(0, ev2);
	c.addEvent(1, ev3);

	EXPECT_EQ(c.getEvent(0, 0, 1, "Dummy1", "DummyDescr1"), ev1);
	EXPECT_EQ(c.getEvent(0, 0, 100, "Dummy2", "DummyDescr2"), ev2);
	EXPECT_EQ(c.getEvent(1, 500, 600, "Dummy3", "DummyDescr3"), ev3);

	EXPECT_TRUE(!c.empty());
}

TEST(CalendarTestSet, size1) {
	Calendar c;
	Event* ev1 = new Event(0, 1, "Dummy1", "DummyDescr1", "");
	Event* ev2 = new Event(0, 100, "Dummy2", "DummyDescr2", "");
	Event* ev3 = new Event(500, 600, "Dummy3", "DummyDescr3", "");
	c.addEvent(0, ev1);
	c.addEvent(0, ev2);
	c.addEvent(1, ev3);

	EXPECT_EQ(c.getEvent(0, 0, 1, "Dummy1", "DummyDescr1"), ev1);
	EXPECT_EQ(c.getEvent(0, 0, 100, "Dummy2", "DummyDescr2"), ev2);
	EXPECT_EQ(c.getEvent(1, 500, 600, "Dummy3", "DummyDescr3"), ev3);

	EXPECT_TRUE(!c.empty());
	EXPECT_EQ(c.size(), 3);
}

TEST(CalendarTestSet, size2) {
	Calendar c;
	Event* ev1 = new Event(0, 1, "Dummy1", "DummyDescr1", "");
	Event* ev2 = new Event(100, 200, "Dummy2", "DummyDescr2", "");
	c.addEvent(0, ev1);
	c.addEvent(0, ev2);

	EXPECT_EQ(c.getEvent(0, 0, 1, "Dummy1", "DummyDescr1"), ev1);
	EXPECT_EQ(c.getEvent(0, 100, 200, "Dummy2", "DummyDescr2"), ev2);
	
	EXPECT_EQ(c.size(), 2);

	EXPECT_TRUE(!c.empty());
}

TEST(CalendarTestSet, size3) {
	Calendar c;
	Event* ev1 = new Event(0, 1, "Dummy1", "DummyDescr1", "");
	Event* ev2 = new Event(100, 200, "Dummy2", "DummyDescr2", "");
	c.addEvent(0, ev1);
	c.addEvent(0, ev2);

	EXPECT_EQ(c.getEvent(0, 0, 1, "Dummy1", "DummyDescr1"), ev1);
	EXPECT_EQ(c.getEvent(0, 100, 200, "Dummy2", "DummyDescr2"), ev2);
	
	c.removeEvent(0, 1);

	EXPECT_EQ(c.getEvent(0, 1), ev2);

	EXPECT_TRUE(!c.empty());

	c.removeEvent(0, 1);
	EXPECT_EQ(c.size(), 0);

	EXPECT_TRUE(c.empty());
}

TEST(CalendarTestSet, sizeOfDay1) {
	Calendar c;
	Event* ev1 = new Event(0, 1, "Dummy1", "DummyDescr1", "");
	Event* ev2 = new Event(0, 100, "Dummy2", "DummyDescr2", "");
	Event* ev3 = new Event(500, 600, "Dummy3", "DummyDescr3", "");
	c.addEvent(0, ev1);
	c.addEvent(0, ev2);
	c.addEvent(1, ev3);

	EXPECT_EQ(c.getEvent(0, 0, 1, "Dummy1", "DummyDescr1"), ev1);
	EXPECT_EQ(c.getEvent(0, 0, 100, "Dummy2", "DummyDescr2"), ev2);
	EXPECT_EQ(c.getEvent(1, 500, 600, "Dummy3", "DummyDescr3"), ev3);

	EXPECT_TRUE(!c.empty());
	EXPECT_EQ(c.size(), 3);
	EXPECT_EQ(c.sizeOfDay(0), 2);
	EXPECT_EQ(c.sizeOfDay(1), 1);

}

TEST(CalendarTestSet, sizeOfDay2) {
	Calendar c;
	Event* ev1 = new Event(0, 1, "Dummy1", "DummyDescr1", "");
	Event* ev2 = new Event(100, 200, "Dummy2", "DummyDescr2", "");
	c.addEvent(0, ev1);
	c.addEvent(0, ev2);

	EXPECT_EQ(c.getEvent(0, 0, 1, "Dummy1", "DummyDescr1"), ev1);
	EXPECT_EQ(c.getEvent(0, 100, 200, "Dummy2", "DummyDescr2"), ev2);
	
	EXPECT_EQ(c.size(), 2);

	EXPECT_TRUE(!c.empty());
	EXPECT_EQ(c.sizeOfDay(0), 2);
	EXPECT_EQ(c.sizeOfDay(1), 0);
}

TEST(CalendarTestSet, sizeOfDay3) {
	Calendar c;
	Event* ev1 = new Event(0, 1, "Dummy1", "DummyDescr1", "");
	Event* ev2 = new Event(100, 200, "Dummy2", "DummyDescr2", "");
	c.addEvent(0, ev1);
	c.addEvent(0, ev2);

	EXPECT_EQ(c.getEvent(0, 0, 1, "Dummy1", "DummyDescr1"), ev1);
	EXPECT_EQ(c.getEvent(0, 100, 200, "Dummy2", "DummyDescr2"), ev2);
	
	c.removeEvent(0, 1);
	EXPECT_EQ(c.sizeOfDay(0), 1);

	EXPECT_EQ(c.getEvent(0, 1), ev2);

	EXPECT_TRUE(!c.empty());

	c.removeEvent(0, 1);
	EXPECT_EQ(c.size(), 0);

	EXPECT_TRUE(c.empty());
	EXPECT_EQ(c.sizeOfDay(0), 0);
	EXPECT_EQ(c.sizeOfDay(1), 0);
}

TEST(CalendarTestSet, dateToDays1) {
	Calendar c;
	EXPECT_EQ(c.dateToDays(1,1), 0);
	EXPECT_EQ(c.dateToDays(1,15), 14);
	EXPECT_EQ(c.dateToDays(1,31), 30);
	EXPECT_EQ(c.dateToDays(2,1), 31);
	EXPECT_EQ(c.dateToDays(2,20), 50);
	EXPECT_EQ(c.dateToDays(2,29), 59);
	EXPECT_EQ(c.dateToDays(12,31), 365);
}

TEST(CalendarTestSet, dateToDays2) {
	Calendar c;
	EXPECT_EQ(c.dateToDays(1,0), -1);
	EXPECT_EQ(c.dateToDays(1,-1), -1);
	EXPECT_EQ(c.dateToDays(0,31), -1);
	EXPECT_EQ(c.dateToDays(2,30), -1);
	EXPECT_EQ(c.dateToDays(2,-20), -1);
	EXPECT_EQ(c.dateToDays(3,34), -1);
	EXPECT_EQ(c.dateToDays(3,34), -1);
	EXPECT_EQ(c.dateToDays(4,33), -1);
	EXPECT_EQ(c.dateToDays(4,31), -1);
	EXPECT_EQ(c.dateToDays(5,32), -1);
	EXPECT_EQ(c.dateToDays(13,12), -1);
	EXPECT_EQ(c.dateToDays(-11,31), -1);
	EXPECT_EQ(c.dateToDays(30,31), -1);
	EXPECT_EQ(c.dateToDays(-42,34), -1);
	EXPECT_EQ(c.dateToDays(11, 31), -1);
}

#endif

