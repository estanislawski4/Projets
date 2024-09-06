#include "compteclient.h"
#include "menu.h"

CompteClient::CompteClient(const string _nom, const int _numero) :
    compteBancaire(new CompteBancaire),
    compteEpargne(nullptr),
    nom(_nom),
    numero(_numero)
{

}

CompteClient::~CompteClient() {
    delete compteBancaire;
    delete compteEpargne;
}

void CompteClient::OuvrirCompteEpargne() {
    if (compteEpargne != nullptr) {
        cout << "Un compte épargne existe déjà. Vous ne pouvez pas en ouvrir un second." << endl;
    } else {
        double solde;
        double tauxInteret;

        cout << "Veuillez entrer le solde de départ pour le compte épargne: ";
        cin >> solde;

        cout << "Veuillez entrer le taux d'intérêt: ";
        cin >> tauxInteret;

        compteEpargne = new CompteEpargne(tauxInteret, solde);

        cout << "Le compte épargne a été créé avec succès." << endl;
    }
}

void CompteClient::GererCompteBancaire() {
    try {
        Menu menu("../ProjetBanque/compteBancaire.txt");
        int choix;
        do {
            choix = menu.Afficher();

            switch (choix) {
            case 1: {
                cout << "Option 1 sélectionnée : Dépôt" << endl;
                float montant;
                cout << "Entrez le montant à déposer : ";
                cin >> montant;

                if (montant > 0) {
                    compteBancaire->Deposer(montant);
                    cout << "Montant déposé avec succès." << endl;
                } else {
                    cout << "Le montant doit être positif." << endl;
                }
                break;
            }
            case 2: {
                cout << "Option 2 sélectionnée : Retrait" << endl;
                float montant;
                cout << "Entrez le montant à retirer : ";
                cin >> montant;

                if (compteBancaire->Retirer(montant)) {
                    cout << "Retrait réussi." << endl;
                } else {
                    cout << "Retrait échoué : solde insuffisant ou montant invalide." << endl;
                }
                break;
            }
            case 3: {
                cout << "Option 3 sélectionnée : Consulter solde" << endl;
                float solde = compteBancaire->Consulter();
                cout << "Solde actuel : " << solde << " euros" << endl;
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
}

void CompteClient::GererCompteEpargne() {
    if (compteEpargne == nullptr) {
        cout << "Vous n'avez pas encore de compte épargne. Veuillez en ouvrir un d'abord." << endl;
        return;
    }

    try {
        Menu menu("../ProjetBanque/compteEpargne.txt");
        int choix;
        do {
            choix = menu.Afficher();

            switch (choix) {
            case 1: {
                cout << "Option 1 sélectionnée : Dépôt" << endl;
                float montant;
                cout << "Entrez le montant à déposer : ";
                cin >> montant;

                if (montant > 0) {
                    compteEpargne->Deposer(montant);
                    cout << "Montant déposé avec succès." << endl;
                } else {
                    cout << "Le montant doit être positif." << endl;
                }
                break;
            }
            case 2: {
                cout << "Option 2 sélectionnée : Retrait" << endl;
                float montant;
                cout << "Entrez le montant à retirer : ";
                cin >> montant;

                if (compteEpargne->Retirer(montant)) {
                    cout << "Retrait réussi." << endl;
                } else {
                    cout << "Retrait échoué : solde insuffisant ou montant invalide." << endl;
                }
                break;
            }
            case 3: {
                cout << "Option 3 sélectionnée : Calculer les intérêts" << endl;
                compteEpargne->CalculerInterets();
                cout << "Les intérêts ont été calculés et ajoutés au solde." << endl;
                break;
            }
            case 4: {
                cout << "Option 4 sélectionnée : Consulter solde" << endl;
                float solde = compteEpargne->Consulter();
                cout << "Solde actuel : " << solde << " euros" << endl;
                break;
            }
            case 5: {
                cout << "Option 5 sélectionnée : Modifier le taux d'intérêt" << endl;
                float nouveauTaux;
                cout << "Entrez le nouveau taux d'intérêt : ";
                cin >> nouveauTaux;

                compteEpargne->ModifierTaux(nouveauTaux);
                cout << "Le taux d'intérêt a été modifié." << endl;
                break;
            }
            case 6: {
                // Option pour quitter
                cout << "Option 4 sélectionnée : Quitter" << endl;
                break;
            }
            default:
                cout << "Sortie du menu." << endl;
                break;
            }

            Menu::AttendreAppuiTouche();

        } while (choix != 6);

    } catch (Exception &e) {
        cerr << "Erreur [" << e.ObtenirCodeErreur() << "] : " << e.ObtenirMessage() << endl;
    }
}
