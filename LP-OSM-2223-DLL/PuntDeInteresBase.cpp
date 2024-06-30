#include "pch.h"
#include "PuntDeInteresBase.h"


PuntDeInteresBase::PuntDeInteresBase() {
	this->m_coord = Coordinate{ 0.0, 0.0 };
	this->m_name = "undefinit";
}

PuntDeInteresBase::PuntDeInteresBase(Coordinate coord, std::string name) {
	this->m_name = name;
	this->m_coord = coord;
}

PuntDeInteresBase::PuntDeInteresBase(const PuntDeInteresBase& p)
{
	this->m_coord = p.m_coord;
	this->m_name = p.m_name;
}

Coordinate PuntDeInteresBase::getCoord() {
	return this->m_coord;
}

std::string PuntDeInteresBase::getName() {
	return this->m_name;
}

unsigned int PuntDeInteresBase::getColor() {
	return DEFAULT_COLOR;
}


