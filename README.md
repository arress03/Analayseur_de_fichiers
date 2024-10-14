# Projet C - Analyseur de Fichier Texte

## Description

Ce projet est un **analyseur de fichier texte** développé en langage C. Il permet de lire un fichier texte et d'analyser son contenu, notamment en comptant le nombre de lignes, de mots, et de caractères.

## Fonctionnalités

- **Comptage des lignes** : Compte le nombre total de lignes dans le fichier texte.
- **Comptage des mots** : Compte le nombre total de mots dans le fichier.
- **Comptage des caractères** : Compte le nombre total de caractères dans le fichier.
- **Ecriture des résultats dans un fichier txt** : Ecrit les résultats dans un fichier txt.
- **Utilisation d'un makefile** : Compilation du projet avec un fichier `make.mak`.


## Utilisation

### Compilation

Pour compiler le projet, utilisez la commande suivante avec `mingw32-make`, sur Windows :

```bash
mingw32-make -f make.mak
```
ou `make` sur Linux 

```bash
make
```

**Cela génère l'exécutable analyseur_texte.exe.**

Executez le avec : 

```bash
./analyseur_texte
```

## Dépendances

- **GCC** :  Le projet utilise le compilateur GCC (GNU Compiler Collection).
- **MinGW** : Utilisé pour la compilation sous Windows.
- **Makefile** : Utilisé pour automatiser le processus de compilation.