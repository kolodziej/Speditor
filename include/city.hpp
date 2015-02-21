#ifndef SPEDITOR_CITY_HPP
#define SPEDITOR_CITY_HPP
#include "node.hpp"

#include <string>

namespace speditor {

class Base;
class ClientCompany;

class City :
	public Node
{
public:
	City(std::string, int, int);

	std::string name();
	std::vector<std::shared_ptr<Base>> bases();
	bool addBase(std::shared_ptr<Base>);
	std::vector<std::shared_ptr<ClientCompany>> clientCompanies();
	bool addClientCompany(std::shared_ptr<ClientCompany>);

	virtual NodeType type()
	{
		return NodeType::City;
	}
	
private:
	std::string name_;
	int max_bases_;
	int max_client_companies_;

	std::vector<std::shared_ptr<Base>> bases_;
	std::vector<std::shared_ptr<ClientCompany>> client_companies_;

};

}

#endif
