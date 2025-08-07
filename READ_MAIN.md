Dans cette seconde partie on détaille le code "main.cpp" à partir de l'anlyse faite en first_step.


Sachant qu'il nous faut déterminer 7 cases, on devra faire 7 "boucle for" imbriquées,
afin de réduire ce calcul on peut s'intéresser aux combinaisons possibles et faire un choix astucieux des cases testés.

En choisissant 6 cases parmi les cases aux bords du jeu, il suffit alors de lister les sommes d'entiers égales à 38 avec
3 chiffres distincts compris entre 1 et 19. 
On peut alors créer un vecteur v contenant, pour chaque entier i compris entre 1 et 19, 
un vecteur v[i] contenant chaque entier j tel qu'il existe une combinaison de 3 chiffres distincts compris entre 1 et 19 de somme 38.

Nous sommes donc en capacité de reconstituer les bords possibles du plateau.
Il suffit alors de tester une case au centre avec les numéros non utilisés sur les bords afin de déduire les autres cases du jeu.




