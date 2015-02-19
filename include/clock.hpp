#ifndef SPEDITOR_CLOCK_HPP
#define SPEDITOR_CLOCK_HPP

namespace speditor {

class Timepoint;

class Clock
{
public:
	Clock(int);
	Timepoint timepoint() const;
private:
	const int minute_duration_;
	long long time_;
};

}

#endif
