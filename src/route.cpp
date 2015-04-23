#include "route.hpp"

#include "node.hpp"
#include "road.hpp"
#include <algorithm>
#include <iostream>

#include "tools/logger.hpp"

namespace speditor {

Route::Route(NodePtr start_node) :
  start_node_(start_node)
{}

Route::Route(NodePtr start_node, std::vector<RoadPtr> roads) :
  start_node_(start_node),
  roads_(roads)
{}

std::vector<RoadPtr> Route::roads() const
{
  return roads_;
}

NodePtr Route::startNode() const
{
  return start_node_;
}

NodePtr Route::endNode() const
{
  if (roads_.empty())
  {
    return nullptr;
  }

  return roads_.back()->destination();
}

Route& Route::operator+=(Route right)
{
  for (auto road : right.roads())
  {
    addRoad_(road);
  }
  return *this;
}

bool Route::continuous() const
{
  if (roads_.empty())
  {
    return true;
  }

  bool c = true;
  NodePtr node = startNode();
  auto road = roads_.begin();
  while (c && road != roads_.end())
  {
    bool in = false;
    for (auto r : node->roads())
    {
      if (r == *road)
      {
        in = true;
        node = r->destination();
        ++road;
        break;
      }
    }
    if (in == false)
    {
      c = false;
    }
  }

  return c;
}

int Route::length() const
{
  int length = 0;
  for (auto r : roads_)
  {
    length += r->length();
  }

  return length;
}

int Route::time() const
{
  int time = 0;
  for (auto r : roads_)
  {
    time += r->time();
  }

  return time;
}
  
void Route::addRoad_(RoadPtr road)
{
  roads_.push_back(road);
}

}
