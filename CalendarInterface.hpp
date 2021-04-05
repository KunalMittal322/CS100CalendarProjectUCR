#ifndef __CALENDAR_INTERFACE_HPP__
#define __CALENDAR_INTERFACE_HPP__

#include "ClassObserver.hpp"
#include "DayState.hpp"
#include "WeekState.hpp"
#include "MonthState.hpp"

class CalendarInterface {
    public:
	CalendarInterface() { };

	void attach(ClassObserver* Obs);
	void getState(const Calendar& c, int num1);
    private:
	ClassObserver* stateObj;

	
};

#endif
