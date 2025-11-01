#include <iostream>
using namespace std;

class Pile {
private:
    int* elements;     // Tableau dynamique pour stocker les éléments
    int tailleMax;     // Taille maximale de la pile
    int sommet;        // Indice du sommet de la pile

public:
    // Constructeur
    Pile(int taille = 10) {
        tailleMax = taille;
        elements = new int[tailleMax];
        sommet = -1;
    }

    // Destructeur
    ~Pile() {
        delete[] elements;
    }

    // Vérifie si la pile est vide
    bool estVide() const {
        return (sommet == -1);
    }

    // Vérifie si la pile est pleine
    bool estPleine() const {
        return (sommet == tailleMax - 1);
    }

    // Empiler un élément
    void push(int valeur) {
        if (estPleine()) {
            cout << "Pile pleine, impossible d'empiler " << valeur << endl;
            return;
        }
        elements[++sommet] = valeur;
    }

    // Dépiler un élément
    int pop() {
        if (estVide()) {
            cout << "Pile vide, rien à dépiler." << endl;
            return -1;
        }
        return elements[sommet--];
    }

    // Afficher le contenu de la pile
    void afficher() const {
        if (estVide()) {
            cout << "Pile vide." << endl;
            return;
        }
        cout << "Contenu de la pile : ";
        for (int i = 0; i <= sommet; i++) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

// ---------------------
// Programme principal
// ---------------------
int main() {
    Pile p1(5);  // Création de la première pile
    Pile p2(5);  // Création de la deuxième pile

    cout << "--- Empilage dans p1 ---" << endl;
    p1.push(10);
    p1.push(20);
    p1.push(30);
    p1.afficher();

    cout << "--- Empilage dans p2 ---" << endl;
    p2.push(100);
    p2.push(200);
    p2.push(300);
    p2.afficher();

    cout << "--- Dépiler p1 ---" << endl;
    cout << "Élément dépilé : " << p1.pop() << endl;
    p1.afficher();

    cout << "--- Dépiler p2 ---" << endl;
    cout << "Élément dépilé : " << p2.pop() << endl;
    p2.afficher();

    return 0;
}
/*
===========================
 Questions de réflexion
===========================

1 Différence entre copie superficielle et copie profonde :
------------------------------------------------------------
- Une copie superficielle duplique seulement les adresses mémoire (pointeurs).
- Une copie profonde crée un nouvel objet indépendant en mémoire.
- La copie profonde évite les conflits et les erreurs lors de la destruction.

2 Pourquoi le compteur du nombre de comptes doit-il être statique ?
--------------------------------------------------------------------
- Parce qu’il doit être partagé entre tous les objets de la classe.
- Une variable statique conserve sa valeur commune à toutes les instances.
- Cela permet de compter le nombre total de comptes existants.

3 Différence entre une méthode statique et une méthode normale :
-----------------------------------------------------------------
- Une méthode statique appartient à la classe et non à un objet.
- Elle ne peut pas accéder directement aux attributs non statiques.
- Une méthode normale agit sur un objet précis et accède à ses attributs.

4 Dans quel cas est-il pertinent de rendre une fonction inline ?
-----------------------------------------------------------------
- Quand la fonction est courte et fréquemment appelée.
- Pour éviter le coût d’un appel de fonction et accélérer l’exécution.
- Utile pour les petites fonctions utilitaires (comme des calculs simples).

5 Que se passe-t-il si on oublie de libérer la mémoire dans le destructeur ?
------------------------------------------------------------------------------
- Cela provoque une fuite de mémoire (memory leak).
- L’espace alloué dynamiquement n’est jamais libéré.
- Le programme consomme inutilement de la mémoire au fil du temps.
*/