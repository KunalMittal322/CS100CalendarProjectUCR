#ifndef __WEEK_INDEX_HPP__
#define __WEEK_INDEX_HPP__

#include "Busyness.hpp"

class WeekIndex : public Busyness{
    public:
        WeekIndex() : Busyness() {};
        double calculate(int time, int events);

};
#endif

