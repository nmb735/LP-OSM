#pragma once
#include "PuntDeInteresBase.h"

static const unsigned int SUPERMARKET_COLOR = 0xA5BE00;
static const unsigned int TOBACCO_COLOR = 0xFFAD69;
static const unsigned int BAKERY_COLOR = 0xE85D75;
static const unsigned int BAKERY_FULLTIME_WHEELCHAIR = 0x4CB944;


class PuntDeInteresBotigaSolucio :
	public PuntDeInteresBase
{
public:
	PuntDeInteresBotigaSolucio(Coordinate coord,
		std::string name,
		std::string type,
		bool opening,
		bool wheelChair
	) : PuntDeInteresBase(coord, name),
		m_shopType(type),
		m_wheelchair(wheelChair) {
		m_openingHours = opening;
	};
	PuntDeInteresBotigaSolucio(Coordinate coord, std::string name, std::string shop, std::string schedule, std::string wheels);

	PuntDeInteresBotigaSolucio(const PuntDeInteresBotigaSolucio& b);
	std::string getName(); //DUBTES RESPECTE A LA IMPLEMENTACIÓ. NO ACABO D'ENTENDRE QUÉ DEMANA.
	//
	//Funció "string getName()"
	//DESCRIPCIÓ:
	// Funció que té com a objectiu retornar el nom del punt d'interés. Continuació d'una declaració virtual de la classe base.
	// 
	//PARÀMETRES:
	// -
	// 
	//RETORN:
	// Haurà de retornar el nom base i el tag de la botiga.
	//

	unsigned int getColor();
	//
	//Funció "unsigned int getColor()"
	//DESCRIPCIÓ:
	// Funció que té com a objectiu retornar el color corresponent del punt d'interés. Continuació d'una declaració virtual de la classe base.
	// 
	//PARÀMETRES:
	// -
	// 
	//RETORN:
	// Haurà de retornar el color corresponent.
	//

	//int shopTagToInt();
	//
	//Funció "unsigned int shopTagToInt()"
	//DESCRIPCIÓ:
	// Funció que transforma el valor de m_shopTag (un string) a un enter per poder utilitzar un switch-case.
	// 
	//PARÀMETRES:
	// -
	// 
	//RETORN:
	// 1: és un supermarket
	// 2: és un estanc
	// 3: és un forn de pa
	// 4: és un altre tipus de botiga
	//

	//bool isItWheelchair();
	//
	//Funció "bool isItWheelchair()"
	//DESCRIPCIÓ:
	// Funció que verifica si una botiga està adaptada per a una cadira de rodes.
	// 
	//PARÀMETRES:
	// -
	// 
	//RETORN:
	// TRUE: està preparada.
	// FALSE: no està preparada.
	//

	std::string shopTag() const;

	bool isItFullTime();
	//
	//Funció "bool isItFullTime()"
	//DESCRIPCIÓ:
	// Funció que verifica si una botiga està oberta de 06-22, independentment del dia.
	// 
	//PARÀMETRES:
	// -
	// 
	//RETORN:
	// TRUE: està oberta.
	// FALSE: no està oberta.
	//

	PuntDeInteresBotigaSolucio* clone() const { return new PuntDeInteresBotigaSolucio(*this); };

	void openingHoursStringToBool(const std::string& s);

	void wheelchairStringToBool(const std::string& s) { (s == "yes") ? m_wheelchair = 1 : m_wheelchair = 0; }

private:
	std::string m_shopType;
	// Atribut de la classe derivada. Ha de prendre el valor del tag de la botiga.
	// Prendrá un valor enter segons el tipus de botiga per evitar redundancies. 0 = default

	bool m_openingHours;
	// Atribut de la classe derivada. Ha de prendre el valor del tag de les hores d'obertura.
	// Tindrá un bool indicant si està obert en les hores corresponents (06:00 - 22:00)

	bool m_wheelchair;
	// Atribut de la classe derivada. Ha de prendre el valor del tag de si facilita accés a cadires de rodes.
	
	
};