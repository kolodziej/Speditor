#include "timepoint.hpp"

#include <cmath>
#include "clock.hpp"

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

Timepoint Timepoint::operator+(Timepoint right)
{
	return Timepoint(get() + right.get());
}

Timepoint Timepoint::operator-(Timepoint right)
{
	return Timepoint(get() + right.get());
}

Timepoint& Timepoint::operator+=(Timepoint right)
{
	time_ += right.get();
	return *this;
}

Timepoint& Timepoint::operator-=(Timepoint right)
{
	time_ -= right.get();
	return *this;
}

Timepoint& Timepoint::operator+=(long long add)
{
	time_ += add;
	return *this;
}

Timepoint& Timepoint::operator-=(long long subtract)
{
	time_ -= subtract;
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

}
