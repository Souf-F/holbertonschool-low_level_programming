# 0x00 - Hello, World

## Ce que j'ai appris

Les différentes étapes de compilation en C et comment les utiliser avec `gcc`.

---

## Les étapes de compilation

| Fichier | Commande | Ce que ça fait |
|---|---|---|
| `0-preprocessor` | `gcc -E` | Préprocessing : remplace les `#include` et `#define` |
| `1-compiler` | `gcc -c` | Compilation : génère un fichier `.o` (objet) |
| `2-assembler` | `gcc -S` | Assemblage : génère un fichier `.s` (assembleur) |
| `3-name` | `gcc -E -o cisfun` | Préprocessing avec un nom de sortie personnalisé |

---

## Les fichiers C

| Fichier | Description |
|---|---|
| `4-puts.c` | Affiche une phrase avec `puts` |
| `5-printf.c` | Affiche une phrase avec `printf` |
| `6-size.c` | Affiche la taille en mémoire des types C (`char`, `int`, `float`...) |
| `main.c` | Fichier de base, retourne 0 |

---

## Ce qu'il faut retenir
```bash
gcc -E file.c -o file    # préprocesseur seulement
gcc -c file.c            # compile sans linker → génère .o
gcc -S file.c            # génère le code assembleur → .s
gcc file.c -o file       # compilation complète
```
```c
// Les tailles des types varient selon la machine
sizeof(char)          // 1 byte
sizeof(int)           // 4 bytes
sizeof(long long int) // 8 bytes
```