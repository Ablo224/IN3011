#include <stdio.h>
#include <stdlib.h>
#include <uvsqgraphics.h>
#include "list.h"

UNDO Create_list(){return NULL;}


//ajoute un point au debut la liste
UNDO ajoute_point_debut(UNDO u,POINT P)
{
	UNDO new = malloc(sizeof(UNDO));
	if(u == NULL)
	{
		new->Val = P;
		new->suiv = u;
	return new;
	}
	else if(u!= NULL)
	{
		if(u->Val.x != P.x || u->Val.y != P.y)
		{
			new->Val = P;
			new->suiv = u;
			return new;
		}
		else{return u;}
	}
return new;
}


//liberation de la liste
UNDO libere_liste(UNDO u)
{
	UNDO tmp;
	while(u)
	{
		tmp = u->suiv;
		free(u);
		u = tmp;
	}
	return NULL;
}


