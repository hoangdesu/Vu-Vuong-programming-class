#ifndef TASK_H
#define TASK_H

#include <string>

#include <iostream>
#include <iomanip>
#include <sstream>

class Time {
   private:
      int hours;
      int minutes;
      int seconds;

   public:
    //   constructors
      Time(); 
      Time(int h, int m, int s);  

      int GetHours() const;
      int GetMinutes() const;
      int GetSeconds() const;
      void TimeDifference(const Time& end, const Time& start);
};

#endif