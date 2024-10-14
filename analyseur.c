#include "analyseur.h"
#include <stdlib.h>

// Fonction pour ouvrir un fichier en mode lecture
FILE* ouvrirFichierLecture(const char* chemin) {
    FILE* fichier = fopen(chemin, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
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
            dansMot = 0;
        } else if (dansMot == 0) {
            dansMot = 1;
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

// Fonction pour sauvegarder les résultats dans un fichier de sortie
void sauvegarderResultats(const char* cheminSortie, int nombreLignes, int nombreMots, int nombreCaracteres) {
    FILE* fichierSortie = fopen(cheminSortie, "w");
    if (fichierSortie == NULL) {
        perror("Erreur lors de l'ouverture du fichier de sortie");
        exit(EXIT_FAILURE);
    }

    // Écrire les résultats dans le fichier de sortie
    fprintf(fichierSortie, "Résultats de l'analyse du fichier texte :\n");
    fprintf(fichierSortie, "Nombre de lignes : %d\n", nombreLignes);
    fprintf(fichierSortie, "Nombre de mots : %d\n", nombreMots);
    fprintf(fichierSortie, "Nombre de caractères : %d\n", nombreCaracteres);

    fclose(fichierSortie);  // Fermer le fichier de sortie
}
