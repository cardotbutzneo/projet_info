# Makefile

# Règle par défaut
all: main.o
	./main.o

# Règle pour générer l'exécutable
main.o: main.c fonction.c
	gcc -o main.o main.c fonction.c

# Règle pour nettoyer les fichiers générés
clean:
	rm -f main.o

.PHONY: all clean
