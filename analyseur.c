#include "analyseur.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAILLE_MAX_MOT 1000

// Fonction pour ouvrir un fichier en mode lecture
FILE* ouvrirFichierLecture(const char* chemin) {
    FILE* fichier = fopen(chemin, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    return fichier;
}

// Fonction pour compter le nombre de lignes dans un fichier
int compterLignes(FILE* fichier) {
    int lignes = 0;
    char c;
    int fichierNonVide = 0; // Pour gérer les fichiers vides

    while ((c = fgetc(fichier)) != EOF) {
        fichierNonVide = 1; // Indique que le fichier contient au moins un caractère
        if (c == '\n') {
            lignes++;
        }
    }
    // Ajouter une ligne supplémentaire si le dernier caractère n'est pas un saut de ligne
    if (fichierNonVide && c != '\n') {
        lignes++;
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
void ajouterMotOuIncrementer(char* mot, struct Mot* tableauMots, int* nombreMots) {
    for (int i = 0; i < *nombreMots; i++) {
        if (strcmp(tableauMots[i].mot, mot) == 0) {
            tableauMots[i].frequence++;
            return;
        }
    }
    strcpy(tableauMots[*nombreMots].mot, mot);
    tableauMots[*nombreMots].frequence = 1;
    (*nombreMots)++;
}

// Fonction pour extraire les mots d'un fichier et calculer leur fréquence
void calculerFrequenceMots(FILE* fichier, struct Mot* tableauMots, int* nombreMots) {
    char mot[TAILLE_MAX_MOT];
    *nombreMots = 0;
    
    while (fscanf(fichier, "%99s", mot) == 1) {
        ajouterMotOuIncrementer(mot, tableauMots, nombreMots);
    }
    rewind(fichier);
}
int comparerFrequence(const void* a, const void* b) {
    struct Mot* motA = (struct Mot*)a;
    struct Mot* motB = (struct Mot*)b;
    return motB->frequence - motA->frequence;  // Tri décroissant
}

void trierMotsParFrequence(struct Mot* tableauMots, int nombreMots) {
    qsort(tableauMots, nombreMots, sizeof(struct Mot), comparerFrequence);
}

// Fonction pour sauvegarder les résultats, y compris la fréquence des mots
void sauvegarderResultats(const char* cheminSortie, int nombreLignes, int nombreMots, int nombreCaracteres, struct Mot* tableauMots, int nombreMotsDistincts) {
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
    
    // Ajouter la fréquence des mots dans le fichier de sortie
    fprintf(fichierSortie, "\nLes 10 mots les plus fréquents dans le fichier (ordre décroissant) :\n");
    int limite = (nombreMotsDistincts < 10) ? nombreMotsDistincts : 10;
    for (int i = 0; i < limite; i++) {
        fprintf(fichierSortie, "%s : %d\n", tableauMots[i].mot, tableauMots[i].frequence);
    }


    fclose(fichierSortie);  // Fermer le fichier de sortie
}



// Fonction qui vérifie si un mot est un palindrome
int estPalindrome(const char* mot) {
    int longueur = strlen(mot);
    for (int i = 0, j = longueur - 1; i < j; i++, j--) {
        // Compare les caractères en ignorant la casse
        if (tolower(mot[i]) != tolower(mot[j])) {
            return 0; // Pas un palindrome
        }
    }
    return 1; // C'est un palindrome
}
void detecterPalindromes(FILE* fichier) {
    char mot[100];
    int compteur = 0;

    printf("Mots palindromes trouvés dans le fichier :\n");

    // Lire chaque mot du fichier
    while (fscanf(fichier, "%99s", mot) == 1) {
        if (estPalindrome(mot)) {
            printf("- %s\n", mot);
            compteur++;
        }
    }

    if (compteur == 0) {
        printf("Aucun mot palindrome trouvé.\n");
    }

    rewind(fichier);
}
