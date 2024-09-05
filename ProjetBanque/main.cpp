#include <iostream>
#include "menu.h"
#include "compteepargne.h"

using namespace std;

int main() {
    try {
        // Créer un menu à partir du fichier texte
        Menu menu("../ProjetBanque/compteEpargne.txt");

        // Créer un compte épargne avec un taux d'intérêt initial de 3% et un solde initial de 1000 euros
        CompteEpargne compteEpargne(3.0f, 1000.0f);

        int choix;
        do {
            choix = menu.Afficher();

            switch (choix) {
            case 1: {
                // Option pour le dépôt d'argent
                cout << "Option 1 sélectionnée : Dépôt" << endl;
                float montant;
                cout << "Entrez le montant à déposer : ";
                cin >> montant;

                if (montant > 0) {
                    compteEpargne.Deposer(montant);
                    cout << "Montant déposé avec succès." << endl;
                } else {
                    cout << "Le montant doit être positif." << endl;
                }
                break;
            }
            case 2: {
                // Option pour le retrait d'argent
                cout << "Option 2 sélectionnée : Retrait" << endl;
                float montant;
                cout << "Entrez le montant à retirer : ";
                cin >> montant;

                if (compteEpargne.Retirer(montant)) {
                    cout << "Retrait réussi." << endl;
                } else {
                    cout << "Retrait échoué : solde insuffisant ou montant invalide." << endl;
                }
                break;
            }
            case 3: {
                // Option pour calculer les intérêts
                cout << "Option 3 sélectionnée : Calculer les intérêts" << endl;
                compteEpargne.CalculerInterets();
                cout << "Les intérêts ont été calculés et ajoutés au solde." << endl;
                break;
            }
            case 4: {
                // Option pour consulter le solde
                cout << "Option 4 sélectionnée : Consulter solde" << endl;
                float solde = compteEpargne.Consulter();
                cout << "Solde actuel : " << solde << " euros" << endl;
                break;
            }
            case 5: {
                // Option pour modifier le taux d'intérêt
                cout << "Option 5 sélectionnée : Modifier le taux d'intérêt" << endl;
                float nouveauTaux;
                cout << "Entrez le nouveau taux d'intérêt : ";
                cin >> nouveauTaux;

                compteEpargne.ModifierTaux(nouveauTaux);
                cout << "Le taux d'intérêt a été modifié." << endl;
                break;
            }
            default:
                cout << "Sortie du menu." << endl;
                break;
            }

            Menu::AttendreAppuiTouche();

        } while (choix != -1);

    } catch (Exception &e) {
        cerr << "Erreur [" << e.ObtenirCodeErreur() << "] : " << e.ObtenirMessage() << endl;
    }

    return 0;
}
