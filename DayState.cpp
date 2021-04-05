#include <iostream>
#include "DayState.hpp"

using namespace std;

void DayState::update(const Calendar& calendar, int num) {
    int numDays = num;
    int monthCount = 1;
    int daysToMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    for(int i = 0; i < 11; ++i) {
		numDays -= daysToMonth[i];
		if(numDays < 0) {
		    numDays += daysToMonth[i];
		    break;
		}
		monthCount++;
    }
    cout << monthCount << "/" << numDays + 1 << endl;   

    if(calendar.getDay(num).size() != 0) {
	int count = 1;
	for(auto ev : calendar.getDay(num)) {
	    cout << count << ". " << ev -> getName() << endl;
	    count++;
	}
    }
    else {
	cout << "No events" << endl;
    }
    cout << endl;
}
