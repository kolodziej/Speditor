#ifndef SPEDITOR_CITY_HPP
#define SPEDITOR_CITY_HPP
#include "node.hpp"

#include <string>

namespace speditor {

class Map;
class Base;
class ClientCompany;
class Cargo;

using BasePtr = std::shared_ptr<Base>;
using ClientCompanyPtr = std::shared_ptr<ClientCompany>;
using CargoPtr = std::shared_ptr<Cargo>;

class City :
      public Node
{
 public:
  City(std::string, unsigned int = 1000, unsigned int = 1000);

  std::string name();
  std::vector<BasePtr> bases();
  bool addBase(BasePtr);
  std::vector<ClientCompanyPtr> clientCompanies();
  bool addClientCompany(ClientCompanyPtr);

  std::vector<CargoPtr> getAllCargos();

  virtual NodeType type()
  {
    return NodeType::City;
  }
  
 private:
  std::string name_;
  unsigned int max_bases_;
  unsigned int max_client_companies_;

  std::vector<BasePtr> bases_;
  std::vector<ClientCompanyPtr> client_companies_;
};

}

#endif
