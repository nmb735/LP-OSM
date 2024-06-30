#include "pch.h"
#include "PuntDeInteresRestaurantSolucio.h"

PuntDeInteresRestaurantSolucio::PuntDeInteresRestaurantSolucio(const PuntDeInteresRestaurantSolucio& res)
	: PuntDeInteresBase(res)
{
	this->m_cuisine = res.m_cuisine;
	this->m_wheelchair = res.m_wheelchair;
}

PuntDeInteresRestaurantSolucio::PuntDeInteresRestaurantSolucio(Coordinate coord, std::string name, std::string cuisine, std::string wheels) : PuntDeInteresBase(coord, name)
{

	m_cuisine = cuisine;

	wheelchairStringToBool(wheels);
}

std::string PuntDeInteresRestaurantSolucio::getCuisine() const
{
	return m_cuisine;
}

std::string PuntDeInteresRestaurantSolucio::getName()
{
	std::string firstPart = PuntDeInteresBase::getName();

	std::string secondPart = getCuisine();

	std::string separation = ": ";

	std::string result = firstPart + separation;

	result = result + secondPart;

	return result;
}


unsigned int PuntDeInteresRestaurantSolucio::getColor()
{
	if (m_cuisine == "chinese")
		return CHINESE_COLOR;
	else
	{
		if (m_wheelchair)
		{
			if (m_cuisine == "pizza")
				return PIZZA_COLOR;
			else
				return WHEELCHAIR_COLOR;
		}

		else
			return (PuntDeInteresBase::getColor());
	}
}