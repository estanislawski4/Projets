#include "barreronde.h"

BarreRonde::BarreRonde(const string _reference, const string _nomAlliage, const int _longueur, const float _densite, const int _diametre) : Barre(_reference, _nomAlliage, _longueur, _densite), diametre(_diametre) {}

float BarreRonde::CalculerSection(){return 3.14159 * (diametre * diametre) / 4;}

float BarreRonde::CalculerMasse(){return (longueur * CalculerSection() * densite) / 1000;}

void BarreRonde::AfficherCaracteristiques() {
    cout << "Caractéristiques de la barre ronde en " << nomAlliage << ":" << endl << endl;
    Barre::AfficherCaracteristiques();
    cout << "Section: " << CalculerSection() << endl;
    cout << "Masse: " << CalculerMasse() << " kg." << endl << endl;
}
