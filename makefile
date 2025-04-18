# Makefile

# Règle par défaut
all: main
	./main

# Règle pour générer l'exécutable
main: main.o fonction.o affichage.o attaque.o IA.o
	gcc -o main main.o fonction.o affichage.o attaque.o IA.o

# Règle pour générer les fichiers objets
main.o: main.c
	gcc -c main.c -o main.o

fonction.o: fonction.c
	gcc -c fonction.c -o fonction.o

affichage.o: affichage.c
	gcc -c affichage.c -o affichage.o

attaque.o: attaque.c
	gcc -c attaque.c -o attaque.o

IA.o: IA.c
	gcc -c IA.c -o IA.o
# Règle pour nettoyer les fichiers générés
clean:
	rm -f main main.o fonction.o affichage.o attaque.o IA.o

.PHONY: all clean