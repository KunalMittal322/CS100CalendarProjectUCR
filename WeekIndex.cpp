#include "WeekIndex.hpp"
#include <cmath>
double WeekIndex::calculate(int time, int events){
    if(time <= 0 || events <= 0)
	return 0;
    return time*sqrt(events)/7;
}
