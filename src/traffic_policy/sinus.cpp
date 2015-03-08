#include "traffic_policy/sinus.hpp"

#include <cmath>

namespace speditor { namespace traffic_policy {

double Sinus::traffic(Timepoint tp)
{
	return sin(calcX_(tp.hour()));
}

constexpr double calcX_(short hour)
{
	return hour*M_PI/24;
}
