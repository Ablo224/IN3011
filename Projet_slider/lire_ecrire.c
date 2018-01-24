#include <stdio.h>
#include <stdlib.h>
#include "mes_constantes.h"
#include "mes_types.h"
#include "list.h"
#include "lire_ecrire.h"

void init_grille(SLIDER S){

	//initialisation du tableau grille
	for(int i=0;i<S.L;i++)
	{
		for(int j=0;j<S.H;j++)
		{
			S.grille[i][j].haut = VIDE;
			S.grille[i][j].bas = VIDE;
			S.grille[i][j].gauche = VIDE;
			S.grille[i][j].droite = VIDE;
		}
	}
} 

SLIDER lire_slider(char *nom) {
	FILE *F;
	int di,ret,tmp,x,y;
	x=0; y=0;
	F = fopen(nom,"r");
	if(F==NULL)
	{
		printf("probleme d'ouveture\n");
		exit(1);
	}
	SLIDER S;
	ret = fscanf(F,"%d",&tmp); S.L = tmp;
	ret = fscanf(F,"%d",&tmp); S.H = tmp;
	ret = fscanf(F,"%d",&tmp); S.slid.x = tmp;
	ret = fscanf(F,"%d",&tmp); S.slid.y = tmp;
	ret = fscanf(F,"%d",&tmp); S.sortie.x = tmp;
	ret = fscanf(F,"%d",&tmp); S.sortie.y = tmp;
	ret = fscanf(F,"%d",&tmp); S.N = tmp;
	//Création de la liste qui gère le UNDO
	S.retour = Create_list();
	//initialisation du tableau grille de la structure SLIDER
	init_grille(S);
	//recuperation des coordonnées des cases
	while(ret != -1)
	{
		ret = fscanf(F,"%d",&x);
		ret = fscanf(F,"%d",&y);
		ret = fscanf(F,"%d",&di);
		if(di == 3){S.grille[x][y].droite = 1; }
		if(di == 9){S.grille[x][y].gauche = 1; }
		if(di == 0){S.grille[x][y].haut = 1; }
		if(di == 6){S.grille[x][y].bas = 1; }
	}
	fclose(F);
	return S;
}



void ecrire_slider_dans_fichier(SLIDER S, char*nom) {
	FILE *fichier ;//= NULL;
	fichier =  fopen(nom, "w");
	
	fprintf(fichier,"%d %d\n",S.L,S.H);
	fprintf(fichier,"%d %d\n",S.slid.x,S.slid.y);
	fprintf(fichier,"%d %d\n",S.sortie.x,S.sortie.y);
	fprintf(fichier,"%d\n",S.N);
	
	for(int x=0;x<S.L;x++)
	{
		for(int y=0;y<S.H;y++)
		{
			if(S.grille[x][y].haut == 1){ fprintf(fichier,"%d %d %d\n",x,y,HAUT);}
			if(S.grille[x][y].bas == 1){ fprintf(fichier,"%d %d %d\n",x,y,BAS);}
			if(S.grille[x][y].droite == 1){ fprintf(fichier,"%d %d %d\n",x,y,DROIT);}
			if(S.grille[x][y].gauche == 1){ fprintf(fichier,"%d %d %d\n",x,y,GAUCHE);}
		}
	}
	fclose(fichier);
}
