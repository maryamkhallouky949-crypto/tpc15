
#include <iostream>
#include <stdexcept>
using namespace std;

class File {
private:
    int* tableau;
    int capacite;
    int debut;
    int fin;
    int nombre;

public:
    
    File(int c) {
        capacite = c;
        tableau = new int[capacite];
        debut = 0;
        fin = -1;
        nombre = 0;
    }

    bool estVide() const {
        return nombre == 0;
    }

    bool estPleine() const {
        return nombre == capacite;
    }

  
    void enfiler(int valeur) {
        if (estPleine()) {
            throw overflow_error("Erreur : la file est pleine !");
        }

        fin = (fin + 1) % capacite;
        tableau[fin] = valeur;
        nombre++;

        cout << valeur << " ajoute a la file." << endl;
    }

    int defiler() {
        if (estVide()) {
            throw underflow_error("Erreur : la file est vide !");
        }

        int valeur = tableau[debut];

        debut = (debut + 1) % capacite;
        nombre--;

        return valeur;
    }

    void afficher() const {
        if (estVide()) {
            cout << "La file est vide." << endl;
            return;
        }

        cout << "File : ";

        for (int i = 0; i < nombre; i++) {
            cout << tableau[(debut + i) % capacite] << " ";
        }

        cout << endl;
    }

    
    ~File() {
        delete[] tableau;
    }
};

int main() {

    File f(5);

    int choix, valeur;

    do {
        cout << " MENU FILE" << endl;
        cout << "1. Enfiler" << endl;
        cout << "2. Defiler" << endl;
        cout << "3. Afficher" << endl;
        cout << "4. Verifier si vide" << endl;
        cout << "5. Quitter" << endl;

        cout << "Votre choix : ";
        cin >> choix;

        try {
            switch (choix) {

                case 1:
                    cout << "Donner une valeur : ";
                    cin >> valeur;
                    f.enfiler(valeur);
                    break;

                case 2:
                    valeur = f.defiler();
                    cout << "Element retire : " << valeur << endl;
                    break;

                case 3:
                    f.afficher();
                    break;

                case 4:
                    if (f.estVide())
                        cout << "La file est vide." << endl;
                    else
                        cout << "La file n'est pas vide." << endl;
                    break;

                case 5:
                    cout << "Fin du programme." << endl;
                    break;

                default:
                    cout << "Choix invalide !" << endl;
            }
        }
        catch (const exception& e) {
            cout << e.what() << endl;
        }

    } while (choix != 5);

    return 0;
}
