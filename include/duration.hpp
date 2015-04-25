#ifndef SPEDITOR_DURATION_HPP
#define SPEDITOR_DURATION_HPP

namespace speditor {

class Duration
{
 public:
  Duration(unsigned long long duration);
  
  Duration operator+(Duration) const;
  Duration operator-(Duration) const;
  unsigned long long operator/(Duration) const;
  Duration& operator+=(Duration);
  Duration& operator-=(Duration);

  bool operator==(Duration) const;
  bool operator<(Duration) const;
  bool operator>(Duration) const;
  bool operator<=(Duration) const;
  bool operator>=(Duration) const;
  bool operator!=(Duration) const;

  void set(unsigned long long);
  unsigned long long get() const;

 private:
  unsigned long long duration_;
};

}

#endif
