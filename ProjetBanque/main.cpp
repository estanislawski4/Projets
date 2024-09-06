#include <iostream>
#include "menu.h"
#include "compteclient.h"

using namespace std;

int main() {
    try {
        // Créer un menu à partir du fichier texte
        Menu menu("../ProjetBanque/CompteClient.txt");

        // Créer un compte épargne avec un taux d'intérêt initial de 3% et un solde initial de 1000 euros
        CompteClient compte("Albert", 1);

        int choix;
        do {
            choix = menu.Afficher();

            switch (choix) {
            case 1: {
                // Option pour ouvrir un compte Epargne
                cout << "Option 1 sélectionnée : Ouvrir un compte Epargne" << endl;
                compte.OuvrirCompteEpargne();
                break;
            }
            case 2: {
                // Option pour gérer le compte Bancaire
                cout << "Option 2 sélectionnée : Gérer le compte Bancaire" << endl;
                compte.GererCompteBancaire();
                break;
            }
            case 3: {
                // Option pour gérer le compte Epargne
                cout << "Option 3 sélectionnée : Gérer le compte Epargne" << endl;
                compte.GererCompteEpargne();
                break;
            }
            case 4: {
                // Option pour quitter
                cout << "Option 4 sélectionnée : Quitter" << endl;
                break;
            }
            default:
                cout << "Sortie du menu." << endl;
                break;
            }

            Menu::AttendreAppuiTouche();

        } while (choix != 4);

    } catch (Exception &e) {
        cerr << "Erreur [" << e.ObtenirCodeErreur() << "] : " << e.ObtenirMessage() << endl;
    }

    return 0;
}
