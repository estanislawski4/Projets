#ifndef SEGMENT_H
#define SEGMENT_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "element.h"

using namespace std;

class Segment : public Element
{
public:
    Segment(const double _longueur, const double _angle, const double _vitesse);
    virtual void Afficher();

    double ObtenirLongueur();
    Vecteur ObtenirArrivee();
    double ObtenirDuree();
private:
    double longueur;
    double angle;
};

#endif // SEGMENT_H
