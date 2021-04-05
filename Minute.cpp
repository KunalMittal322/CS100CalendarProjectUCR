#include "Minute.hpp"

using std::string;

Minute::Minute() {totalMin = -1;}
void Minute::parse(string input) {
/*
Scenarios:
	5AM
	5PM
	5 AM
	5 PM
	0PM
	0AM
	12AM
	12PM
	12:00PM
	5:90 AM
	rules: no miliary time, need am/pm. can be upper or lower 0-12, 0-59
	0PM = 12PM;
	0AM = 12AM;

	first check for AM/PM -> parse and flag, we get a number, or AB:CD
	then check for AB, or just if just 1 number, then hour

*/

	//lowercase everything
	totalMin = -1;
	int ampm = 0;
	int hour = 0;
	int minutes = 0;
	for(unsigned i = 0; i < input.size(); i++) {
		if(input[i] >= 'A' && input[i] <= 'Z') {
			input[i] += 32;
		}
	}
	while(input.at(input.size()-1) == ' ') input.pop_back();
	int s = input.size();
	//find ampm and eliminate
	if(input[s-1] == 'm' && input[s-2] == 'p') {
		ampm = 12*60;
		input.pop_back();
		input.pop_back();
	} else if (input[s-1] == 'm' && input[s-2] == 'a') {
		input.pop_back();
		input.pop_back();
	} else {
		return;
	}

	
	//check whitespace
	while(input.at(input.size()-1) == ' ') {
		input.pop_back();
	}

	s = input.size();
	//check if everything in there is a number

	if(input.size() == 0) return;

	if(input.find(":") == string::npos) {
		//if : doesnt exist
		for(unsigned i = 0; i < input.size(); i++) {
			if(input.at(i) < '0' || input.at(i) > '9') {
				return;
			}
		}
		//if : doesnt exist, then it is hour
		hour = std::stoi(input);
		if(hour > 12) return;
		hour %= 12;
	} else {
		//has :
		//extract minutes

		if(input.size() < 4) return; //X:XX

		if(input.at(s-3) == ':') {
			if((input.at(s-1) >= '0' && input.at(s-1) <= '9')
				&& (input.at(s-2) >= '0' && input.at(s-2) <= '9')) {
				minutes += (int) input.at(s-1) - '0';
				minutes += 10 * ((int) input.at(s-2) - '0');
				if(minutes >= 60) return;
				input.pop_back();
				input.pop_back();
				input.pop_back(); //pops :
			} else return;
		} else return;
		//now do hour
		if(input.size() == 1 || input.size() == 2) {
			for(unsigned i = 0; i < input.size(); i++) {
				if(input.at(i) < '0' || input.at(i) > '9') {
					return;
				}
			}

			hour = std::stoi(input);
			if(hour > 12) return;
			hour %= 12;

		}
	}

	totalMin = hour * 60 + minutes + ampm;


	//further implementation
}

int Minute::getMinute() const {return totalMin;}