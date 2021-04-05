#ifndef __EVENT_HPP__
#define __EVENT_HPP__
#include <string>
using std::string;

class Event {
private:
	string tag;
	int startMin;
	int endMin;
	string name;
	string description;
public:
	Event(int startMin, int endMin, const string& name,
		const string& description, const string& tag);
	~Event() {}
	string getTag() const;
	int getStartMin() const;
	int getEndMin() const;
	string getName() const;
	string getDescription() const;
	int getDuration() const;


	void setStartMin(int m);
	void setEndMin(int m);
	void setName(const string& n);
	void setDescription(const string& d);
	string numToTime(int num) const;
	string getDetailed() const ;
};


#endif //__EVENT_HPP__
