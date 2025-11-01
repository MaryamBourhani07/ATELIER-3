#include <iostream>
#include <cstring>
using namespace std;

class Fichier {
private:
    char* p;    // pointeur vers la mémoire
    int longueur;

public:
    // Constructeur
    Fichier() {
        p = nullptr;
        longueur = 0;
        cout << "Constructeur appelé." << endl;
    }

    // Méthode Creation : allouer un espace mémoire
    void Creation(int l) {
        longueur = l;
        p = new char[longueur];
        cout << "Espace mémoire de " << longueur << " octets alloué." << endl;
    }

    // Méthode Remplit : remplir avec une chaîne arbitraire
    void Remplit(const char* texte) {
        if (p != nullptr)
            strncpy(p, texte, longueur);
    }

    // Méthode Affiche : afficher le contenu du fichier
    void Affiche() {
        if (p != nullptr)
            cout << "Contenu du fichier : " << p << endl;
        else
            cout << "Aucun contenu à afficher." << endl;
    }

    // Destructeur
    ~Fichier() {
        delete[] p;
        cout << "Destructeur appelé. Mémoire libérée." << endl;
    }
};

// ---------- MAIN ----------
int main() {
    Fichier* f = new Fichier(); // création par pointeur
    f->Creation(50);            // allocation de 50 octets
    f->Remplit("Bonjour, ceci est un test de la classe Fichier !");
    f->Affiche();

    delete f; // destruction de l’objet
    return 0;
}