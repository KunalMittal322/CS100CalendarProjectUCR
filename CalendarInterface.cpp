#include <iostream>
#include "CalendarInterface.hpp"

void CalendarInterface::attach(ClassObserver* Obs) {
    stateObj = Obs;
}

void CalendarInterface::getState(const Calendar& c, int num1) {  
    stateObj->update(c, num1);
}
