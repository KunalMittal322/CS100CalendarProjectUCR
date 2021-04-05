#include "Calendar.hpp"


using std::string;
using std::vector;
using std::list;
//private:
//vector<list<Event*> > calendar;

	int Calendar::dateToDays(int month, int days) const {
		int daysTilMonth[] = {-1, 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};

		for(int i = 1; i < 13; i++) {
			daysTilMonth[i] += daysTilMonth[i-1];
		} //running sum

		if(month < 1 || month > 12) {
			return -1;
		} else {
			if(month == 2) {
				if(days > 29 || days < 1) return -1;
			} else if(month == 4 || month == 6 || month == 9 || month == 11) {
				if(days > 30 || days < 1) return -1;
			} else {
				if(days > 31 || days < 1) return -1;
			}
		}

		return daysTilMonth[month] + days;
	}
//public:
	
	Calendar::Calendar() {
		calendar.resize(366); //This will be a 2020 calendar
	} //will only have 1 year

	Calendar::~Calendar() {
		for(auto l : calendar) {
			if(l.size() != 0) {
				for(auto ev : l) {
					if(ev) delete ev;
				}
			}
		}
	}

	void Calendar::addEvent(int days, Event* event) {
		calendar.at(days).push_back(event);
	}

	void Calendar::removeEvent(int days, int eventNumber) {
		eventNumber--;
		
		if(calendar.at(days).size() <= eventNumber) {
			return;
		}
		auto it = calendar.at(days).begin();
		unsigned i = 0;
		while(i < eventNumber) {
			it++;
			i++;
		}

		delete *it;
		calendar.at(days).erase(it);
	}

	Event* Calendar::getEvent(int days, int startTime, int endTime, const string& name, const string& descr) const{
		for(auto it : calendar.at(days)) {
			if(it->getStartMin() == startTime && it->getEndMin() == endTime && it->getName() == name && it->getDescription() == descr) {
				return it;
			}
		}
		return nullptr;
	}

	Event* Calendar::getEvent(int days, int eventNumber) const {
		//if user sees 1-9, first event is 0, last event is 8
		eventNumber--;
		
		if(calendar.at(days).size() <= eventNumber) {
			return nullptr;
		}
		auto it = calendar.at(days).begin();
		unsigned i = 0;
		while(i < eventNumber) {
			it++;
			i++;
		}
		return *it;
	}

	bool Calendar::empty() const {
		for(unsigned i = 0; i < 366; i++) {
			if(!calendar.at(i).empty()) return false;
		}
		return true;
	}

	int Calendar::size() const {
		int size = 0;
		for(unsigned i = 0; i < 366; i++) {
			size += calendar.at(i).size();
		}
		return size;
	}
	int Calendar::sizeOfDay(int day) const {
		return calendar.at(day).size();
		
	}
