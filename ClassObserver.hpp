#ifndef __CLASS_OBSERVER_HPP__
#define __CLASS_OBSERVER_HPP__

#include "Calendar.hpp"
#include "Event.hpp"

using namespace std;

class ClassObserver {
    public:
	ClassObserver() { };
	virtual ~ClassObserver() {};
	virtual void update(const Calendar& calendar, int num) = 0;
};

#endif
