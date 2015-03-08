#ifndef SPEDITOR_TIMEPOINT_HPP
#define SPEDITOR_TIMEPOINT_HPP

namespace speditor {

class Timepoint
{
public:
	Timepoint() {}
	Timepoint(long long);

	void set(long long);
	long long get() const;

	short minute() const;
	short hour() const;
	int day() const;
	short dayOfWeek() const;
	int week() const;

private:
	long long time_;

};

}

#endif
