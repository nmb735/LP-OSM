#pragma once

#include <string>
#include "Common.h"

static const unsigned int DEFAULT_COLOR = 0xFFA500;

class PuntDeInteresBase {

	protected:
		Coordinate m_coord;
		std::string m_name;

	public:		
		PuntDeInteresBase();
		PuntDeInteresBase(Coordinate coord, std::string name);
		PuntDeInteresBase(const PuntDeInteresBase& p);
		virtual PuntDeInteresBase* clone() const { return new PuntDeInteresBase(*this); };
		virtual std::string getName();
		Coordinate getCoord();
		virtual unsigned int getColor();

};