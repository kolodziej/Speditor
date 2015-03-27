#ifndef SPEDITOR_TIMEPOINT_HPP
#define SPEDITOR_TIMEPOINT_HPP
#include <type_traits>

namespace speditor {

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

	template <typename Integer,
		typename std::enable_if<std::is_integral<Integer>::value, Integer>::type>
	Timepoint operator+(Integer) const;

	template <typename Integer,
		typename std::enable_if<std::is_integral<Integer>::value, Integer>::type>
	Timepoint operator-(Integer) const;

	template <typename Integer,
		typename std::enable_if<std::is_integral<Integer>::value, Integer>::type>
	Timepoint& operator+=(Integer);

	template <typename Integer,
		typename std::enable_if<std::is_integral<Integer>::value, Integer>::type>
	Timepoint& operator-=(Integer);

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

	template <typename Integer,
		typename std::enable_if<std::is_integral<Integer>::value, Integer>::type>
	operator Integer() const;


private:
	long long time_;

};

}

#include "impl/timepoint.hpp"

#endif
