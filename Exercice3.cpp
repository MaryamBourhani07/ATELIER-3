#include <iostream>
using namespace std;

// Classe représentant un élément de la liste
class Element {
public:
    int valeur;        // donnée stockée
    Element* suivant;  // pointeur vers l’élément suivant

    // Constructeur
    Element(int val) {
        valeur = val;
        suivant = nullptr;
    }
};

// Classe Liste simplement chaînée
class Liste {
private:
    Element* premier;  // pointeur vers le premier élément

public:
    // Constructeur : liste vide
    Liste() {
        premier = nullptr;
    }

    // Destructeur : libère toute la mémoire
    ~Liste() {
        Element* courant = premier;
        while (courant != nullptr) {
            Element* temp = courant;
            courant = courant->suivant;
            delete temp;  // supprime chaque élément
        }
        premier = nullptr;
    }

    // Méthode pour ajouter un élément au début
    void ajouterDebut(int val) {
        Element* nouveau = new Element(val);
        nouveau->suivant = premier;
        premier = nouveau;
    }

    // Méthode pour supprimer un élément au début
    void supprimerDebut() {
        if (premier != nullptr) {
            Element* temp = premier;
            premier = premier->suivant;
            delete temp;
        } else {
            cout << "Liste vide, rien à supprimer.\n";
        }
    }

    // Méthode pour afficher la liste
    void afficher() const {
        if (premier == nullptr) {
            cout << "Liste vide.\n";
            return;
        }
        Element* courant = premier;
        cout << "Contenu de la liste : ";
        while (courant != nullptr) {
            cout << courant->valeur << " -> ";
            courant = courant->suivant;
        }
        cout << "NULL\n";
    }
};

// Fonction principale de test
int main() {
    Liste maListe;

    maListe.ajouterDebut(10);
    maListe.ajouterDebut(20);
    maListe.ajouterDebut(30);

    maListe.afficher();

    maListe.supprimerDebut();
    maListe.afficher();

    maListe.supprimerDebut();
    maListe.supprimerDebut();
    maListe.supprimerDebut(); // liste vide

    return 0;
}