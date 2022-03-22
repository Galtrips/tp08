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

	if (SDL_Init(SDL_INIT_VIDEO != 0)) {
		cout << "Echec à l’ouverture";
		return 1;
	}

	const int WIDTH = 1200;
	const int HEIGHT = 800;
	//on crée la fenêtre
	SDL_Window* win = SDL_CreateWindow("Gold d Condeissiat",
		SDL_WINDOWPOS_CENTERED,     //pos. X: autre option: SDL_WINDOWPOS_UNDEFINED
		SDL_WINDOWPOS_CENTERED,     //pos. Y: autre option: SDL_WINDOWPOS_UNDEFINED 
		WIDTH, 			//largeur en pixels			
		HEIGHT, 			//hauteur en pixels
		SDL_WINDOW_SHOWN //d’autres options (plein ecran, resizable, sans bordure...)
	);
	if (win == NULL)
		cout << "erreur ouverture fenetre";

	//Création d’un dessin associé à la fenêtre (1 seul renderer par fenetre)
	SDL_Renderer* rendu = SDL_CreateRenderer(
		win,  //nom de la fenêtre
		-1, //par défaut
		SDL_RENDERER_ACCELERATED); //utilisation du GPU, valeur recommandée





	bool continuer = true;   //booléen fin de programme
	SDL_Event event;// gestion des évènements souris/clavier :SDL_Event est de type struct
	SDL_SetRenderDrawColor(rendu, 185, 185, 185, 255);
	SDL_RenderClear(rendu);
	Parcours p("Gold d Condeissiat");
	p.loadParcours("Condeissiat.osm");
	//p.afficherSDL(rendu, WIDTH, HEIGHT);
	SDL_RenderPresent(rendu);

	while (continuer)
	{
		while (SDL_PollEvent(&event) != 0) {
			switch (event.type) //test du type d’évènement
			{
			case SDL_QUIT: //clic sur la croix de fermeture
					   //on peut enlever SDL_Delay
				continuer = false;
				break;
			}
		}

	}
	//destruction du renderer à la fin
	SDL_DestroyRenderer(rendu);

	//destruction à la fin
	SDL_DestroyWindow(win);   //equivalent du delete

							  //fermeture
	SDL_Quit();

	return EXIT_SUCCESS;
}
