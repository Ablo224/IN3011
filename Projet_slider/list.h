#ifndef ___LIST_H
#define ___LIST_H

struct undo{
	POINT Val;
	struct undo *suiv;
};
typedef struct undo *UNDO; 



UNDO Create_list();

UNDO ajoute_point_debut(UNDO u,POINT P);

UNDO libere_liste(UNDO u);


#endif
