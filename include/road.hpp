#ifndef SPEDITOR_ROAD_HPP
#define SPEDITOR_ROAD_HPP
#include <memory>

#include "traffic_policy/policy.hpp"

namespace speditor {

class Map;
class Node;

using NodePtr = std::shared_ptr<Node>;

class Road
{
 public:
  Road();
  Road(NodePtr, int length = 0, int max_speed = 90, std::shared_ptr<traffic_policy::Policy> policy = nullptr);

  int length() const;
  int maxSpeed() const;
  int averageSpeed() const;
  int time() const;
  double traffic() const;
  NodePtr destination() const;

 private:
  int length_;
  int max_speed_;
  int average_speed_;
  double traffic_;
  NodePtr destination_;
  std::shared_ptr<traffic_policy::Policy> policy_;

  friend class Map;
};

}

#endif
