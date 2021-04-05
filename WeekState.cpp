#include <iostream>
#include "WeekState.hpp"

using namespace std;

void WeekState::update(const Calendar& calendar, int num) {
    int count = 1;
    int finalNum = num + 7;
    for(int j = num; j < finalNum; ++j) {
	if(j > 365) {
	    j = 0;
	    finalNum = num - 365 + 6;
	}
	int numDays = j;
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

    	if(calendar.getDay(j).size() != 0) {
	    for(auto ev : calendar.getDay(j)) {
	    	cout << count << ". " << ev -> getName() << endl;
	    	count++;
	    }
        }
	else {
	    cout << "No events" << endl;
	}
	cout << endl;
    }  
}
