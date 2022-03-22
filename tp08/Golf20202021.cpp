// Golf20202021.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <sstream>
#include <SDL.h> //ne pas oublier

#include "Parcours.h"


int main(int argn, char* argv[]) {//entête imposée
								  //ouverture de la SDL

	if (SDL_Init(SDL_INIT_VIDEO != 0)) {
		cout << "Echec à l’ouverture";
		return 1;
	}

	const int WIDTH = 1200;
	const int HEIGHT = 800;
	//on crée la fenêtre
	SDL_Window* win = SDL_CreateWindow("Ma fenetre",
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
	p.afficherSDL(rendu, WIDTH, HEIGHT);
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
	return 0;
}

//int main()
//{
//	/*Joueur BTe("Bruno");
//	Golf leClou("le Clou de Villars");*/
//	Parcours p("le 18 de Villars");
//	/*p.addTrou(new Trou(1, 3));
//	p.addTrou(new Trou(1, 4));
//	p.addTrou(new Trou(1, 5));
//
//	Partie p1(&BTe, &p, "11/02/2021");
//	p1.addScore(4);
//	p1.addScore(3);
//	p1.addScore(8);
//	p1.affiche();*/
//
//	p.loadParcours("GolfClou.osm");
//	
//}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
