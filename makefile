# Makefile

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -g

# Nom de l'exécutable
EXEC = main

# Fichiers sources et objets
SRCS = main.c fonction.c affichage.c attaque.c IA.c tuto.c attaquespe.c synergie.c
OBJS = $(SRCS:.c=.o)

# Règle par défaut
all: $(EXEC)

# Règle pour générer l'exécutable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Règle générique pour générer les fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(EXEC)
# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(EXEC) $(OBJS)

# Règle pour nettoyer tout (y compris les fichiers temporaires)
distclean: clean
	rm -f *~

.PHONY: all clean distclean