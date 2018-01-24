#include <uvsqgraphics.h>
#include "list.h"
#define NMAX 100

#ifndef ___MESTYPES_H
#define ___MESTYPES_H



struct Case{
	int haut;
	int bas;
	int gauche;
	int droite;
};

typedef struct Case CASE;



struct slider {
	int L,H; // Largeur et hauteur de la grille
	POINT sortie;
	POINT slid;
	int N;//nombre de murs
	int cout;
	CASE grille[NMAX][NMAX];
	UNDO retour;
	
};
typedef struct slider SLIDER;

struct action{
	int mode;
};
typedef struct action ACTION;

#endif





