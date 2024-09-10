#ifndef BARRERECTANGLE_H
#define BARRERECTANGLE_H

#include "barre.h"

class BarreRectangle : public Barre
{
public:
    BarreRectangle(const string _reference, const string _nomAlliage, const int _longueur, const float _densite, const int _largeur);
    float CalculerSection();
    float CalculerMasse();
    void AfficherCaracteristiques();
private:
    int largeur;
};


#endif // BARRERECTANGLE_H
