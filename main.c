#include "analyseur.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_MOTS 1000

void afficherMenuLangue() {
    printf("Choisissez une langue :\n");
    printf("1 - Français\n");
    printf("2 - Anglais\n");
    printf("3 - Russe\n");
    printf("4 - Espagnol\n");
    printf("Votre choix : ");
}

int main() {
    setlocale(LC_ALL, "fr_FR.UTF-8");

    // Afficher le menu pour choisir la langue
    int choixLangue;
    afficherMenuLangue();
    scanf("%d", &choixLangue);

    // Configurer la langue sélectionnée
    switch (choixLangue) {
        case 1:
            setlocale(LC_ALL, "fr_FR.UTF-8");
            break;
        case 2:
            setlocale(LC_ALL, "en_US.UTF-8");
            break;
        case 3:
            setlocale(LC_ALL, "ru_RU.UTF-8");
            break;
        case 4:
            setlocale(LC_ALL, "es_ES.UTF-8");
            break;
        default:
            printf("Choix invalide. Par défaut, la langue sera le français.\n");
            setlocale(LC_ALL, "fr_FR.UTF-8");
    }

    // Saisir le fichier d'entrée et de sortie
    char fichierEntree[256];
    char fichierSortie[256];
    printf("Entrez le nom du fichier à analyser : ");
    scanf("%s", fichierEntree);
    printf("Entrez le nom du fichier de sortie : ");
    scanf("%s", fichierSortie);

    // Ouvrir le fichier d'entrée
    FILE *fichier = ouvrirFichierLecture(fichierEntree);
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier %s\n", fichierEntree);
        return 1;
    }

    // Analyse du fichier
    int nombreLignes = compterLignes(fichier);
    int nombreMots = compterMots(fichier);
    int nombreCaracteres = compterCaracteres(fichier);

    // Calculer la fréquence des mots
    struct Mot tableauMots[MAX_MOTS];
    int nombreMotsDistincts;
    calculerFrequenceMots(fichier, tableauMots, &nombreMotsDistincts);
    trierMotsParFrequence(tableauMots, nombreMotsDistincts);

    // Sauvegarder les résultats
    sauvegarderResultats(fichierSortie, nombreLignes, nombreMots, nombreCaracteres, tableauMots, nombreMotsDistincts);

    fclose(fichier);
    printf("Analyse terminée. Résultats sauvegardés dans %s\n", fichierSortie);

    return 0;
}
