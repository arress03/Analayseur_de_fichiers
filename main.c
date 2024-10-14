#include <stdio.h>
#include "analyseur.h"

int main() {
    const char* cheminEntree = "C:/ProjetC/entree.txt";  // Remplacez par le chemin du fichier à analyser
    const char* cheminSortie = "C:/ProjetC/sortie.txt";  // Remplacez par le chemin du fichier de sortie

    FILE* fichier = ouvrirFichierLecture(cheminEntree);

    int nombreLignes = compterLignes(fichier);
    int nombreMots = compterMots(fichier);
    int nombreCaracteres = compterCaracteres(fichier);

    printf("Voir les resultats dans le fichier sortie.txt \n");

    // Sauvegarder les résultats dans un fichier de sortie
    sauvegarderResultats(cheminSortie, nombreLignes, nombreMots, nombreCaracteres);

    fclose(fichier);
    return 0;
}
