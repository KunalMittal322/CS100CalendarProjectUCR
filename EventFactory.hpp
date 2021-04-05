#ifndef __EVENT_FACTORY_HPP__
#define __EVENT_FACTORY_HPP__

#include <string>
#include "Event.hpp"
using std::string;

class EventFactory {
private:

public:
	EventFactory();
	virtual Event* createEvent(int start, int end, 
		const string& name, const string& descr);

};

#endif
