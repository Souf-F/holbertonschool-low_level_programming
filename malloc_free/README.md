# 0x0A - malloc, free, structures

## Ce que j'ai appris

`malloc` sert à réserver de la mémoire pendant l'exécution du programme, contrairement aux tableaux classiques dont la taille doit être connue à l'avance.
Cette mémoire ne se libère pas toute seule, il faut obligatoirement appeler `free` sinon c'est une fuite mémoire.

---

## Les fonctions

| Fichier | Fonction | Description |
|---|---|---|
| `0-create_array.c` | `create_array()` | Alloue un tableau de `char` et le remplit avec un caractère donné |
| `1-strdup.c` | `_strdup()` | Duplique une chaîne dans une nouvelle zone mémoire |
| `2-str_concat.c` | `str_concat()` | Concatène deux chaînes dans une nouvelle zone mémoire |
| `3-alloc_grid.c` | `alloc_grid()` | Alloue un tableau 2D d'entiers initialisé à 0 |
| `4-free_grid.c` | `free_grid()` | Libère proprement un tableau 2D |

---

## Ce qu'il faut retenir
```c
// Toujours vérifier que malloc n'a pas retourné NULL
ptr = malloc(size);
if (ptr == NULL)
    return (NULL);

// Pour un tableau 2D : libérer les lignes AVANT le tableau de pointeurs
free(grid[i]);   // 1. chaque ligne
free(grid);      // 2. le tableau
```