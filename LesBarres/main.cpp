#include <iostream>
#include "menu.h"
#include "catalogue.h"
#include "barreronde.h"
#include "barrecarree.h"

using namespace std;

int main() {
    try {
        // Créer un menu à partir du fichier texte
        Menu menu("../LesBarres/Catalogue.txt");

        Catalogue Catalogue1(4);

        int choix;
        do {
            choix = menu.Afficher();

            switch (choix) {
            case 1: {
                string ref, nom;
                int longueur, cote;
                float densite;
                cout << "Option 1 sélectionnée : Ajouter une barre carrée" << endl;
                cout << "Veuillez renseigner la référence de l'objet: " << endl;
                cin >> ref;
                cout << "Veuillez renseigner le nom de l'alliage: " << endl;
                cin >> nom;
                cout << "Veuillez renseigner la longueur de la barre: " << endl;
                cin >> longueur;
                cout << "Veuillez renseigner la densité de l'objet: " << endl;
                cin >> densite;
                cout << "Veuillez renseigner le côté de la barre: " << endl;
                cin >> cote;
                BarreCarree *objet = new BarreCarree(ref, nom, longueur, densite, cote);
                Catalogue1.AjouterBarre(objet);
                break;
            }
            case 2: {
                string ref, nom;
                int longueur, diametre;
                float densite;
                cout << "Option 1 sélectionnée : Ajouter une barre ronde" << endl;
                cout << "Veuillez renseigner la référence de l'objet: " << endl;
                cin >> ref;
                cout << "Veuillez renseigner le nom de l'alliage: " << endl;
                cin >> nom;
                cout << "Veuillez renseigner la longueur de la barre: " << endl;
                cin >> longueur;
                cout << "Veuillez renseigner la densité de l'objet: " << endl;
                cin >> densite;
                cout << "Veuillez renseigner le côté de la barre: " << endl;
                cin >> diametre;
                BarreRonde *objet = new BarreRonde(ref, nom, longueur, densite, diametre);
                Catalogue1.AjouterBarre(objet);
                break;
            }
            case 3: {
                cout << "Option 3 sélectionnée : Voir le catalogue" << endl;
                Catalogue1.AfficherCatalogue();
                break;
            }
            case 4: {
                cout << "Option 4 sélectionnée : Quitter" << endl;
                break;
            }
            default:
                cout << "Option invalide, veuillez réessayer." << endl;
                break;
            }

            Menu::AttendreAppuiTouche();

        } while (choix != 4);

    } catch (Exception &e) {
        cerr << "Erreur [" << e.ObtenirCodeErreur() << "] : " << e.ObtenirMessage() << endl;
    }

    return 0;
}
