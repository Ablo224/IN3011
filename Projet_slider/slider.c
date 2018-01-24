#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <uvsqgraphics.h>
#include "mes_types.h"
#include "lire_ecrire.h"
#include "afficher.h"
#include "action_bouton_clic.h"
#include "list.h"
#include "creation_niveaux.h"
#include "mes_constantes.h"



//fonction qui modifie le slider en fonction d'une action
SLIDER Modifie_Slider(ACTION A,SLIDER S,char* touch,int* flech,POINT* P,char* nom){
	
	if(A.mode == JOUER)
	{
		S=Gestion_deplacement_slider(S,flech);
	}	
	if(A.mode == ACTE)
	{
		S = Undo(S,touch);
		return S;
	}
	return S;
}


//fonction qui trace un ou des murs et effectue l'enregistrement si besoin
SLIDER Modifie_creation(ACTION A,SLIDER S,char* touch,int* flech,POINT* P,char* nom){
	
	if(A.mode == SAVE){ ecrire_slider_dans_fichier(S,nom); return S;}
	if(A.mode == CREATION){ S=creation_murs(S,P); return S;}
	return S;
}

void Play_one_level(SLIDER S,ACTION A,char* t,int* fl,POINT* P,char* path){
		
		init_grille(S);	
		S = lire_slider(path);
		initialiser_affichage(S);
		S.cout = 0;
		afficher_slider(S);
		do{
				A = Recupe_Action(S,t,fl,P);
				S = Modifie_Slider(A,S,t,fl,P,path);
				afficher_slider(S);
	
			}while((Mode_action(A) != QUITTER) && (Gagner_one_level(S) != GAGNER));
			S.retour = libere_liste(S.retour);
			
}

void Play_all_levels(SLIDER S,ACTION A,char* t,int* fl,POINT* P,char* path){
		
		init_grille(S);	
		S = lire_slider(path);
		initialiser_affichage(S);
		S.cout = 0;
		afficher_slider_all(S);
		do{
				A = Recupe_Action(S,t,fl,P);
				S = Modifie_Slider(A,S,t,fl,P,path);
				afficher_slider_all(S);
	
			}while((Mode_action(A) != QUITTER) && (Gagner_all_level(S) != GAGNER));
			S.retour = libere_liste(S.retour);
			
}

void creation_niveaux(SLIDER S,ACTION A,char* fichier,char* L,char* H){
		int fl; char t; POINT P;
		S.L = atoi(L);
		S.H = atoi(H);
		S.N = 0;
		if(S.L > 0 && S.H > 0)
		{
			S.slid.x = 0; S.slid.y = 0;
			S.sortie.x =S.L - 1; S.sortie.y = S.H - 1;
			
			init_grille(S);
			initialiser_affichage(S);
			affichage_mode_creation(S);
			do{
				A = Recupe_Action(S,&t,&fl,&P);
				S = Modifie_creation(A,S,&t,&fl,&P,fichier);
				affichage_mode_creation(S);
			}while(Mode_action(A) != QUITTER && A.mode != SAVE);
		}
		else{printf(" la taille de la grille doit être supperieur à 0\n");}
} 	


int main (int argc, char*argv[]) {

	SLIDER S; ACTION A;
	int fl; char t; POINT P;
	
	
	//une structure qui se trouve dans la BU stat
	struct stat sbuf;	
	char *path = argv[1];
	
	//une structure qui se trouve dans la BU dirent.h
	DIR* dir=NULL;
	struct dirent* fichier = NULL;
	
	
	if(argc ==2)
	{
		//verification si argv[1] est un fichier ou un repertoire et excécuter en fonction du résultat la tache appropriée
		if(stat(path,&sbuf) >= 0)
		{
		
			int m = sbuf.st_mode;
		
			//verification si argv[1] est un fichier
			if(S_ISREG(m))
			{
				Play_one_level(S,A,&t,&fl,&P,path);
			}
			//verification si argv[1] est un repertoire	
			else if((S_ISDIR(m)))
			{
				//ouverture du repertoire
				dir =  opendir(path);
				if(dir == NULL)
				{
					perror("");exit(1);
				}
				//lecture des fichiers du repertoire
				while((fichier = readdir(dir)) != NULL)
				{
					if (strcmp(fichier->d_name, ".") != 0 && strcmp(fichier->d_name, "..") != 0)
					{ 
						Play_all_levels(S,A,&t,&fl,&P,fichier->d_name);
					}
				}
				closedir(dir);
			}
		}
		
	}
	if(argc == 5)
	{
		char* c=argv[1];
		if(strcmp(c,"-c")==0 && strstr(argv[4],".slider")!=NULL)
		{
				creation_niveaux(S,A,argv[4],argv[2],argv[3]);
		}
		else
		{
			printf("verifier les arguments passés en ligne de commande\n");
		}
	}
				
	exit(0);
}
