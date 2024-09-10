#include "barrecarree.h"

BarreCarree::BarreCarree(const string _reference, const string _nomAlliage, const int _longueur, const float _densite, const int _cote) : Barre(_reference, _nomAlliage, _longueur, _densite), cote(_cote) {}

float BarreCarree::CalculerSection(){return cote*cote;}

float BarreCarree::CalculerMasse(){return (CalculerSection() * densite) / 1000;}

void BarreCarree::AfficherCaracteristiques() {
    cout << "Caractéristiques de la barre rectangle en " << nomAlliage << ":" << endl << endl;
    Barre::AfficherCaracteristiques();
    cout << "Section: " << CalculerSection() << endl;
    cout << "Masse: " << CalculerMasse() << " kg." << endl << endl;
}
