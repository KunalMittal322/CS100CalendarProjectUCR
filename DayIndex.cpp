#include "DayIndex.hpp"
#include <cmath>
double DayIndex::calculate(int time, int events){
    if(time <= 0 || events <= 0)
	return 0;
    return time*sqrt(events);
}
