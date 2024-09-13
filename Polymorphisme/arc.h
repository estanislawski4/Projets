#ifndef ARC_H
#define ARC_H

#include "math.h"
#include <iostream>
#include <fstream>
#include <iomanip>

#include "element.h"
#include "vecteur.h"

using namespace std;

class Arc : public Element
{
public:
    Arc(const double _rayon, const double _angleDebut, const double _angleFin, const double _vitesse);
    virtual void Afficher();

    double ObtenirLongueur();
    Vecteur ObtenirArrivee();
    double ObtenirDuree();

private:
    double rayon;
    double angleDebut;
    double angleFin;
    double duree;
};

#endif // ARC_H
