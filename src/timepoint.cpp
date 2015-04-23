#include "timepoint.hpp"

#include <sstream>
#include <cmath>
#include "clock.hpp"
#include "duration.hpp"

#include "tools/logger.hpp"

namespace speditor {

Timepoint::Timepoint(long long time) :
  time_{time}
{}

Timepoint::Timepoint(short hour, short minute, int day, int week) :
  time_{0}
{
	set(hour, minute, day, week);
}

void Timepoint::set(long long time)
{
	time_ = time;
}

void Timepoint::set(short hour, short minute, int day, int week)
{
	time_ = 0;
	time_ += minute;
	time_ += hour * 60;
	time_ += (day - 1) * 60 * 24;
	time_ += (week - 1) * 60 * 24 * 7;
}

long long Timepoint::get() const
{
	return time_;
}

short Timepoint::minute() const
{
	return time_ % 60;
}

short Timepoint::hour() const
{
	return static_cast<int>(time_ / 60) % 24;
}

int Timepoint::day() const
{
	return static_cast<int>(time_ / 1440) + 1;
}

short Timepoint::dayOfWeek() const
{
	return (day()-1) % 7;
}

int Timepoint::week() const
{
	return static_cast<int>(time_ / 10080) + 1;
}

Timepoint Timepoint::operator+(Duration right) const
{
	return Timepoint(time_ + right.get());
}

Timepoint Timepoint::operator-(Duration right) const
{
	return Timepoint(time_ - right.get());
}

Timepoint& Timepoint::operator+=(Duration right)
{
	time_ += right.get();
	return *this;
}

Timepoint& Timepoint::operator-=(Duration right)
{
	time_ -= right.get();
	return *this;
}

Timepoint& Timepoint::operator++()
{
	++time_;
	return *this;
}

Timepoint Timepoint::operator++(int /*unused*/)
{
	Timepoint tp = *this;
	++time_;
	return tp;
}

Timepoint& Timepoint::operator--()
{
	--time_;
	return *this;
}

Timepoint Timepoint::operator--(int /*unused*/)
{
	Timepoint tp = *this;
	--time_;
	return tp;
}

bool Timepoint::operator>(Timepoint right) const
{
	return time_ > right.get();
}

bool Timepoint::operator>=(Timepoint right) const
{
	return time_ >= right.get();
}

bool Timepoint::operator<(Timepoint right) const
{
	return time_ < right.get();
}

bool Timepoint::operator<=(Timepoint right) const
{
	return time_ <= right.get();
}

bool Timepoint::operator==(Timepoint right) const
{
	LogDetail("Using Timepoint::operator==");
	return time_ == right.get();
}

bool Timepoint::operator!=(Timepoint right) const
{
	return time_ != right.get();
}

Timepoint::operator bool() const
{
	return time_ != -1;
}

}
