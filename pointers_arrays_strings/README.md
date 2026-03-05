# C - Pointers, Arrays, and Strings

## 📌 Description
Ce dépôt contient mes solutions pour les projets sur les pointeurs, les tableaux et les chaînes de caractères. L'objectif est de maîtriser la gestion directe de la mémoire et la manipulation de données en C.

Tous les fichiers sont compilés avec `gcc` et respectent strictement la norme **Betty** (style et documentation).

## 🚀 Concepts Abordés

### 1. Pointeurs & Mémoire
* **Manipulation d'adresses :** Modification de variables via des pointeurs (`reset_to_98`, `swap`).
* **Arithmétique de pointeurs :** Navigation et modification de données sans utiliser d'index quand c'est nécessaire.

### 2. Chaînes de Caractères (Strings)
* **Fonctions de base :** Réimplémentation de `strlen`, `puts`, `strcpy`.
* **Transformations complexes :** Inversion de chaînes (`rev_string`), conversion en majuscules (`string_toupper`), et mise en majuscule des mots (`cap_string`).
* **Recherche :** Localisation de caractères (`_strchr`) et de sous-chaînes (`_strstr`).
* **Conversion :** Transformation de chaînes en entiers (`_atoi`) avec gestion des signes.

### 3. Tableaux (Arrays)
* **1D :** Inversion de tableaux d'entiers (`reverse_array`) et encodage personnalisé (`1337/leet`).
* **2D (Multidimensionnels) :** Affichage de plateaux de jeu (`print_chessboard`) et calculs sur des matrices carrées (`print_diagsums`).



## 📁 Structure du Projet

| Fichier | Fonction | Description |
| :--- | :--- | :--- |
| `0-reset_to_98.c` | `reset_to_98` | Met à jour la valeur pointée à 98. |
| `1-swap.c` | `swap_int` | Échange les valeurs de deux entiers. |
| `100-atoi.c` | `_atoi` | Convertit une chaîne en nombre entier. |
| `4-rev_array.c` | `reverse_array` | Inverse un tableau d'entiers. |
| `5-strstr.c` | `_strstr` | Localise une sous-chaîne. |
| `7-leet.c` | `leet` | Encode une chaîne en langage 1337. |
| `8-print_diagsums.c` | `print_diagsums` | Somme des diagonales d'une matrice. |

## 🛠️ Compilation & Tests
Pour tester les fonctions, utilise un fichier `main.c` avec le prototype correspondant et compile :
```bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 main.c <fichier.c> -o test
./test