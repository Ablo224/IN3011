NOM=ABDOULAYE_BALDE
Rep=Niveaux_slider
CFLAGS=-c -g -Wall



test: slider
	./slider niveau1.slider
	
All_level:slider
		./slider Niveaux_slider
	
#pour le mode création
creation:slider	
	./slider -c 10 10 new_level.slider
	

# Edition de liens
slider: slider.o lire_ecrire.o afficher.o action_bouton_clic.o list.o creation_niveaux.o
	gcc slider.o lire_ecrire.o afficher.o action_bouton_clic.o  list.o  creation_niveaux.o -o slider -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf -O2

# Compilation
slider.o: slider.c mes_types.h lire_ecrire.h action_bouton_clic.h list.h mes_constantes.h
	gcc `sdl-config --cflags`  $(CFLAGS) slider.c -O2
	
# Compilation
lire_ecrire.o: lire_ecrire.c list.h  mes_constantes.h mes_types.h
	gcc  `sdl-config --cflags`  $(CFLAGS) lire_ecrire.c -O2

# Compilation
afficher.o: afficher.c mes_constantes.h
	gcc  `sdl-config --cflags` $(CFLAGS)  afficher.c -O2

# Compilation	
action_bouton_clic.o: action_bouton_clic.c list.h afficher.h lire_ecrire.h mes_constantes.h mes_types.h
	gcc `sdl-config --cflags` $(CFLAGS) action_bouton_clic.c -O2

# Compilation	
list.o: list.c 
	gcc  `sdl-config --cflags` $(CFLAGS) list.c -O2
	
creation_niveaux.o: creation_niveaux.c afficher.h lire_ecrire.h mes_constantes.h mes_types.h
	gcc `sdl-config --cflags`  $(CFLAGS) creation_niveaux.c	 -O2

#copier des niveaux dans le repertoire contenant les niveaux	
copie_level:
	cp *.slider $(Rep)

# Pour creer le zip a deposer sur e-campus
zip:
	rm -fr $(NOM)
	rm -f $(NOM).zip
	mkdir $(NOM)
	cp *.c $(NOM)
	cp *.h $(NOM)
	cp Makefile $(NOM)
	cp -f *.slider *.pdf $(NOM)
	cp -fr $(Rep) $(NOM)
	zip -r $(NOM).zip $(NOM)/*
	rm -fr $(NOM)



clean:
	rm -rf $(NOM)
	rm -f $(NOM).zip
	rm -f *.o
	rm -f slider
