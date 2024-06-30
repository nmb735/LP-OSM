#pragma once
#include "MapaBase.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include "CamiSolucio.h"
#include <unordered_map>
#include "Util.h"

class MapaSolucio :
    public MapaBase
{
public:
    MapaSolucio() = default;
    void getPdis(std::vector<PuntDeInteresBase*>& pids);
    void getCamins(std::vector<CamiBase*>& camins);
    void parsejaXmlElements(std::vector<XmlElement>& xmlElements);
private:
    std::unordered_map<unsigned long long int, PuntDeInteresBase*> m_pdis;
    std::unordered_map<unsigned long long int, CamiBase*> m_camins;
    void afegeixNode(const XmlElement& element);
    void afegeixCami(const XmlElement& element);
};

