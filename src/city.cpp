#include "city.hpp"
#include "node.hpp"

namespace speditor {

City::City(std::string name, int max_bases, int max_client_companies) :
	name_(name),
	max_bases_(max_bases),
	max_client_companies_(max_client_companies)
{}

std::string City::name()
{
	return name_;
}

std::vector<std::shared_ptr<Base>> City::bases()
{
	return bases_;
}

bool City::addBase(std::shared_ptr<Base> base)
{
	if (bases_.size() < max_bases_)
	{
		bases_.push_back(base);
		return true;
	}

	return false;
}

std::vector<std::shared_ptr<ClientCompany>> City::clientCompanies()
{
	return client_companies_;
}

bool City::addClientCompany(std::shared_ptr<ClientCompany> client_company)
{
	if (client_companies_.size() < max_client_companies_)
	{
		client_companies_.push_back(client_company);
		return true;
	}

	return false;
}

}
