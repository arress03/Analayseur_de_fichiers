#ifndef ANALYSEUR_H
#define ANALYSEUR_H

#include <stdio.h>

// Fonction pour ouvrir un fichier en mode lecture
FILE* ouvrirFichierLecture(const char* chemin);

// Fonctions de comptage
int compterLignes(FILE* fichier);
int compterMots(FILE* fichier);
int compterCaracteres(FILE* fichier);

#endif
