#ifndef ANALYSEUR_H
#define ANALYSEUR_H

#include <stdio.h>

#define TAILLE_MAX_MOT 1000

// Définition de la structure Mot
struct Mot {
    char mot[TAILLE_MAX_MOT];
    int frequence;
};

// Fonction pour ouvrir un fichier en mode lecture
FILE* ouvrirFichierLecture(const char* chemin);

// Fonctions de comptage
int compterLignes(FILE* fichier);
int compterMots(FILE* fichier);
int compterCaracteres(FILE* fichier);

// Fonctions pour calculer la fréquence des mots
void ajouterMotOuIncrementer(char* mot, struct Mot* tableauMots, int* nombreMots);
void calculerFrequenceMots(FILE* fichier, struct Mot* tableauMots, int* nombreMots);
void trierMotsParFrequence(struct Mot* tableauMots, int nombreMots);


// Fonction pour sauvegarder les résultats
void sauvegarderResultats(const char* cheminSortie, int nombreLignes, int nombreMots, int nombreCaracteres, struct Mot* tableauMots, int nombreMotsDistincts);

#endif
