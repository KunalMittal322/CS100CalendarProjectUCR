#include "DayIndex.hpp"	
#include "WeekIndex.hpp"	
#include "MonthIndex.hpp"	
#include "DayTest.hpp"	
#include "WeekTest.hpp"	
#include "EventFactoryTest.hpp"	
#include "AppointmentFactoryTest.hpp"	
#include "ClassFactoryTest.hpp"	
#include "MinuteTest.hpp"	
#include "CalendarTest.hpp"	
int main(int argc, char **argv) {	
  ::testing::InitGoogleTest(&argc, argv);	
  return RUN_ALL_TESTS();	
}
