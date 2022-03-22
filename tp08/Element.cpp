#include "Element.h"
#include <iostream>
#include "Coord.h"
using namespace std;

void Element::addCoord(double lat, double lon) {
	coord co;
	co.Lat = lat;
	co.Lon = lon;
	tabCoo.push_back(co);
}