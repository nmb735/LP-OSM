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
	std::string getName(); //DUBTES RESPECTE A LA IMPLEMENTACI�. NO ACABO D'ENTENDRE QU� DEMANA.
	//
	//Funci� "string getName()"
	//DESCRIPCI�:
	// Funci� que t� com a objectiu retornar el nom del punt d'inter�s. Continuaci� d'una declaraci� virtual de la classe base.
	// 
	//PAR�METRES:
	// -
	// 
	//RETORN:
	// Haur� de retornar el nom base i el tag de la botiga.
	//

	unsigned int getColor();
	//
	//Funci� "unsigned int getColor()"
	//DESCRIPCI�:
	// Funci� que t� com a objectiu retornar el color corresponent del punt d'inter�s. Continuaci� d'una declaraci� virtual de la classe base.
	// 
	//PAR�METRES:
	// -
	// 
	//RETORN:
	// Haur� de retornar el color corresponent.
	//

	//int shopTagToInt();
	//
	//Funci� "unsigned int shopTagToInt()"
	//DESCRIPCI�:
	// Funci� que transforma el valor de m_shopTag (un string) a un enter per poder utilitzar un switch-case.
	// 
	//PAR�METRES:
	// -
	// 
	//RETORN:
	// 1: �s un supermarket
	// 2: �s un estanc
	// 3: �s un forn de pa
	// 4: �s un altre tipus de botiga
	//

	//bool isItWheelchair();
	//
	//Funci� "bool isItWheelchair()"
	//DESCRIPCI�:
	// Funci� que verifica si una botiga est� adaptada per a una cadira de rodes.
	// 
	//PAR�METRES:
	// -
	// 
	//RETORN:
	// TRUE: est� preparada.
	// FALSE: no est� preparada.
	//

	std::string shopTag() const;

	bool isItFullTime();
	//
	//Funci� "bool isItFullTime()"
	//DESCRIPCI�:
	// Funci� que verifica si una botiga est� oberta de 06-22, independentment del dia.
	// 
	//PAR�METRES:
	// -
	// 
	//RETORN:
	// TRUE: est� oberta.
	// FALSE: no est� oberta.
	//

	PuntDeInteresBotigaSolucio* clone() const { return new PuntDeInteresBotigaSolucio(*this); };

	void openingHoursStringToBool(const std::string& s);

	void wheelchairStringToBool(const std::string& s) { (s == "yes") ? m_wheelchair = 1 : m_wheelchair = 0; }

private:
	std::string m_shopType;
	// Atribut de la classe derivada. Ha de prendre el valor del tag de la botiga.
	// Prendr� un valor enter segons el tipus de botiga per evitar redundancies. 0 = default

	bool m_openingHours;
	// Atribut de la classe derivada. Ha de prendre el valor del tag de les hores d'obertura.
	// Tindr� un bool indicant si est� obert en les hores corresponents (06:00 - 22:00)

	bool m_wheelchair;
	// Atribut de la classe derivada. Ha de prendre el valor del tag de si facilita acc�s a cadires de rodes.
	
	
};