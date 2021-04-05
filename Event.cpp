#include "Event.hpp"
using std::string;

Event::Event(int startMin, int endMin, const string& name, 
	const string& description, const string& tag) {
	this->startMin = startMin;
	this->endMin = endMin;
	this->name = name;
	this->description = description;
	this->tag = tag;
}

string Event::getTag() const {return tag;}
int Event::getStartMin() const {return startMin;}
int Event::getEndMin() const {return endMin;}
string Event::getName() const {return name;}
string Event::getDescription() const {return description;}
int Event::getDuration() const {return -startMin + endMin;}


void Event::setStartMin(int m) {startMin = m;}
void Event::setEndMin(int m) {endMin = m;}
void Event::setName(const string& n) {name = n;}
void Event::setDescription(const string& d) {description = d;}

string Event::numToTime(int num) const {
  
  string ampm = "";
  if(num / 720 == 0) ampm = " AM";
  else ampm = " PM";
  int hour = num/60 % 12;
  if(hour == 0) hour = 12;
  int actualHour = num/60;
  int minute = num - actualHour*60;
  string minuteString = std::to_string(minute);
  if(minuteString.size() == 1) minuteString = "0" + minuteString;

  return std::to_string(hour) + ":" + minuteString + ampm;
}

string Event::getDetailed() const {
  return name +": "+ numToTime(startMin) +" - " + numToTime(endMin) + ", Type: " +tag +", " + description + "\n";
}