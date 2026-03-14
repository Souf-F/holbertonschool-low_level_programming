# 0x0A - argc, argv

## Ce que j'ai appris

`argc` et `argv` permettent de passer des arguments à un programme C directement depuis le terminal.
- `argc` = le nombre d'arguments (le nom du programme compte comme 1)
- `argv` = le tableau qui contient tous les arguments sous forme de chaînes

---

## Les fichiers

| Fichier | Description |
|---|---|
| `1-args.c` | Affiche le nombre d'arguments reçus (sans compter le nom du programme) |
| `2-args.c` | Affiche tous les arguments reçus, un par ligne |
| `3-mul.c` | Multiplie deux nombres passés en argument, affiche `Error` si ce n'est pas exactement 2 |

---

## Ce qu'il faut retenir
```c
// argc - 1 pour exclure le nom du programme
printf("%d\n", argc - 1);

// argv[0] = nom du programme, argv[1] = premier vrai argument
printf("%s\n", argv[i]);

// atoi() pour convertir un argument string en entier
num1 = atoi(argv[1]);
```