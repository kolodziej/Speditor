#include "city.hpp"
#include "node.hpp"

namespace speditor {

City::City(std::string name, unsigned int max_bases, unsigned int max_client_companies) :
  name_{name},
  max_bases_{max_bases},
  max_client_companies_{max_client_companies}
{}

std::string City::name()
{
  return name_;
}

std::vector<BasePtr> City::bases()
{
  return bases_;
}

bool City::addBase(BasePtr base)
{
  if (bases_.size() < max_bases_)
  {
    bases_.push_back(base);
    return true;
  }

  return false;
}

std::vector<ClientCompanyPtr> City::clientCompanies()
{
  return client_companies_;
}

bool City::addClientCompany(ClientCompanyPtr client_company)
{
  if (client_companies_.size() < max_client_companies_)
  {
    client_companies_.push_back(client_company);
    return true;
  }

  return false;
}

}
