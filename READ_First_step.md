Dans cette partie nous étudions la première étape (first_step_1 et first_step_2).

L'idée générale étant d'écrire le problème sous forme A*X=b, 
avec A une matrice de taille 19*19 inversible, b un vecteur de taille 19 et X le vecteur solution du problème.

En considérant que la somme fait 38 sur les 5 lignes et les 10 diagonales du casse-tête, il vient à priori 15 conditions.
Cependant le code "first_step_1" montre une dépendance linéaire entre les conditions, il y a donc seulement 12 conditions indépendantes.
Le vecteur b quant à lui est donc rempli de 38 sur ses 12 premières lignes. 

Il est donc nécessaire d'imposer une condition sur 7 cases à minima. 

Le code "first_step_2" nous permet de compléter ces 12 conditions via 7 nouvelles contraintes.
Autrement dit si on connait le numéro de 7 cases spécifiquement et qu'on les enregistre dans le vecteur b suite au 12 premières,
il vient alors une unique solution X=A^(-1)*b.

Grâce au code "first_step_2" et la théorie on doit donc pouvoir résoudre le problème en ne cherchant qu'à travers 7 cases. 
