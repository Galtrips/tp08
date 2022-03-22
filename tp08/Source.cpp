#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


#include "Parcours.h"

int main(int argc, char* argv[]) {

	Parcours p1 ("Parcours");

	p1.loadParcours("Condeissiat.osm");

	return EXIT_SUCCESS;
}
