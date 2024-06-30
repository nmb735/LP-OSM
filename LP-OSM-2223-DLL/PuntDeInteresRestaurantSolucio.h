#pragma once

#include "PuntDeInteresBase.h"

static const unsigned int CHINESE_COLOR = 0xA6D9F7; 
static const unsigned int PIZZA_COLOR = 0x03FCBA;
static const unsigned int WHEELCHAIR_COLOR = 0x251351;

class PuntDeInteresRestaurantSolucio :
	public PuntDeInteresBase
{
public:
	PuntDeInteresRestaurantSolucio(Coordinate coord, std::string name, std::string cuisine, bool wheels) :
		PuntDeInteresBase(coord, name), m_cuisine(cuisine), m_wheelchair(wheels) {};

	PuntDeInteresRestaurantSolucio(const PuntDeInteresRestaurantSolucio& res);

	PuntDeInteresRestaurantSolucio(Coordinate coord, std::string name, std::string cuisine, std::string wheels);


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
	// Haur� de retornar el nom base i el tag del restaruant.
	//

	std::string getCuisine() const;

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

	void wheelchairStringToBool(const std::string& s) {(s == "yes") ? m_wheelchair = true : m_wheelchair = false;};

private:
	std::string m_cuisine;
	// Atribut de la classe derivada. Ha de prendre el valor del tag del tipus de cuina.
	// Prendr� un valor enter segons el tipus de botiga per evitar redundancies. 0 = default
	
	bool m_wheelchair;
	//Atribut de la classe derivada. Ha de prendre el valor del tag de si est� adaptat per persones amb mobilitat redu�da.
};