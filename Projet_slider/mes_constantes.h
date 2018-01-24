// constantes.h du projet SLIDER

// Contient les constantes utilisées un peu partour dans le projet.

#ifndef ___CONSTANTES_H
#define ___CONSTANTES_H



#define VIDE 0

// Les actions et le mode
#define CREATION 0
#define ACTE	 1
#define JOUER    2
#define QUITTER  3
#define SAVE 4
#define CONTINUER 5
#define RETOUR	 6
#define GAGNER	 7

//les constantes qui designe le bord d'un mur
#define HAUT 0
#define BAS 6
#define DROIT 3
#define GAUCHE 9

// Constantes liées à l'affichage
#define TAILLE_CASE 50
#define larg_fenetre (9*TAILLE_CASE)
#define hauteur_fenetre (9*TAILLE_CASE)
#define LARG_BOUTON ((S.L*TAILLE_CASE)/4)
#define HAUT_BOUTON (TAILLE_CASE)
#define LARG_FENETRE (S.L*TAILLE_CASE)
#define HAUT_FENETRE (S.H*TAILLE_CASE + HAUT_BOUTON)
#define TAILLE_POLICE 20

#endif
