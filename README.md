# TP algo 

## 1. Quelques calculs simples 

### e = ∑∞n=0 1/n!:

meilleure précision avec double 
et la fonction récursive terminale prends moins de temps à s'exécuter.

### Puissance 

calculer (1 + 10−k)^10^k...

Sachant que (1 + x)1/x vaut environ
e ∗(1 −(1/2) ∗x + (11/24) ∗x2 −(7/16) ∗x3 + (2447/5760) ∗x4 −(959/2304) ∗x5 + O(x6))

|                                       | itératif | récursif | récursif terminale | récursif 2^p=2(n*2) |
| ------------------------------------- | :------- | -------- | ------------------ | ------------------- |
| mémoire                               |       +   |     +++     |         +           |           ++          |
| précision du résultat (double/ float) |     non     |     non     |          oui          |        oui             |
| temps de calcul                       |     ++     |     +++     |           ++         |          +           |


itératif 
récursif 
récursif terminal
récursif 2^p= 2(n*2)



### Ackermann 

les premières valeurs de  A(m,0): 1, 2, 3, 5, 13, 65533
la version 1 prends moins de mémoire on peut aller jusqu'à m=5,
la version 2 est néanmoins plus rapide dans le cas où n varie.



### Suite

x(100) impossible de la calculer avec des float, il faut des double

calculons x(100)
//La suite de réels (x(n))n∈N est définie par récurrence: x(0) = 1 puis ∀n ≥1,x(n) = x(n−1) + 1/x(n−1).

itératif 
récursif




## 2. Listes-Piles et Files
algo sur papier: ZeroEnDeuxiemePosition; QueDesZeros; Compte0Initiaux; IntersectionTriee; 
pas encore fait: ElimineKpremiersX; ElimineKderniersX; Permutations; Listes circulaires

## 3. Arbres: Quadtrees





## A faire:

-implémenter la partie 1 ✔️
-tester la partie 1 ✔️

-implémenter la partie 2 ✔️
-finir la partie 2
-tester la partie 2

-commencer la partie 3
