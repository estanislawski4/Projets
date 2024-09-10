#ifndef BARRE_H
#define BARRE_H

#include <iostream>

using namespace std;

class Barre
{
public:
    Barre(const string _reference, const string _nomAlliage, const int _longueur, const float _densite);
    virtual ~Barre();
    virtual void AfficherCaracteristiques();
    virtual float CalculerMasse() = 0;
protected:
    string reference;
    string nomAlliage;
    int longueur;
    float densite;
};

#endif // BARRE_H
