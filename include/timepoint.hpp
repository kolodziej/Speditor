#ifndef SPEDITOR_TIMEPOINT_HPP
#define SPEDITOR_TIMEPOINT_HPP

namespace speditor {

class Timepoint
{
public:
	Timepoint() {}

	void set(long long);
	long long get() const;

	short minute();
	short hour();
	int day();
	short dayOfWeek();
	int week();

private:
	long long time_;

};

}

#endif
