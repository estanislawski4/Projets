#ifndef BARRECARREE_H
#define BARRECARREE_H

#include "barre.h"

class BarreCarree : public Barre
{
public:
    BarreCarree(const string _reference, const string _nomAlliage, const int _longueur, const float _densite, const int _cote);
    float CalculerSection();
    float CalculerMasse();
    void AfficherCaracteristiques();
private:
    int cote;
};

#endif // BARRECARREE_H
