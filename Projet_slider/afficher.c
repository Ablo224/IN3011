#include <uvsqgraphics.h>
#include "mes_constantes.h"
#include "mes_types.h"
#include "afficher.h"


//initialise l'affichage
void initialiser_affichage(SLIDER S) {
	init_graphics(LARG_FENETRE,HAUT_FENETRE);
	affiche_auto_off();
	
}


//dessine une case 
void afficher_une_case(SLIDER S, int x, int y){
	POINT bg, hd;
	bg.x = x*TAILLE_CASE;      bg.y = y*TAILLE_CASE;
	hd.x = bg.x + TAILLE_CASE; hd.y = bg.y + TAILLE_CASE;
		draw_fill_rectangle(bg,hd,sarcelle);
		draw_rectangle(bg,hd,black);
}

//trace un mur sur le bord haut d'une case
void mur_haut(int x,int y) {
	
	POINT bg,hd;
	bg.x = hd.x = 0;
	bg.y = hd.y = 0;
	
	bg.x = x*TAILLE_CASE;      bg.y =TAILLE_CASE + y*TAILLE_CASE;
	hd.x = bg.x+TAILLE_CASE; 	   hd.y = bg.y-5;
			draw_fill_rectangle(bg,hd,gold);	
			draw_rectangle(bg,hd,black);
	
}

//trace un mur sur le bord bas d'une case
void mur_bas(int x,int y) {
	POINT bg,hd;
	bg.x = hd.x = 0;
	bg.y = hd.y = 0;
	
	bg.x += x*TAILLE_CASE;      bg.y = y*TAILLE_CASE;
	hd.x += bg.x+TAILLE_CASE; 	   hd.y = bg.y+5;
			draw_fill_rectangle(bg,hd,gold);	
			draw_rectangle(bg,hd,black);
	
}
//trace un mur sur le bord gauche d'une case
void mur_gauche(int x,int y) {
	POINT bg,hd;
	bg.x = hd.x = 0;
	bg.y = hd.y = 0;
	
	bg.x += x*TAILLE_CASE;      bg.y = y*TAILLE_CASE;
	hd.x += x*TAILLE_CASE+5; 	   hd.y = bg.y+TAILLE_CASE;
				draw_fill_rectangle(bg,hd,gold);	
				draw_rectangle(bg,hd,black);
	
}

//trace un mur sur le bord droit d'une case
void mur_droit(int x,int y) {
	POINT bg,hd;
	bg.x = hd.x = 0;
	bg.y = hd.y = 0;

	bg.x += x*TAILLE_CASE + TAILLE_CASE;      bg.y = y*TAILLE_CASE;
	hd.x += x*TAILLE_CASE + TAILLE_CASE-5; 	   hd.y = bg.y + TAILLE_CASE;
				draw_fill_rectangle(bg,hd,gold);	
				draw_rectangle(bg,hd,black);
	
}

//affiche un murs sur l'un des 4 bords d'une case
void afficher_murs(SLIDER S,int x,int y)
{
			if(S.grille[x][y].haut == 1)
			{
				mur_haut(x,y);
			}
			if(S.grille[x][y].bas == 1)
			{
				mur_bas(x,y);
			}
			if(S.grille[x][y].droite == 1)
			{
				mur_droit(x,y);
			}
			if(S.grille[x][y].gauche == 1)
			{
				mur_gauche(x,y);
			}
	
}


//affiche l'ensemble des murs dans la grille
void afficher_grille(SLIDER S){
	int x,y;
	for (x=0; x<S.L ; x++)
	{
		for (y=0 ; y<S.H ; y++)
		{
			afficher_murs(S,x,y);
		}
	}
}


//affiche les case dans la grille
void affiche_les_cases(SLIDER S){
	for(int x=0;x<S.L;x++)
	{
		for(int y=0;y<S.H;y++)
		{
			afficher_une_case(S,x,y);
		}
	}
}

//affiche le slider
void afficher_le_slider(SLIDER S){
	 POINT bg, hd,centre;
	 bg.x = S.slid.x*TAILLE_CASE; bg.y = S.slid.y*TAILLE_CASE;
	 hd.x = bg.x + TAILLE_CASE; hd.y = bg.y + TAILLE_CASE;
	 centre.x = (bg.x + hd.x)/2;
	 centre.y = (bg.y + hd.y)/2;
		 draw_fill_circle(centre,15,rouge);	
		 draw_circle(centre,15,white);
		 aff_pol_centre("S",TAILLE_POLICE,centre,white);
}

