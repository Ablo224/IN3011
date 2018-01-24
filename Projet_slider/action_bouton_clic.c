#include <uvsqgraphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "mes_types.h"
#include "list.h"
#include "lire_ecrire.h"
#include "afficher.h"
#include "mes_constantes.h"




//fonction qui attend qu'on fasse un clic ou qu'on appuis sur une flèche ou une touche
ACTION Recupe_Action(SLIDER S,char* touch,int* flech,POINT* P){
	
	int ret=0;
	ret = wait_key_arrow_clic(touch,flech,P);
	
	ACTION A;
	A.mode = VIDE; 
	if(ret == EST_FLECHE)
	{
			A.mode = JOUER;
			return A;
	}
	if(ret == EST_TOUCHE)
	{
		if(*touch == 'S'){A.mode = SAVE; return A;}
		if(*touch == 'U'){A.mode = ACTE; return A;}
		if(*touch == 'Q'){A.mode = QUITTER; return A;}
	}
	if(ret == EST_CLIC)
	{	
		if(P->x > 3*LARG_BOUTON && P->y > S.H*TAILLE_CASE)
		{
				A.mode = QUITTER;
				return A;
		}
		if(P->y < S.H*TAILLE_CASE){ A.mode = CREATION; return A;}
	}
	return A;
	
}


//retourne une action
int Mode_action(ACTION A){
	return A.mode;
}


int deplacement_haut(SLIDER *S){
	int f=0;
	while(((S->grille[S->slid.x][S->slid.y].haut != 1) && (S->grille[S->slid.x][S->slid.y+1].bas != 1)) && (S->slid.y < S->H-1 ) && ((S->slid.x != S->sortie.x) || (S->slid.y != S->sortie.y)))
		{S->slid.y++; f++;}
		return f;
}



int deplacement_bas(SLIDER *S){
	int f=0;
	while(((S->grille[S->slid.x][S->slid.y].bas != 1) && (S->grille[S->slid.x][S->slid.y-1].haut != 1)) && (S->slid.y > 0) && ((S->slid.x != S->sortie.x) || (S->slid.y != S->sortie.y)))
		{S->slid.y--;f++;}
		return f;
}
 
 
 
int deplacement_droite(SLIDER *S){
	int f=0;
	while(((S->grille[S->slid.x][S->slid.y].droite != 1) && (S->grille[S->slid.x+1][S->slid.y].gauche != 1)) && (S->slid.x < S->L-1 ) && ((S->slid.x != S->sortie.x) || (S->slid.y != S->sortie.y)))
		{
			S->slid.x++;f++;
		}
		return f;
}
 
 
 
int deplacement_gauche(SLIDER *S){
	int f=0;
	while(((S->grille[S->slid.x][S->slid.y].gauche != 1) && (S->grille[S->slid.x-1][S->slid.y].droite != 1)) && (S->slid.x > 0) && ((S->slid.x != S->sortie.x) || (S->slid.y != S->sortie.y)))
		{S->slid.x--; f++;}
		return f;	
}


SLIDER Gestion_deplacement_slider(SLIDER S,int* fleche){
	
	POINT P; int f=0;
	P=S.slid;
	if(*fleche == FLECHE_HAUT)
	{	
		f=deplacement_haut(&S); 
		if(f >=1){ S.cout++; S.retour=ajoute_point_debut(S.retour,P); return S;}
	}
	if(*fleche == FLECHE_BAS)
	{		
		f=deplacement_bas(&S);
		if(f >=1){ S.cout++; S.retour=ajoute_point_debut(S.retour,P); return S;}
		
	}
	if(*fleche == FLECHE_DROITE)
	{
		f=deplacement_droite(&S);
		if(f >=1){S.cout++; S.retour=ajoute_point_debut(S.retour,P);  return S;}
	}
	if(*fleche == FLECHE_GAUCHE)
	{
		f=deplacement_gauche(&S);
		if(f >=1){S.cout++; S.retour=ajoute_point_debut(S.retour,P); return S;}
	}
	return S;
}



int Gagner_all_level(SLIDER S){
	ACTION A; char touch;int flech;POINT P;
	if((S.slid.x == S.sortie.x) && (S.slid.y == S.sortie.y))
	{
		initialiser_affichage(S);
		fenetre_gagner_all_level(S);
		do
		{	
			A = Recupe_Action(S,&touch,&flech,&P);
			fenetre_gagner_all_level(S);
		}while(Mode_action(A) != QUITTER);
		return GAGNER;
	}
	return 0;
}


int Gagner_one_level(SLIDER S){
	ACTION A; char touch;int flech;POINT P;
	if((S.slid.x == S.sortie.x) && (S.slid.y == S.sortie.y))
	{
		initialiser_affichage(S);
		fenetre_gagner_alone_level(S);
		do
		{	
			A = Recupe_Action(S,&touch,&flech,&P);
			fenetre_gagner_alone_level(S);
		}while(Mode_action(A) != QUITTER);
		return GAGNER;
	}
	return 0;
}


//la fonction qui gère le undo
SLIDER Undo(SLIDER S,char* touch){
	if(S.retour != NULL)
	{
		S.cout--;
		S.slid = S.retour->Val;
		S.retour = S.retour->suiv;
		return S;
	}
	return S;
}



  
 
