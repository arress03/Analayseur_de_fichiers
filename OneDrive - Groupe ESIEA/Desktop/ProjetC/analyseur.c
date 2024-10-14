#include "analyseur.h"
#include <stdlib.h>
#include <ctype.h>

// Fonction pour ouvrir un fichier en mode lecture
FILE* ouvrirFichierLecture(const char* chemin) {
    FILE* fichier = fopen(chemin, "r");
    if (fichier == NULL) {
        // Afficher un message d'erreur si le fichier n'a pas pu être ouvert
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);  // Quitte le programme en cas d'erreur
    }
    return fichier;
}

// Fonction pour compter le nombre de lignes dans un fichier
int compterLignes(FILE* fichier) {
    int lignes = 0;
    char c;

    while ((c = fgetc(fichier)) != EOF) {
        if (c == '\n') {
            lignes++;
        }
    }

    rewind(fichier);  // Remettre le fichier au début après lecture
    return lignes;
}

// Fonction pour compter le nombre de mots dans un fichier
int compterMots(FILE* fichier) {
    int mots = 0;
    char c;
    int dansMot = 0;

    while ((c = fgetc(fichier)) != EOF) {
        if (isspace(c)) {
            dansMot = 0;  // Fin d'un mot
        } else if (dansMot == 0) {
            dansMot = 1;  // Début d'un nouveau mot
            mots++;
        }
    }

    rewind(fichier);  // Remettre le fichier au début après lecture
    return mots;
}

// Fonction pour compter le nombre de caractères dans un fichier
int compterCaracteres(FILE* fichier) {
    int caracteres = 0;
    char c;

    while ((c = fgetc(fichier)) != EOF) {
        caracteres++;
    }

    rewind(fichier);  // Remettre le fichier au début après lecture
    return caracteres;
}
