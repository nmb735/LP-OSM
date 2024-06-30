#include "pch.h"
#include "CamiSolucio.h"

CamiSolucio::CamiSolucio(const CamiSolucio& cami)
{
    for (int i = 0; i < cami.m_way.size(); i++)
        this->m_way.push_back(cami.m_way[i]);
    this->m_name = cami.m_name;
    this->m_oneway = cami.m_oneway;
    this->m_surface = cami.m_surface;
    this->m_highway = cami.m_highway;
}

std::vector<Coordinate> CamiSolucio::getCamiCoords()
{
    std::vector<Coordinate> coords;
    for (int i = 0; i < m_way.size(); i++)
        coords.push_back(m_way[i]->getCoord());

    return coords;
}

void CamiSolucio::afegeixPunt(PuntDeInteresBase* p)
{
    m_way.push_back(p);
}
