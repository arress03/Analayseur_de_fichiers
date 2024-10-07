#include "analyseur.h"
#include <stdlib.h>

FILE* ouvrirFichierLecture(const char* chemin) {
    FILE* fichier = fopen(chemin, "r");
    if (fichier == NULL) {
        // Afficher un message d'erreur si le fichier n'a pas pu être ouvert
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);  // Quitte le programme en cas d'erreur
    }
    return fichier;
}
