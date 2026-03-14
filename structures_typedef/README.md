# 0x0E - Structures, typedef

## Ce que j'ai appris

Une `struct` permet de regrouper plusieurs variables de types différents dans un seul type.
`typedef` permet de donner un alias à ce type pour éviter d'écrire `struct dog` à chaque fois.

---

## Les fichiers

| Fichier | Description |
|---|---|
| `dog.h` | Définition de la structure `dog`, le `typedef dog_t`, et les prototypes |
| `1-init_dog.c` | Initialise les champs d'un `struct dog` existant |
| `2-print_dog.c` | Affiche les infos d'un chien, gère les valeurs `NULL` |
| `4-new_dog.c` | Crée un nouveau chien en mémoire dynamique avec `malloc` |

---

## Ce qu'il faut retenir
```c
// Déclarer une struct
struct dog {
    char *name;
    float age;
    char *owner;
};

// typedef pour simplifier
typedef struct dog dog_t;   // maintenant on écrit dog_t au lieu de struct dog

// Accéder aux champs
d->name   // via un pointeur
d.name    // via une variable directe

// Toujours libérer dans le bon ordre
free(dog->name);
free(dog->owner);
free(dog);
```