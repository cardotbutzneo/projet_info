# Makefile

# Règle par défaut
all: main
	./main

# Règle pour générer l'exécutable
main: main.o fonction.o affichage.o
	gcc -o main main.o fonction.o affichage.o

# Règle pour générer les fichiers objets
main.o: main.c
	gcc -c main.c -o main.o

fonction.o: fonction.c
	gcc -c fonction.c -o fonction.o

affichage.o: affichage.c
	gcc -c affichage.c -o affichage.o


# Règle pour nettoyer les fichiers générés
clean:
	rm -f main main.o fonction.o

.PHONY: all clean