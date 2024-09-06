#include "barre.h"

Barre::Barre(const string _reference, const string _nomALliage, const int _longueur, const float _densite) {
    reference = _reference;
    nomAlliage = _nomALliage;
    longueur = _longueur;
    densite = _densite;
}

void Barre::AfficherCaracteristiques() {
    cout << "Référence: " << reference << endl;
    cout << "Nom de l'alliage: " << nomAlliage << endl;
    cout << "Longueur: " << longueur << endl;
    cout << "Densité: " << densite << endl;
}
