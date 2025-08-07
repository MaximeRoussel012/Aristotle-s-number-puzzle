# Aristotle-s-number-puzzle
Le casse tête en bois d'Aristote est un plateau se présentant sous forme hexagonale dont chacune des pièces en bois est numérotée entre 1 et 19.
L'objectif du jeu est de trouver une combinaison telle que chaque ligne et chaque diagonale en somme fassent 38.

En voici une solution:

   10  12  16
  13  4  2  19
 15  8  5  7  3 
  14  6  1  17
   9  11  18   

La première idée est de re-numéroter chaque case comme suit:

     X_0  X_1  X_2
   X_3  X_4  X_5  X_6
 X_7  X_8  X_9  X_10  X_11 
   X_12  X_13  X_14  X_15
     X_16  X_17  X_18   

Il vient alors un vecteur X concaténant chaque ligne à la suite.

On séparera ensuite le projet en 2 parties distinctes 
-Etape 1 : L'anlyse des conditions sur le vecteur X.
-Etape 2: La mise en place du programme de résolution.


   
