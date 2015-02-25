#include "road.hpp"

namespace speditor {

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
	return length() / averageSpeed();
}

NodePtr Road::destination() const
{
	return destination_;
}

}
