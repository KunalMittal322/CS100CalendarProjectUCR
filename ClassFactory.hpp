#ifndef __CLASS_FACTORY_HPP__
#define __CLASS_FACTORY_HPP__

#include "EventFactory.hpp"

class ClassFactory : public EventFactory {
private:

public:
	ClassFactory();
	Event* createEvent(int start, int end, 
		const string& name, const string& descr);
};


#endif //__CLASS_FACTORY_HPP__