#ifndef __BUSYNESS_HPP__
#define __BUSYNESS_HPP__

#include <vector>
using namespace std;
class Busyness{
    public:
	Busyness() {};

	virtual double calculate(int time, int events) = 0;

};
#endif

