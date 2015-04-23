#ifndef SPEDITOR_TIMEPOINT_HPP
#define SPEDITOR_TIMEPOINT_HPP
#include <type_traits>

namespace speditor {

class Duration;

class Timepoint
{
public:
  Timepoint() :
    time_{-1}
  {}
  Timepoint(long long);
  Timepoint(short hour, short minute, int day = 1, int week = 1);

  void set(long long);
  void set(short hour, short minute, int day = 1, int week = 1);
  long long get() const;

  short minute() const;
  short hour() const;
  int day() const;
  short dayOfWeek() const;
  int week() const;

  Timepoint operator+(Duration) const;
  Timepoint operator-(Duration) const;
  Timepoint& operator+=(Duration);
  Timepoint& operator-=(Duration);

  Timepoint& operator++();
  Timepoint operator++(int);
  Timepoint& operator--();
  Timepoint operator--(int);

  bool operator>(Timepoint) const;
  bool operator>=(Timepoint) const;
  bool operator<(Timepoint) const;
  bool operator<=(Timepoint) const;
  bool operator==(Timepoint) const;
  bool operator!=(Timepoint) const;

  operator bool() const;
  
private:
  long long time_;

};

}

#endif
