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

## Fonctionnalités bonus 

- **Support Multilingue** : Prend en charge les textes en Français, Anglais, Russe et Espagnol, avec un menu interactif pour sélectionner la langue. [x]


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
./analyseur_texte
```
Un menu interactif s'affichera pour vous guider à travers les étapes :
Choisissez une langue parmi les 4 disponibles :

- Français
- Anglais
- Russe
- Espagnol

Entrez le nom du fichier à analyser : **Le fichier doit être dans le même dossier que l'exécutable.** Des fichiers dans chaque langues sont fournis.

Entrez le nom du fichier de sortie : Les résultats de l'analyse seront écrits dans ce fichier.

Voici un exemple dans le terminal : 

![PNG](https://i.gyazo.com/a8df0b013c2e2966c6aad36950a86e6a.png)

## Dépendances

- **GCC** :  Le projet utilise le compilateur GCC (GNU Compiler Collection).
- **MinGW** : Utilisé pour la compilation sous Windows.
- **Makefile** : Utilisé pour automatiser le processus de compilation.