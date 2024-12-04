#include "analyseur.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_MOTS 1000

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "fr_FR.UTF-8");
    if (argc != 3) {
        printf("Usage: %s <fichier_entree> <fichier_sortie>\n", argv[0]);
        return 1;
    }

    // Ouvrir le fichier d'entrée
    FILE *fichierEntree = ouvrirFichierLecture(argv[1]);
    if (fichierEntree == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier d'entrée %s\n", argv[1]);
        return 1;
    }

    // Compter les lignes, mots et caractères
    int nombreLignes = compterLignes(fichierEntree);
    int nombreMots = compterMots(fichierEntree);
    int nombreCaracteres = compterCaracteres(fichierEntree);

    // Calculer la fréquence des mots
    struct Mot tableauMots[MAX_MOTS];
    int nombreMotsDistincts;
    calculerFrequenceMots(fichierEntree, tableauMots, &nombreMotsDistincts);
    trierMotsParFrequence(tableauMots, nombreMotsDistincts);


    // Sauvegarder les résultats dans le fichier de sortie
    sauvegarderResultats(argv[2], nombreLignes, nombreMots, nombreCaracteres, tableauMots, nombreMotsDistincts);

    // Fermer le fichier d'entrée
    fclose(fichierEntree);

    printf("Analyse terminée. Résultats sauvegardés dans %s\n", argv[2]);

    return 0;
}
