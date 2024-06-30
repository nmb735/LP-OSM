#include "pch.h"
#include "PuntDeInteresBotigaSolucio.h"

PuntDeInteresBotigaSolucio::PuntDeInteresBotigaSolucio(const PuntDeInteresBotigaSolucio& b) : PuntDeInteresBase(b)
{
	m_openingHours = b.m_openingHours;
	this->m_shopType = b.m_shopType;
	this->m_wheelchair = b.m_wheelchair;
}

PuntDeInteresBotigaSolucio::PuntDeInteresBotigaSolucio(Coordinate coord, std::string name, std::string shop, std::string schedule, std::string wheels) : PuntDeInteresBase(coord, name)
{
	openingHoursStringToBool(schedule);
	wheelchairStringToBool(wheels);
	m_shopType = shop;
}

void PuntDeInteresBotigaSolucio::openingHoursStringToBool(const std::string& s)
{
	if (s.find("06:00-22:00") != std::string::npos)
		m_openingHours = 1;
	else
		m_openingHours = 0;
}



std::string PuntDeInteresBotigaSolucio::getName()
{
	std::string firstPart = PuntDeInteresBase::getName();

	std::string secondPart = shopTag();

	std::string separation = ": ";

	std::string result = firstPart + separation;

	result = result + secondPart;

	return result;
}

/*int PuntDeInteresBotigaSolucio::shopTagToInt()
{
	if (m_shopTag == "supermarket")
		return 1;
	else
	{
		if (m_shopTag == "tobacco")
			return 2;

		else
		{
			if (m_shopTag == "bakery")
				return 3;
			else
				return 4;
		}
	}
}*/

/*bool PuntDeInteresBotigaSolucio::isItWheelchair()
{
	if (m_wheelchairTag == "yes")
		return true;

	else
		return false;
}*/

std::string PuntDeInteresBotigaSolucio::shopTag() const
{
	return m_shopType;
}

bool PuntDeInteresBotigaSolucio::isItFullTime()
{
	return m_openingHours;
}

unsigned int PuntDeInteresBotigaSolucio::getColor()
{

	if (m_shopType == "supermarket")
	{
		return SUPERMARKET_COLOR;
	}
	else if (m_shopType == "tobacco")
	{
		return TOBACCO_COLOR;
	}
	else if (m_shopType == "bakery")
	{
		if (m_wheelchair && isItFullTime())
			return BAKERY_FULLTIME_WHEELCHAIR;
		else
			return BAKERY_COLOR;
	}
	else
	{
		return DEFAULT_COLOR;
	}
}