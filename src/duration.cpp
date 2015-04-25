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

unsigned long long Duration::operator/(Duration right) const
{
  return get() / right.get();
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

bool Duration::operator==(Duration right) const
{
  return get() == right.get();
}

bool Duration::operator<(Duration right) const
{
  return get() < right.get();
}

bool Duration::operator>(Duration right) const
{
  return get() > right.get();
}

bool Duration::operator<=(Duration right) const
{
  return get() <= right.get();
}

bool Duration::operator>=(Duration right) const
{
  return get() >= right.get();
}

bool Duration::operator!=(Duration right) const
{
  return get() != right.get();
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
