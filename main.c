#include <stdio.h>
#include "analyseur.h"

int main() {
    const char* chemin = "C:/ProjetC/test.txt"; // Remplacez par le chemin réel du fichier à analyser
    FILE* fichier = ouvrirFichierLecture(chemin);

    int nombreLignes = compterLignes(fichier);
    int nombreMots = compterMots(fichier);
    int nombreCaracteres = compterCaracteres(fichier);

    printf("Nombre de lignes : %d\n", nombreLignes);
    printf("Nombre de mots : %d\n", nombreMots);
    printf("Nombre de caracteres : %d\n", nombreCaracteres);

    fclose(fichier);
    return 0;
}
