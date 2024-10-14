# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJ = main.o analyseur.o
EXEC = analyseur_texte

# Règle par défaut pour générer l'exécutable
all: $(EXEC)

# Règle pour générer l'exécutable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Règle pour générer l'objet de main.c
main.o: main.c analyseur.h
	$(CC) $(CFLAGS) -c main.c

# Règle pour générer l'objet de analyseur.c
analyseur.o: analyseur.c analyseur.h
	$(CC) $(CFLAGS) -c analyseur.c

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJ) $(EXEC)

# Règle pour forcer la recompilation complète
rebuild: clean all
