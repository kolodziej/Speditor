#include "road.hpp"

namespace speditor {

Road::Road() :
	length_{},
	max_speed_{90},
	average_speed_{60},
	traffic_{1.00},
	destination_{nullptr}
{}

Road::Road(NodePtr destination, int length, int max_speed, int average_speed, double traffic) :
	length_{length},
	max_speed_{max_speed},
	average_speed_{average_speed},
	traffic_{traffic},
	destination_{destination}
{}

int Road::length() const
{
	return length_;
}

int Road::maxSpeed() const
{
	return max_speed_;
}

int Road::averageSpeed() const
{
	return average_speed_;
}

int Road::time() const
{
	return static_cast<double>(length()) / (static_cast<double>(averageSpeed()) / 60.0);
}

double Road::traffic() const
{
	return traffic_;
}

NodePtr Road::destination() const
{
	return destination_;
}

}
