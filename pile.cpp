
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
using namespace std;


template <typename T>
class Pile {
private:
    vector<T> elements;

public:

    void empiler(T element) {
        elements.push_back(element);
    }

   
    T depiler() {
        if (estVide()) {
            throw underflow_error("Erreur : la pile est vide !");
        }

        T element = elements.back();
        elements.pop_back();

        return element;
    }

    
    T sommet() const {
        if (estVide()) {
            throw underflow_error("Erreur : la pile est vide !");
        }

        return elements.back();
    }

    bool estVide() const {
        return elements.empty();
    }


    void inverser() {
        reverse(elements.begin(), elements.end());
    }

    void afficher() const {
        cout << "Pile : ";

        for (int i = elements.size() - 1; i >= 0; i--) {
            cout << elements[i] << " ";
        }

        cout << endl;
    }
};

int main() {

   
    cout << " Pile d'entiers " << endl;

    Pile<int> p1;

    p1.empiler(10);
    p1.empiler(20);
    p1.empiler(30);

    p1.afficher();

    cout << "Sommet : " << p1.sommet() << endl;
    cout << "Element depile : " << p1.depiler() << endl;

    p1.afficher();

    cout << " Pile de chaines " << endl;

    Pile<string> p2;

    p2.empiler("Ali");
    p2.empiler("Sara");
    p2.empiler("Maryam");

    p2.afficher();

    cout << "Element depile : " << p2.depiler() << endl;

    p2.afficher();


    cout << " Pile de reels " << endl;

    Pile<double> p3;

    p3.empiler(10.5);
    p3.empiler(20.5);
    p3.empiler(30.5);

    p3.afficher();

    
    cout << "Apres inversion :" << endl;

    p3.inverser();
    p3.afficher();

    cout << " Test exception " << endl;

    try {
        Pile<int> p4;
        p4.depiler();
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
