#ifndef BARRERONDE_H
#define BARRERONDE_H

#include "barre.h"

class BarreRonde : public Barre
{
public:
    BarreRonde(const string _reference, const string _nomAlliage, const int _longueur, const float _densite, const int _diametre);
    float CalculerSection();
    void AfficherCaracteristiques();
private:
    int diametre;
};

#endif // BARRERONDE_H
