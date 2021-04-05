#include "Calendar.hpp"
#include "Event.hpp"
#include "CalendarInterface.hpp"
#include "ClassObserver.hpp"
#include "DayState.hpp"
#include "WeekState.hpp"
#include "MonthState.hpp"

#include <iostream>
using namespace std;

int main() {
    CalendarInterface tester;
    Calendar calendarObj;
    Event* e = new Event(0, 1, "doctor", "check-up", "2");
    calendarObj.addEvent(0, e);
    calendarObj.addEvent(1, e);
    calendarObj.addEvent(4, e);
    calendarObj.addEvent(31, e);
    calendarObj.addEvent(33, e);
    calendarObj.addEvent(365, e);
    cout << "Testing days..." << endl;
    ClassObserver* obj = new DayState();
    tester.attach(obj);
    cout << "Passing in 0, expecting 1/1" << endl;
    tester.getState(calendarObj, 0);
    cout << "Passing in 50, expecting 2/20" << endl;
    tester.getState(calendarObj, 50);
    cout << "Passing in 365, expecting 12/31" << endl;
    tester.getState(calendarObj, 365);
    
    cout << "Now testing weeks..." << endl;
    ClassObserver* obj2 = new WeekState();
    tester.attach(obj2);
    cout << "Passing in 0, expecting 1/1 - 1/7" << endl;
    tester.getState(calendarObj, 0);
    cout << "Passing in 364, expecting 12/30 - 1/5" << endl;
    tester.getState(calendarObj, 364);
    
    cout << "Now testing months..." << endl;
    ClassObserver* obj3 = new MonthState();
    tester.attach(obj3);
    cout << "Passing in 2, expecting 2/1 - 2/29" << endl;
    tester.getState(calendarObj, 2);
        
    return 0;
}
