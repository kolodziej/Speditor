#ifndef SPEDITOR_TIMEPOINT_HPP
#define SPEDITOR_TIMEPOINT_HPP

namespace speditor {

class Clock;

class Timepoint
{
public:
	Timepoint(const Clock&);

	void set(long long);
	long long get() const;

	short minute();
	short hour();
	int day();
	short dayOfWeek();
	int week();

private:
	const Clock& clock_;
	long long time_;

};

}

#endif
