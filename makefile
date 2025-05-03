# Makefile

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -g
RELEASE_FLAGS = -O2

# Répertoires
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Nom de l'exécutable
EXEC = main

# Fichiers sources et objets
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Règle par défaut
all: $(EXEC)

# Règle pour générer l'exécutable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Règle générique pour générer les fichiers objets
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Règle pour exécuter automatiquement le programme
run: all
	./$(EXEC)

# Règle pour compiler en mode débogage
debug: CFLAGS += -g -DDEBUG
debug: clean all

# Règle pour compiler en mode release (optimisé)
release: CFLAGS = $(RELEASE_FLAGS)
release: clean all

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(EXEC) $(BUILD_DIR)/*.o

# Règle pour nettoyer tout (y compris les fichiers temporaires)
distclean: clean
	rm -f *~

.PHONY: all clean distclean run debug release