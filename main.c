#include <stdio.h>
#include <stdlib.h>
#include "analyseur.h"

int main(int argc, char *argv[]) {
    // Vérification du nombre d'arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <nom_du_fichier_texte>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* cheminEntree = argv[1];  // Chemin du fichier passé en argument
    const char* cheminSortie = "sortie.txt";  // Nom du fichier de sortie (modifiable si besoin)

    // Ouvrir le fichier texte à analyser
    FILE* fichier = ouvrirFichierLecture(cheminEntree);

    // Compter les lignes, mots et caractères
    int nombreLignes = compterLignes(fichier);
    int nombreMots = compterMots(fichier);
    int nombreCaracteres = compterCaracteres(fichier);

    // Afficher les résultats à l'écran
    printf("Resultats stockes dans le fichier 'sortie.txt' \n");

    // Sauvegarder les résultats dans un fichier de sortie
    sauvegarderResultats(cheminSortie, nombreLignes, nombreMots, nombreCaracteres);

    // Fermer le fichier
    fclose(fichier);

    return 0;
}
