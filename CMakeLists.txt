CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(print_test
    Calendar.cpp
    Event.cpp
    CalendarInterface.cpp
    DayState.cpp
    WeekState.cpp
    MonthState.cpp
    testing_main.cpp
)

ADD_EXECUTABLE(test
DayIndex.cpp	
    WeekIndex.cpp	
    MonthIndex.cpp	
    Event.cpp
Calendar.cpp
AppointmentFactory.cpp
ClassFactory.cpp
EventFactory.cpp
Minute.cpp
test.cpp


)

ADD_EXECUTABLE(main
DayIndex.cpp
    WeekIndex.cpp
    MonthIndex.cpp
    Event.cpp
Calendar.cpp
AppointmentFactory.cpp
ClassFactory.cpp
EventFactory.cpp
Minute.cpp
    CalendarInterface.cpp
    DayState.cpp
    WeekState.cpp
    MonthState.cpp
client.cpp


)


TARGET_LINK_LIBRARIES(test gtest)

TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
