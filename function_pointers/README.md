# 0x0F - Function Pointers

## Ce que j'ai appris

Un pointeur de fonction c'est une variable qui stocke l'adresse d'une fonction.
Ça permet de passer une fonction en paramètre d'une autre fonction, comme une valeur normale.

---

## Les fichiers

| Fichier | Description |
|---|---|
| `0-print_name.c` | Appelle une fonction passée en paramètre pour afficher un nom |
| `1-array_iterator.c` | Applique une fonction sur chaque élément d'un tableau |
| `2-int_index.c` | Cherche dans un tableau le premier élément validé par une fonction de comparaison |
| `3-calc.h` | Structure `op_t` qui associe un opérateur (`+`, `-`...) à sa fonction |

---

## Ce qu'il faut retenir
```c
// Déclarer un pointeur de fonction
void (*f)(char *);          // pointeur vers une fonction qui prend un char* et retourne void
int (*f)(int, int);         // pointeur vers une fonction qui prend 2 int et retourne int

// Passer une fonction en paramètre
void print_name(char *name, void (*f)(char *))
{
    f(name);                // appel via le pointeur
}

// Structure avec pointeur de fonction
typedef struct op
{
    char *op;               // l'opérateur en string ex: "+"
    int (*f)(int a, int b); // la fonction associée
} op_t;
```