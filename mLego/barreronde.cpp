#include "barreronde.h"

BarreRonde::BarreRonde(const string _reference, const string _nomAlliage, const int _longueur, const float _densite, const int _diametre) : Barre(_reference, _nomAlliage, _longueur, _densite), diametre(_diametre) {
}

float BarreRonde::CalculerSection() {return 3.14*(diametre*diametre)/4;}

void BarreRonde::AfficherCaracteristiques() {
    cout << "Référence: " << reference << endl;
    cout << "Nom de l'alliage: " << nomAlliage << endl;
    cout << "Longueur: " << longueur << endl;
    cout << "Densité: " << densite << endl;
    cout << "Section: " << CalculerSection() << endl;
}
