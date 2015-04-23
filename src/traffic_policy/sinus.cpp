#include "traffic_policy/sinus.hpp"

#include <stdexcept>
#include <cmath>
#include "timepoint.hpp"

namespace speditor { namespace traffic_policy {

Sinus::Sinus(short rush_hour, double a, double b) :
  rush_hour_{rush_hour},
  a_{a},
  b_{b}
{
  if (a > 1.0)
  {
    throw std::logic_error("Sinus policy: a > 1.0!");
  }
}

double Sinus::traffic(Timepoint tp)
{
  return std::abs(a_*std::sin(b_*calcX_(tp.hour())));
}

double Sinus::calcX_(short hour)
{
  return (12 - rush_hour_ + hour)*M_PI/24;
}

} }
