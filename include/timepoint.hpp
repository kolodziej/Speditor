#ifndef SPEDITOR_TIMEPOINT_HPP
#define SPEDITOR_TIMEPOINT_HPP

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

	Timepoint operator+(Timepoint);
	Timepoint operator-(Timepoint);
	Timepoint& operator+=(Timepoint);
	Timepoint& operator-=(Timepoint);

	Timepoint operator+(long long);
	Timepoint operator-(long long);
	Timepoint& operator+=(long long);
	Timepoint& operator-=(long long);
	Timepoint& operator++();
	Timepoint operator++(int);
	Timepoint& operator--();
	Timepoint operator--(int);

	bool operator>(Timepoint);
	bool operator>=(Timepoint);
	bool operator<(Timepoint);
	bool operator<=(Timepoint);
	bool operator==(Timepoint);

	operator bool();

private:
	long long time_;

};

}

#endif
