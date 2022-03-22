#include <map>
#include <iostream>
#include <sstream>
#define _USE_MATH_DEFINES
#include <math.h>

#include <string>
#include <iostream>
#include <fstream>
#include "Element.h"
#include "Parcours.h"
#include "Coord.h"
using namespace std;


void Parcours::latLon2xy(double lat, double lon, double &y, double &x, double &z) {

	double earthRadius = 6378;
	double theta = M_PI / 2 - lat * M_PI / 180;
	double phi = lon * M_PI / 180;


	x = earthRadius * sin(theta)*cos(phi);
	y = earthRadius * sin(theta)*sin(phi);
	z = earthRadius * cos(lat);


}

void Parcours::loadParcours(const char* link) {
	
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(link);

	auto nodes = doc.select_nodes("/osm/node");
	for (auto n : nodes) {
		coord geo;
		geo.Lat = n.node().attribute("lat").as_double();
		geo.Lon = n.node().attribute("lon").as_double();
		auto id = n.node().attribute("id").as_string();
		map.insert(pair <string, coord>(id, geo));
	}
	vector <string> ways;
	ways.push_back("fairway");
	ways.push_back("bunker");
	ways.push_back("water");
	ways.push_back("green");
	ways.push_back("building");
	
	for (auto i : ways) {
		readWay(doc, i);
	}

	cout << object.size();
}

void Parcours::addElement(Element& e) {
	object.push_back(&e);
}

void Parcours::readWay(pugi::xml_document& doc, string tag) {
	
	auto nodes = doc.select_nodes("/osm/way");
	for (auto n : nodes) {

		auto tags = n.node().select_nodes("tag");
		
		for (auto t : tags) {
			string value = t.node().attribute("k").as_string();
			string value2 = t.node().attribute("v").as_string();
			if (value == tag || value2 == tag) {

				object.push_back(new Element (tag));
				auto nd = n.node().select_nodes("nd");
				for (auto n : nd) {
					
					string ref = n.node().attribute("ref").as_string();
					double Lat = map.find(ref)->second.Lat;
					double Lon = map.find(ref)->second.Lon;
					object.back()->addCoord(Lat, Lon);
				}
			}
		}
	}
}


Parcours::~Parcours() {
	for (auto i : object) {
		delete i;
	}
}