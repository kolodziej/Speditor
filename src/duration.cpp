#include "duration.hpp"

namespace speditor {

Duration::Duration(unsigned long long duration) :
  duration_{duration}
{}

Duration Duration::operator+(Duration right) const
{
	return Duration(duration_ + right.duration_);
}

Duration Duration::operator-(Duration right) const
{
	return Duration(duration_ - right.duration_);
}

Duration& Duration::operator+=(Duration right)
{
	duration_ += right.duration_;
	return *this;
}

Duration& Duration::operator-=(Duration right)
{
	duration_ -= right.duration_;
	return *this;
}

void Duration::set(unsigned long long duration)
{
	duration_ = duration;
}

unsigned long long Duration::get() const
{
	return duration_;
}

}
