# Kandis Tree

     a
   /   \
  b     c
 / \   / \
d   e f   g

## Hauteur de l'arbre
Deux écoles:
 - taille fixe défini par la dimension des données (think so...)
 - on impose un nombre de point max par nœud final et on construit l'arbre jusqu’à ce que chaque nœud respecte cette condition

si tu impose une nombre de points max par nœud final alors tu pourras mieux contrôler la vitesse a laquelle tu fera ta recherche du plus proche voisin
ça évite d'avoir des nœuds a 300 points. ce qui rend l'arbre inefficace.

## Les médianes
Comment stocker les médianes calculées a chaque étage ?
 - une classe nœud (a la grosse)
    struct Node{
        float value;
        Node* left;
        Node* right;
    };

    pros: facile de retirer et de rajouter des nœuds.
          relativement lisible.

    cons: ?

 - un vecteur:
 soit on range la donnée par étage
    abcdefg

 soit on range la donnée par cote
    abefcg

NB: veut on pouvoir modifier l'arbre ?
doit on attendre d'avoir plusieurs points avant des les ajouter (ou reconstruire un autre arbre) ou doit on avoir la possibilité de les rajouter au fur et a mesure ?

Tant de questions, pas de réponse !