#pragma once
#include "CamiBase.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"

class CamiSolucio :
    public CamiBase
{
public:
    CamiSolucio() = default;
    CamiSolucio(const CamiSolucio& cami);
    ~CamiSolucio() = default;
    // Methods
    std::vector<Coordinate> getCamiCoords();
    void afegeixPunt(PuntDeInteresBase* p);
    // Setters
    void setName(const std::string& name) { m_name = name; };
    void setWay(const std::string& highway) { m_highway = highway; };
    void setSurface(const std::string& surface) { m_surface = surface; };
private:
    std::vector<PuntDeInteresBase*> m_way;
    std::string m_name;
    bool m_oneway;
    std::string m_highway;
    std::string m_surface;
};

