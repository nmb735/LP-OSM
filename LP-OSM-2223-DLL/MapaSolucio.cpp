#include "pch.h"
#include "MapaSolucio.h"

void MapaSolucio::getPdis(std::vector<PuntDeInteresBase*>& pids)
{
	pids.clear();
	for (auto i = m_pdis.begin(); i != m_pdis.end(); i++)
	{
		if (i->second->getName() != "")
		{
			pids.push_back(i->second);
		}
	}
}

void MapaSolucio::getCamins(std::vector<CamiBase*>& camins)
{
	camins.clear();
	for (auto i = m_camins.begin(); i != m_camins.end(); i++)
	{
		camins.push_back(i->second);
	}
}

void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements)
{

	for (auto it = xmlElements.begin(); it != xmlElements.end(); it++)
	{
		if (it->id_element == "node")
			afegeixNode(*it);
		else if (it->id_element == "way")
			afegeixCami(*it);
	}
}

void MapaSolucio::afegeixNode(const XmlElement& element)
{
	unsigned long long int id;
	Coordinate coord;

	bool trobat = false;
	auto it = element.atributs.begin();
	while ((!trobat) && (it != element.atributs.end()))
	{
		if (it->first == "id")
		{
			id = std::stoull(it->second);
		}
		else if (it->first == "lat")
		{
			coord.lat = stod(it->second);
		}
		else if (it->first == "lon")
		{
			coord.lon = stod(it->second);
			trobat = true;
		}
		it++;
	}

	
	if (element.fills.size() > 0)
	{
		std::string name, amenity, shop, schedule, cuisine, wheels;

		name = "";
		amenity = "";
		shop = "";
		schedule = "";
		cuisine = "";
		wheels = "no";

		auto iter = element.fills.cbegin();
		bool trobat = false;
		while ((!trobat) && (iter != element.fills.end()))
		{
			auto valor = *iter;
			std::pair<std::string, std::string> valorTag = Util::kvDeTag(valor.second);
			if (valorTag.first == "name")
			{
				name = valorTag.second;
			}
			else if (valorTag.first == "amenity")
			{
				amenity = valorTag.second;
			}
			else if (valorTag.first == "shop")
			{
				shop = valorTag.second;
			}
			else if (valorTag.first == "opening_hours")
			{
				schedule = valorTag.second;
			}
			else if (valorTag.first == "cuisine")
			{
				cuisine = valorTag.second;
			}
			else if (valorTag.first == "wheelchair")
			{
				wheels = valorTag.second;
			}

			iter++;
		}

		// Tenim un PuntDeInteresRestaurantSolucio
		if (amenity == "restaurant")
		{
			m_pdis.insert({ id, new PuntDeInteresRestaurantSolucio(coord, name, cuisine, wheels) });
		}
		else if (shop != "")
		{
			m_pdis.insert({ id, new PuntDeInteresBotigaSolucio(coord, name, shop, schedule, wheels) });
		}
		else
			m_pdis.insert({ id, new PuntDeInteresBase(coord, name) });

	}
	else
	{
		m_pdis.insert({id, new PuntDeInteresBase(coord, "")});
	}
	
}

void MapaSolucio::afegeixCami(const XmlElement& element)
{
	unsigned long long int id;

	bool trobat = false;
	auto it = element.atributs.begin();
	while ((!trobat) && (it != element.atributs.end()))
	{
		if (it->first == "id")
		{
			id = std::stoull(it->second);
			trobat = true;
		}
		it++;
	}

	CamiSolucio cami;

	auto iter = element.fills.begin();
	auto valor = (*iter).second;
	do
	{
		valor = (*iter).second;
		if (valor.size() > 0)
		{
			
			std::pair<std::string, std::string> valorTag = valor[0];
			unsigned long long int ref;
			if (valorTag.first == "ref")
			{
				ref = std::stoull(valorTag.second);
				cami.afegeixPunt(m_pdis[ref]);
			}
		}
		
		iter++;
	} while (iter->first == "nd" || iter->first == "#text");

	std::string name, highway, surface, oneway;

	name = "";
	highway = "";
	surface = "";
	oneway = "no";

	do
	{
		valor = (*iter).second;
		std::pair<std::string, std::string> valorTag = Util::kvDeTag(valor);

		if (valorTag.first == "name")
		{
			name = valorTag.second;
		}
		else if (valorTag.first == "highway")
		{
			highway = valorTag.second;
		}
		else if (valorTag.first == "surface")
		{
			surface = valorTag.second;
		}
		else if (valorTag.first == "oneway")
		{
			oneway = valorTag.second;
		}

		iter++;
	} while (iter != element.fills.end());

	cami.setName(name);
	cami.setSurface(surface);
	cami.setWay(highway);

	m_camins[id] = new CamiSolucio(cami);
}
