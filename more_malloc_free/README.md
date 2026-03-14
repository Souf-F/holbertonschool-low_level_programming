# 0x0A - malloc, free, structures

## Ce que j'ai appris

Dans ce projet j'ai appris à utiliser `malloc` et `free` pour gérer la mémoire dynamiquement en C.
Contrairement aux tableaux classiques déclarés en local, la mémoire allouée avec `malloc` :
- persiste après la fin d'une fonction
- doit être libérée manuellement avec `free` sinon c'est une fuite mémoire

---

## Les fonctions

### 0-create_array.c
Crée un tableau de `char` en mémoire dynamique et le remplit avec un caractère donné.
- J'ai appris à utiliser `malloc` pour allouer un bloc mémoire
- Et à initialiser case par case avec une boucle

### 1-strdup.c
Duplique une chaîne de caractères dans une nouvelle zone mémoire.
- J'ai appris à calculer la longueur d'une chaîne sans `strlen`
- À allouer exactement `len + 1` octets (le +1 c'est pour le `\0`)
- Et à copier caractère par caractère

### 2-str_concat.c
Concatène deux chaînes dans une nouvelle zone mémoire.
- J'ai appris à gérer les cas `NULL` en les remplaçant par `""`
- À calculer la taille totale avant d'allouer
- Et à copier les deux chaînes l'une après l'autre dans le résultat

### 3-alloc_grid.c
Alloue un tableau 2D d'entiers initialisé à 0.
- J'ai appris qu'un tableau 2D dynamique c'est un tableau de pointeurs, chaque pointeur pointant vers une ligne
- Et surtout comment gérer proprement un échec en cours d'allocation : libérer ce qui a déjà été alloué avant de retourner `NULL`

### 4-free_grid.c
Libère proprement un tableau 2D.
- J'ai appris qu'il faut libérer les lignes **avant** le tableau de pointeurs
- Sinon on perd les adresses et on a une fuite mémoire

---

## Ce qu'il faut retenir
```c
// Toujours vérifier que malloc n'a pas retourné NULL
ptr = malloc(size);
if (ptr == NULL)
    return (NULL);

// Toujours libérer dans le bon ordre pour un tableau 2D
// 1. les lignes
free(grid[i]);
// 2. le tableau de pointeurs
free(grid);
```

## Fichiers

| Fichier | Fonction | Description |
|---|---|---|
| `0-create_array.c` | `create_array()` | Crée et initialise un tableau de char |
| `1-strdup.c` | `_strdup()` | Duplique une chaîne en mémoire |
| `2-str_concat.c` | `str_concat()` | Concatène deux chaînes |
| `3-alloc_grid.c` | `alloc_grid()` | Alloue un tableau 2D à 0 |
| `4-free_grid.c` | `free_grid()` | Libère un tableau 2D |
| `main.h` | — | Prototypes de toutes les fonctions |