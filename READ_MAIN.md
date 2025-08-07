Dans cette seconde partie on détail le main à partir de l'anlyse faite en first_step.


Sachant qu'il nous faut déterminer 7 cases, on devra faire 7 "boucle for" imbriqués,
afin de réduire ce calcul on peut s'intéresser aux combinaisons possibles et faire un choix astucieux des cases testés.

En choisissant 6 cases parmis les cases aux bords du jeu, il suffit alors lister les sommes d'entiers égales à 38 avec
3 chiffres distinct compris entre 1 et 19. 
On peut alors créer un vecteur v contenant pour chaque entier i compris entre 1 et 19, 
un vecteur v[i] contenant chaque entier j tel qu'il existe une combinaison de 3 chiffres distinct compris entre 1 et 19 de somme 38.

Nous sommes en capacité de reconstituer les bords possibles du plateau.
Il suffit donc de tester une case au centre avec les numéros non utilisés sur les bord afin de complèter de facon unique les autres cases du jeu.




