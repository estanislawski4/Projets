#include <iostream>
#include "emballage.h"

using namespace std;

const int NB_COLIS = 2;

int main()
{
    // Emballage Test("xl", 2, 5,96,8);
    // Test.Visualisation();
    // Emballage *TestColis;
    // TestColis = new Emballage("xs", 2, 5,96,8);
    // delete TestColis;

    Emballage* Colis[NB_COLIS];

    for (int i = 0; i < NB_COLIS; i++) {
        string format;
        int resistance, largeur, longueur, hauteur;

        cout << "Entrez les caractéristiques de l'emballage " << i+1 << " : " << endl;
        cout << "Format: ";
        cin >> format;
        cout << "Résistance (kg): ";
        cin >> resistance;
        cout << "Largeur: ";
        cin >> largeur;
        cout << "Longueur: ";
        cin >> longueur;
        cout << "Hauteur (0 si non applicable): ";
        cin >> hauteur;

        Colis[i] = new Emballage(format, resistance, largeur, longueur, hauteur);
    }

    cout << "\nCatalogue des emballages : \n";
    cout << "+----+----------+-----------------+------------+\n";
    for (int i = 0; i < NB_COLIS; i++) {
        Colis[i]->Visualisation();
    }
    cout << "+----+----------+-----------------+------------+\n";

    if (*Colis[0] < *Colis[1]) {
        cout << "Le colis1 a un plus petit volume que colis2." << endl;
    } else if (*Colis[0] > *Colis[1]) {
        cout << "Le colis2 a un plus petit volume que colis1." << endl;
    } else {
        cout << "Les 2 colis ont le même volume." << endl;
    }

    if (*Colis[0] == *Colis[1]) {
        cout << "colis1 est identique à colis2." << endl;
    } else {
        cout << "colis1 n'est pas identique à colis2." << endl;
    }

    float volume;
    volume = static_cast<float>(*Colis[0]);
    cout << "Le volume de colis1 est de " << volume << " cm³." << endl;

    for (int i = 0; i < NB_COLIS; i++) {
        delete Colis[i];
    }

    return 0;
}
