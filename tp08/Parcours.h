#pragma once
#include <vector>
#include <string>
#include <map>
#include <pugixml.hpp>
#include "Element.h"
#include "Coord.h"
#include <iostream>
#include <sstream>

using namespace std;


class Parcours
{
private:
	string nom;
	map <string, coord> map;
	vector <Element*> object;
	void latLon2xy(double lat, double lon, double &x, double &y, double &z);
	
public:
	Parcours(string n) : nom(n) { ; }
	~Parcours();

	void loadParcours(const char* link);
	void addElement(Element& e);
	void readWay(pugi::xml_document& doc, string tag);
};

