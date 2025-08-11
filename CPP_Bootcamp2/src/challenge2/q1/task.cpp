#include "task.h"

#include <string>

#include <iostream>
#include <iomanip>
#include <sstream>

Time::Time() {}

// Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}
Time::Time(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;
}

int Time::GetHours() const {
    return hours;
}


int Time::GetMinutes() const {
    return minutes;
}


int Time::GetSeconds() const {
    return seconds;
}

void Time::TimeDifference(const Time& end, const Time& start) {
    // seconds
    seconds = end.GetSeconds();
    minutes = end.GetMinutes();
    hours = end.GetHours();

    if (seconds < start.GetSeconds())
    {
        // borrow 60 seconds (or 1 full minute) from minute
        seconds = seconds + 60 - start.GetSeconds();
        minutes -= 1;
    } else {
        seconds -= start.GetSeconds();
    }

    // minutes
    if (minutes < start.GetMinutes())
    {
        minutes = minutes + 60 - start.GetMinutes();
        hours -= 1;
    } else {
        minutes -= start.GetMinutes();
    }

    // hours
    if (hours < start.GetHours())
    {
        // borrow 1 full day (24 hours)
        hours = hours + 24 - start.GetHours();
    } else {
        hours -= start.GetHours();
    }
}

// 4:15:50 - 2:55:10

// s = 50 - 10 = 40
// m = 75 - 55 = 20
// h = 3 - 2 = 1
// => 1:20:40

// start = 2:15:50 AM
// end = 2:10:40 AM

//   2:10:40
// - 2:15:50

// s = 40-50 => 50
// m = (10-1) - 15 = 9-15 => 69-15 = 54
// h = (2-1) - 2 = 1-2 => (24+1) - 2 = 23

// 23:54:50