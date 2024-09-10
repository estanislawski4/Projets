#include "barrerectangle.h"

BarreRectangle::BarreRectangle(const string _reference, const string _nomAlliage, const int _longueur, const float _densite, const int _largeur) : Barre(_reference, _nomAlliage, _longueur, _densite), largeur(_largeur) {}

float BarreRectangle::CalculerSection(){return largeur*longueur;}

float BarreRectangle::CalculerMasse(){return (CalculerSection() * densite) / 1000;}

void BarreRectangle::AfficherCaracteristiques() {
    cout << "Caractéristiques de la barre rectangle en " << nomAlliage << ":" << endl << endl;
    Barre::AfficherCaracteristiques();
    cout << "Section: " << CalculerSection() << endl;
    cout << "Masse: " << CalculerMasse() << " kg." << endl << endl;
}
