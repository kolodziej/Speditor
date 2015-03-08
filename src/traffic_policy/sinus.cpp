#include "traffic_policy/sinus.hpp"

#include <cmath>

namespace speditor { namespace traffic_policy {

Sinus::Sinus(short rush_hour) :
	rush_hour_{rush_hour}
{}

double Sinus::traffic(Timepoint tp)
{
	return std::abs(std::sin(calcX_(tp.hour())));
}

constexpr double calcX_(short hour)
{
	return (12 - rush_hour_ + hour)*M_PI/24;
}
