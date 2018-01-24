#include <uvsqgraphics.h>
#include "mes_constantes.h"
#include "mes_types.h"
#include "afficher.h"
#include "lire_ecrire.h"


//recupère les coordonnées pour un mur haut
void point_haut(POINT *bg,POINT *hd,int x,int y) {
	bg->x = hd->x = 0;
	bg->y = hd->y = 0;
	
	bg->x = x*TAILLE_CASE;      bg->y =TAILLE_CASE + y*TAILLE_CASE;
	hd->x = bg->x+TAILLE_CASE+5; 	 hd->y = bg->y-5;
}



//recupère les coordonnées pour un mur bas
void point_bas(POINT *bg,POINT *hd,int x,int y) {
	bg->x = hd->x = 0;
	bg->y = hd->y = 0;
	
	bg->x += x*TAILLE_CASE;      bg->y = y*TAILLE_CASE;
	hd->x += bg->x+TAILLE_CASE+5; 	   hd->y = y*TAILLE_CASE+5;
}


//recupère les coordonnées pour un mur gauche
void point_gauche(POINT *bg,POINT *hd,int x,int y) {
	bg->x = hd->x = 0;
	bg->y = hd->y = 0;
	
	bg->x += x*TAILLE_CASE;      bg->y = y*TAILLE_CASE;
	hd->x += x*TAILLE_CASE+5; 	   hd->y = bg->y+TAILLE_CASE+5;	
}

//recupère les coordonnées pour un mur droit
void point_droit(POINT *bg,POINT *hd,int x,int y) {
	bg->x = hd->x = 0;
	bg->y = hd->y = 0;

	bg->x += x*TAILLE_CASE + TAILLE_CASE;      bg->y = y*TAILLE_CASE;
	hd->x += x*TAILLE_CASE + TAILLE_CASE-5; 	   hd->y = bg->y + TAILLE_CASE+5;
}

SLIDER change_coordonnees_slider(SLIDER S,POINT P){
		 P = wait_clic();
		 P.x=P.x/TAILLE_CASE; 
		 P.y=P.y/TAILLE_CASE;
		 if(P.y < S.H)
		 {
			if(P.x != S.sortie.x || P.y != S.sortie.y)
			{
				S.slid.x = P.x;
				S.slid.y = P.y;
				return S;
			}
		 }
		 return S;
}


SLIDER change_coordonnees_sortie(SLIDER S,POINT P){
		 P= wait_clic();
		 P.x=P.x/TAILLE_CASE; 
		 P.y=P.y/TAILLE_CASE;
		 if(P.y < S.H)
		 { 
			if(P.x != S.slid.x || P.y != S.slid.y)
			{
				S.sortie.x = P.x;
				S.sortie.y = P.y;
				return S;
			}
		 }
		 return S;
}


SLIDER trace_ou_supprime_mur_gauche(SLIDER S,int x,int y){
	if(S.grille[x][y].gauche == 0){ S.N++; S.grille[x][y].gauche = 1; return S; }
	if(S.grille[x][y].gauche == 1){ S.N--; S.grille[x][y].gauche = 0; return S; }
	return S;
}


SLIDER trace_ou_supprime_mur_droit(SLIDER S,int x,int y){
	if(S.grille[x][y].droite == 0){ S.N++; S.grille[x][y].droite = 1; return S; }
	if(S.grille[x][y].droite == 1){ S.N--;S.grille[x][y].droite = 0; return S; }
	return S;
}	


SLIDER trace_ou_supprime_mur_haut(SLIDER S,int x,int y){
	if(S.grille[x][y].haut == 0){S.N++; S.grille[x][y].haut = 1; return S; }
	if(S.grille[x][y].haut == 1){ S.N--;S.grille[x][y].haut = 0; return S; }
	return S;
}


SLIDER trace_ou_supprime_mur_bas(SLIDER S,int x,int y){
	if(S.grille[x][y].bas == 0){S.N++;S.grille[x][y].bas = 1; return S; }
	if(S.grille[x][y].bas == 1){S.N--;S.grille[x][y].bas = 0; return S; }
	return S;
}

//La fonction qui permet la création des murs en fonction du clic
SLIDER creation_murs(SLIDER S,POINT *P){
	
	POINT bg_gauche,hd_gauche,bg_droit,hd_droit,bg_haut,hd_haut,bg_bas,hd_bas;
	int x=P->x/TAILLE_CASE; int y=P->y/TAILLE_CASE;
	
	//les fonctions de récuperation des coordonnées
	point_droit(&bg_droit,&hd_droit,x,y);
	point_gauche(&bg_gauche,&hd_gauche,x,y);
	point_haut(&bg_haut,&hd_haut,x,y);
	point_bas(&bg_bas,&hd_bas,x,y);
	
	//Vérification sur quel bord le clic a été effectuer
	if((P->x >= bg_gauche.x && P->x <= hd_gauche.x) && (P->y <= hd_gauche.y))
	{
		S=trace_ou_supprime_mur_gauche(S,x,y);
	} 
	if((P->x <= bg_droit.x && P->x >= hd_droit.x) && (P->y <= hd_droit.y))
	{
		S=trace_ou_supprime_mur_droit(S,x,y);
	}
	if((P->x >= bg_haut.x && P->x <= hd_haut.x) && (P->y <= bg_haut.y && P->y >= hd_haut.y))
	{
		S=trace_ou_supprime_mur_haut(S,x,y);
	} 
	if((P->x >= bg_bas.x && P->x <= hd_bas.x) && (P->y >= bg_bas.y && P->y <= hd_bas.y))
	{
		S=trace_ou_supprime_mur_bas(S,x,y);
	}
	if(x == S.slid.x && y == S.slid.y)
	{
		POINT Q;
		S=change_coordonnees_slider(S,Q);
	 }
	 if(x == S.sortie.x && y == S.sortie.y)
	 {
		POINT Q;
		S=change_coordonnees_sortie(S,Q);
	 }	
	return S;
}






