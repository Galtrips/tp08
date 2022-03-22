#pragma once
#include <SDL.h>
#include <vector>
#include <string>
#include "SDL2_gfxPrimitives.h"
#include "Coord.h"

using namespace std;

class Element
{
private:
	string tag;
	vector <coord> tabCoo;
public:
	Element(string t) : tag(t) { ; }
	void addCoord(double lat, double lon);
	string getTag() { return tag; }
};

