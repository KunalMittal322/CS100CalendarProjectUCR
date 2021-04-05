#include "EventFactory.hpp"

EventFactory::EventFactory() {}

Event* EventFactory::createEvent(int start, int end, const string& name, const string& descr) {
	return new Event(start, end, name, descr, "");
}
