#ifndef __DAY_INDEX_HPP__
#define __DAY_INDEX_HPP__

#include "Busyness.hpp"

class DayIndex : public Busyness{
    public:
	DayIndex() : Busyness() {};

	double calculate(int time, int events);

};
#endif
