#include "AppointmentFactory.hpp"

AppointmentFactory::AppointmentFactory() : EventFactory() {};

Event* AppointmentFactory::createEvent(int start, int end, const string& name, const string& descr) {
	return new Event(start, end, name, descr, "Appointment");
}
