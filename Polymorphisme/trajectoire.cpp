#include "trajectoire.h"

Trajectoire::Trajectoire(const int _nbEtapesMaxi) :
    nbEtapesMax(_nbEtapesMaxi),
    prochaineEtape(0)
{
    depart.setX(5);
    depart.setY(10);
    parcours = new Element*[_nbEtapesMaxi];
}

Trajectoire::~Trajectoire() {

    delete[] parcours;
}

bool Trajectoire::Ajouter(Element *_pElement) {
    bool retour = true;
    if (prochaineEtape < nbEtapesMax) {
        parcours[prochaineEtape++] = _pElement;
        _pElement->setNumero(prochaineEtape);
    } else {
        retour = false; }
    return retour;
}

void Trajectoire::Afficher() {
    cout << "Trajectoire : " << endl << endl;
    double newLong = 0;
    double newDuree = 0;
    Vecteur newVecteur;
    newVecteur = depart;
    for (int indice = 0; indice < prochaineEtape ; indice++)
    {
        parcours[indice]->Afficher();
        newLong += parcours[indice]->ObtenirLongueur();
        newDuree += parcours[indice]->ObtenirDuree();

        newVecteur = newVecteur + parcours[indice]->ObtenirArrivee();
        newVecteur.Afficher();
    }

    Pause petitePause(4);
    cout << "(" << prochaineEtape+1 << ") ";
    newDuree = petitePause.Attendre(newDuree);
    newVecteur.Afficher();

    Arc newArc = Arc(5, 3.14159, 0, 6);

    newLong += newArc.ObtenirLongueur();
    newDuree += newArc.ObtenirDuree();
    cout << "(" << prochaineEtape+2 << ") ";
    newArc.Afficher();
    newVecteur = newVecteur + newArc.ObtenirArrivee();
    newVecteur.Afficher();

    newLong = roundf(newLong * 1000) / 1000;
    newDuree = roundf(newDuree * 1000) / 1000;

    cout << endl << "Durée totale du parcours = " << newDuree << endl << "Longueur totale du parcours = " << newLong << endl << endl;
    cout << "Vecteur de départ = ";
    depart.Afficher();
    cout << "Vecteur d'arrivé = ";
    newVecteur.Afficher();
}
