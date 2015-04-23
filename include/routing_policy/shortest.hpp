#ifndef SPEDITOR_ROUTING_POLICY_SHORTEST_HPP
#define SPEDITOR_ROUTING_POLICY_SHORTEST_HPP

#include "abstract.hpp"

namespace speditor { namespace routing_policy {

class Shortest : public Abstract
{
 public:
  int getRoadWeight(RoadPtr);
};

} }

#endif
