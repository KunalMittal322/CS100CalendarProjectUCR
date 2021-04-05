#ifndef __APPOINTMENT_FACTORY_HPP__
#define __APPOINTMENT_FACTORY_HPP__

#include "EventFactory.hpp"

class AppointmentFactory : public EventFactory {
private:

public:
	AppointmentFactory();
	Event* createEvent(int start, int end,
	 const string& name, const string& descr);
};


#endif //__APPOINTMENT_FACTORY_HPP__
