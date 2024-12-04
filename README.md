# Projet C - Analyseur de Fichier Texte

## Description

Ce projet est un **analyseur de fichier texte** développé en langage C. Il permet de lire un fichier texte et d'analyser son contenu, notamment en comptant le nombre de lignes, de mots, et de caractères.

## Fonctionnalités

- **Comptage des lignes** : Compte le nombre total de lignes dans le fichier texte. [x]
- **Comptage des mots** : Compte le nombre total de mots dans le fichier. [x]
- **Comptage des caractères** : Compte le nombre total de caractères dans le fichier. [x]
- **Calcul de la fréquence de chaque mot** : Calcule la fréquence d'apparition de chaque mot dans le fichier. [x]
- **Affichage des mots les plus fréquents** : Affiche les mots les plus fréquents dans le fichier, dans l'ordre décroissant de fréquence. [x]
- **Ecriture des résultats dans un fichier txt** : Ecrit les résultats dans un fichier txt. [x]
- **Utilisation d'un makefile** : Compilation du projet avec un fichier `make.mak`. [x]


## Utilisation

Téléchargez le projet en **.zip** et extraire les fichiers.
Ouvrez le PowerShell ou le terminal Linux et allez au dossier du projet.

### Compilation

Pour compiler le projet, utilisez la commande suivante avec `mingw32-make`, sur Windows :

```bash
mingw32-make -f make.mak
```
Et ajoutez cette ligne de commande afin d'éviter les bugs d'affichage des accents dans le terminal :
```bash
chcp 65001
```
Sur Linux faites `make` : 

```bash
make
```

**Cela génère l'exécutable analyseur_texte.exe.**

Executez le avec : 

```bash
./analyseur_texte <nom du fichier à analyser> <nom du fichier de sortie>
```

**Il faut que le fichier txt à analyser soit dans le dossier du projet.**
Les resultats seront ecrits dans le fichier nommé **sortie.txt**.

## Dépendances

- **GCC** :  Le projet utilise le compilateur GCC (GNU Compiler Collection).
- **MinGW** : Utilisé pour la compilation sous Windows.
- **Makefile** : Utilisé pour automatiser le processus de compilation.