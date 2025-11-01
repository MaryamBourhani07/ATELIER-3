
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