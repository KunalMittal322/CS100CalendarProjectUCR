#ifndef __MONTH_INDEX_HPP__
#define __MONTH_INDEX_HPP__

#include "Busyness.hpp"

class MonthIndex : public Busyness{
    public:
        MonthIndex() : Busyness() {};
        double calculate(int time, int events);

};
#endif                                                                 
