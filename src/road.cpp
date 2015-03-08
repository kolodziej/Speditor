#include "road.hpp"

namespace speditor {

Road::Road() :
	length_{},
	max_speed_{90},
	average_speed_{90},
	traffic_{0.0},
	destination_{nullptr},
	policy_{nullptr}
{}

Road::Road(NodePtr destination, int length, int max_speed, std::shared_ptr<traffic_policy::Policy> policy) :
	length_{length},
	max_speed_{max_speed},
	average_speed_{max_speed},
	traffic_{0.0},
	destination_{destination},
	policy_{policy}
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
	return static_cast<double>(length()) / (static_cast<double>(averageSpeed()) / 60.0); // time in minutes - convert averageSpeed to km per min
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
