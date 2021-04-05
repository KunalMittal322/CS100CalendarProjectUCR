#ifndef __CALENDAR_HPP__
#define __CALENDAR_HPP__
#include <string>
#include <list>
#include <vector>


#include "Event.hpp"

using std::string;
using std::vector;
using std::list;

class Calendar {
protected:
	vector<list<Event*> > calendar;
public:
	Calendar(); //will only have 1 year
	~Calendar();

	list<Event*> getDay(int days) const {return calendar.at(days);}


	void addEvent(int day, Event* event);
	void removeEvent(int days, int eventNumber);

	Event* getEvent(int days, int startTime, int endTime, const string& name, const string& descr) const;
	Event* getEvent(int days, int eventNumber) const;

	bool empty() const;

	int size() const;
	int sizeOfDay(int day) const;
	int dateToDays(int month, int days) const;
};


#endif //__CALENDAR_HPP__