//affiche la sortie
void afficher_la_sortie(SLIDER S){
	 POINT bg, hd,centre;
	 bg.x = S.sortie.x*TAILLE_CASE; bg.y = S.sortie.y*TAILLE_CASE;
	 hd.x = bg.x + TAILLE_CASE; hd.y = bg.y + TAILLE_CASE;
	 centre.x = (bg.x + hd.x)/2;
	 centre.y = (bg.y + hd.y)/2;
		 draw_fill_circle(centre,15,vert);	
		 draw_circle(centre,15,white);
		 aff_pol_centre("P",TAILLE_POLICE,centre,white);
}


void afficher_un_bouton(int numero, char *texte,SLIDER S,COULEUR coul){
	
	POINT bg, hd, centre;
	bg.x =  numero*LARG_BOUTON; bg.y = HAUT_FENETRE-HAUT_BOUTON;
	hd.x = bg.x + LARG_BOUTON; hd.y = bg.y + HAUT_BOUTON;
	centre.x = (bg.x+hd.x)/2;  centre.y = (bg.y+hd.y)/2;
		draw_fill_rectangle(bg,hd,coul);
		draw_rectangle(bg,hd,black);
		aff_pol_centre(texte,25,centre,black);
}


void afficher_cout(SLIDER S){
	
	POINT bg, hd, centre1,centre2;
	bg.x =  LARG_BOUTON; bg.y = HAUT_FENETRE-HAUT_BOUTON;
	hd.x = bg.x + LARG_BOUTON+TAILLE_CASE; hd.y = bg.y + HAUT_BOUTON;
	centre1.x = bg.x+TAILLE_CASE;  centre1.y = (bg.y + hd.y)/2;
	centre2.x = hd.x-TAILLE_CASE-20;  centre2.y = hd.y-10;
		draw_fill_rectangle(bg,hd,sarcelle);
		draw_rectangle(bg,hd,black);
		aff_pol_centre("Cout:",25,centre1,gold);
		aff_int(S.cout,25,centre2,gold);
}


//fonction de transition  quand on gagne à un niveau donnée parmi tous les niveaux
void fenetre_gagner_all_level(SLIDER S){
	POINT centre,centre1,centre2; 
	centre.x = LARGEUR_FENETRE/2; centre.y = HAUTEUR_FENETRE/2;
	centre1.x = LARGEUR_FENETRE/2; centre1.y = HAUTEUR_FENETRE/4;
	centre2.x = LARGEUR_FENETRE/2; centre2.y = HAUTEUR_FENETRE/6;
		fill_screen(sarcelle);
		pol_style(GRAS);
		aff_pol_centre("BINGO YOU WIN THIS PART",20,centre,white);
		aff_pol_centre("clic NEXT to continue",20,centre1,jaune);
		aff_pol_centre("Or ECHAPE to Quit",20,centre2,red);
		afficher_un_bouton(QUITTER,"NEXT",S,jaune);
		affiche_all();
}

//fonction de transition  quand on gagne à un niveau donnée
void fenetre_gagner_alone_level(SLIDER S){
	POINT centre,centre1; 
	centre.x = LARGEUR_FENETRE/2; centre.y = HAUTEUR_FENETRE/2;
	centre1.x = LARGEUR_FENETRE/2; centre1.y = HAUTEUR_FENETRE/4;
		fill_screen(sarcelle);
		pol_style(GRAS);
		aff_pol_centre("BINGO YOU WIN THIS PART",20,centre,white);
		aff_pol_centre("Clic ECHAPE  Or touch 'Q' to Quit",18,centre1,jaune);
		afficher_un_bouton(QUITTER,"QUIT",S,jaune);
		affiche_all();
}

//affiche la fenêtre de création d'un niveau
void affichage_mode_creation(SLIDER S){
	fill_screen(black);
	affiche_les_cases(S);
	afficher_grille(S);
	pol_style(GRAS);
	afficher_un_bouton(QUITTER,"QUIT",S,white);
	afficher_le_slider(S);
	afficher_la_sortie(S);
	affiche_all();
}

//affichage complet quand on joue à tous les niveau
void afficher_slider_all(SLIDER S) {
	fill_screen(black);
	affiche_les_cases(S);
	afficher_grille(S);
	pol_style(GRAS);
	afficher_un_bouton(QUITTER,"NEXT",S,jaune);
	afficher_cout(S);
	afficher_le_slider(S);
	afficher_la_sortie(S);
	affiche_all();
}


//affichage complet quand on joue à un seul niveau 
void afficher_slider(SLIDER S) {
	fill_screen(black);
	affiche_les_cases(S);
	afficher_grille(S);
	pol_style(GRAS);
	afficher_un_bouton(QUITTER,"QUIT",S,jaune);
	afficher_cout(S);
	afficher_le_slider(S);
	afficher_la_sortie(S);
	affiche_all();
}


