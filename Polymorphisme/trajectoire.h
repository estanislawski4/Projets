#ifndef TRAJECTOIRE_H
#define TRAJECTOIRE_H

#include <iostream>
#include "element.h"

using namespace std;

class Trajectoire
{
public:
    Trajectoire(const int _nbEtapesMaxi);
    ~Trajectoire();
    bool Ajouter(Element *_pElement);
    void Afficher();
private:
    Element **parcours;
    int nbEtapesMax;
    int prochaineEtape;
};

#endif // TRAJECTOIRE_H
