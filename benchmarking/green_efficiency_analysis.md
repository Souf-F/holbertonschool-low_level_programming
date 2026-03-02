# Green Efficiency Analysis Report: Benchmarking and Instrumentation

## Measurement Methodology
Pour comprendre comment mon programme se comporte, j'ai dû mesurer le temps qu'il met à faire ses calculs. J'ai utilisé une technique appelée **l'instrumentation**. En langage C, cela se fait avec l'outil `clock()` qui se trouve dans la bibliothèque `<time.h>`. 

Imaginez que `clock()` est un chronomètre interne à l'ordinateur. Voici comment j'ai procédé techniquement :
1. J'ai créé une variable de type `clock_t` pour stocker le temps de départ.
2. J'ai lancé le calcul de mon algorithme.
3. J'ai repris le temps exact à la fin de l'exécution.

Le chiffre que l'ordinateur me donne n'est pas tout de suite en secondes, il est en "ticks" (ce sont comme des battements de cœur très rapides du processeur). Pour transformer ces battements en secondes normales que nous pouvons lire, j'ai divisé le résultat par une valeur fixe appelée `CLOCKS_PER_SEC`. 

J'ai découpé mon test en trois étapes précises : la création des données (BUILD), le calcul mathématique (PROCESS) et le résultat final (REDUCE). Pour être bien sûr de mes chiffres, j'ai lancé le test **3 fois**. C'est une étape cruciale car un ordinateur fait souvent plusieurs choses à la fois en arrière-plan (comme vérifier les mises à jour). Faire une moyenne de 3 essais permet d'obtenir un résultat plus honnête et d'éviter les erreurs de mesure accidentelles.



## Observed Performance Differences
Pendant mes tests de comparaison, j'ai remarqué une différence de vitesse incroyable entre deux manières de résoudre le même problème. Les résultats parlent d'eux-mêmes :
* **L'algorithme Naïf ($O(n^2)$)** : Il a mis environ **5,33 secondes**. Pour un ordinateur moderne, c'est extrêmement lent.
* **L'algorithme Single-pass ($O(n)$)** : Il a mis seulement **0,00019 secondes**.

Cela signifie que le deuxième code est environ **27 000 fois plus rapide** que le premier ! C’est la différence entre une personne qui marche à pied et un avion de ligne supersonique. Dans mon fichier `instrumentation_lab.c`, j'ai aussi remarqué que l'étape la plus longue n'est pas forcément le calcul mathématique lui-même, mais souvent la préparation des données (l'étape BUILD). Cela prouve que même un calcul très simple peut être ralenti si on prépare mal ses informations au début de l'exécution. L'organisation des données est donc aussi importante que le calcul.



## Relation Between Runtime and Energy Consumption
Il y a un lien direct et très fort entre le temps que met un programme à tourner et l'énergie qu'il consomme. Un processeur (le