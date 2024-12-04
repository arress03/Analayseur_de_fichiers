#include "analyseur.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

// Définition de la structure pour stocker les mots et leur fréquence
typedef struct Mot {
    char* mot;
    int frequence;
} Mot;



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

// Fonction pour ajouter un mot ou incrémenter sa fréquence
void ajouterMotOuIncrementer(char* mot, Mot* tableauMots, int* nombreMotsDistincts) {
    for (int i = 0; i < *nombreMotsDistincts; i++) {
        if (strcmp(tableauMots[i].mot, mot) == 0) {
            tableauMots[i].frequence++;
            return;
        }
    }
    // Ajouter un nouveau mot
    tableauMots[*nombreMotsDistincts].mot = malloc(strlen(mot) + 1);
    if (tableauMots[*nombreMotsDistincts].mot == NULL) {
        perror("Erreur d'allocation de mémoire");
        exit(EXIT_FAILURE);
    }
    strcpy(tableauMots[*nombreMotsDistincts].mot, mot);
    tableauMots[*nombreMotsDistincts].frequence = 1;
    (*nombreMotsDistincts)++;
}

// Fonction pour calculer la fréquence de chaque mot dans un fichier (version simplifiée)
int calculerFrequenceMots(FILE* fichier, Mot* tableauMots, int* nombreMotsDistincts) {
    char mot[256];
    *nombreMotsDistincts = 0;
    while (fscanf(fichier, "%255s", mot) == 1) {
        // Convertir le mot en minuscules pour éviter la distinction de casse
        for (char* p = mot; *p; ++p) {
            *p = tolower(*p);
        }
        ajouterMotOuIncrementer(mot, tableauMots, nombreMotsDistincts);
    }
    rewind(fichier); // Remettre le fichier au début après lecture
    return *nombreMotsDistincts;
}

// Fonction pour afficher les mots les plus fréquents
void afficherMotsFrequents(Mot* tableauMots, int nombreMotsDistincts, int limite) {
    printf("Mots les plus fréquents :\n");
    for (int i = 0; i < nombreMotsDistincts && i < limite; i++) {
        printf("%s : %d\n", tableauMots[i].mot, tableauMots[i].frequence);
    }
}

// Fonction pour sauvegarder les résultats complets dans un fichier de sortie
void sauvegarderResultatsComplets(const char* cheminSortie, int nombreLignes, int nombreMots, int nombreCaracteres, Mot* tableauMots, int nombreMotsDistincts) {
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
    fprintf(fichierSortie, "\nMots les plus fréquents :\n");
    for (int i = 0; i < nombreMotsDistincts && i < 10; i++) {
        fprintf(fichierSortie, "%s : %d\n", tableauMots[i].mot, tableauMots[i].frequence);
    }

    fclose(fichierSortie);  // Fermer le fichier de sortie
}

// Fonction pour libérer la mémoire allouée dynamiquement aux mots
void libererMemoireMots(Mot* tableauMots, int nombreMotsDistincts) {
    for (int i = 0; i < nombreMotsDistincts; i++) {
        free(tableauMots[i].mot);
    }
}

// Exemple d'utilisation de l'analyseur de fichier texte
int main() {
    FILE* fichier = ouvrirFichierLecture("entree.txt");

    // Allouer un tableau de mots de taille fixe
    int tailleMax = 1000; // Ajuster la taille en fonction des besoins
    Mot* tableauMots = malloc(tailleMax * sizeof(Mot));
    if (tableauMots == NULL) {
        perror("Erreur d'allocation de mémoire");
        exit(EXIT_FAILURE);
    }

    int nombreMotsDistincts;
    int nombreLignes = compterLignes(fichier);
    int nombreMots = compterMots(fichier);
    int nombreCaracteres = compterCaracteres(fichier);
    int calculerFrequenceMots(fichier, tableauMots, &nombreMotsDistincts);
    int afficherMotsFrequents(tableauMots, nombreMotsDistincts, 10);

    // Sauvegarder les résultats dans un fichier de sortie
    void sauvegarderResultatsComplets("resultats.txt", nombreLignes, nombreMots, nombreCaracteres, tableauMots, nombreMotsDistincts);

    // Libérer la mémoire
    libererMemoireMots(tableauMots, nombreMotsDistincts);
    free(tableauMots);

    fclose(fichier);
    return 0;
}
