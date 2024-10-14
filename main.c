#include <stdio.h>
#include "analyseur.h"

int main() {
    const char* chemin = "chemin/vers/le/fichier.txt"; 
    FILE* fichier = ouvrirFichierLecture(chemin);

    char ligne[256];
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        printf("%s", ligne);
    }

    fclose(fichier);
    return 0;
}
