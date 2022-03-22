#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include<SDL.h>
#include <SDL_ttf.h>
#include "config_sdl.h"

using namespace std;


#include "Parcours.h"

int main(int argc, char* argv[]) {

	Parcours p1 ("Parcours");

	p1.loadParcours("Condeissiat.osm");

	return EXIT_SUCCESS;
}
