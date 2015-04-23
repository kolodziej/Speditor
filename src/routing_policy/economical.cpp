#include "routing_policy/economical.hpp"

#include "road.hpp"

namespace speditor { namespace routing_policy {

int Economical::getRoadWeight(RoadPtr road)
{
  return static_cast<double>(road->length()) * 0.7 + (road->maxSpeed() - road->averageSpeed()) * 0.3;
}

} }


