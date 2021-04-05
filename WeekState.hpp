#ifndef __WEEK_STATE_HPP__
#define __WEEK_STATE_HPP__

#include "ClassObserver.hpp"

class WeekState : public ClassObserver {
    public:
	WeekState() : ClassObserver() { };
	virtual ~WeekState() {}
    void update(const Calendar& calendar, int num);
};

#endif
