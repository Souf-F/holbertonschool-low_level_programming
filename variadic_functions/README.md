# 0x10 - Variadic Functions

## Ce que j'ai appris

Les fonctions variadiques permettent de passer un nombre variable d'arguments à une fonction.
On utilise `va_list`, `va_start`, `va_arg` et `va_end` de `<stdarg.h>` pour les lire un par un.

---

## Les fichiers

| Fichier | Description |
|---|---|
| `0-sum_them_all.c` | Additionne tous les entiers passés en argument |
| `1-print_numbers.c` | Affiche des entiers séparés par une chaîne donnée |
| `2-print_strings.c` | Affiche des chaînes séparées par une chaîne donnée, `(nil)` si NULL |

---

## Ce qu'il faut retenir
```c
va_list args;           // déclare la liste d'arguments
va_start(args, n);      // initialise à partir du dernier argument fixe
va_arg(args, int);      // récupère le prochain argument du type donné
va_end(args);           // ferme proprement la liste
```