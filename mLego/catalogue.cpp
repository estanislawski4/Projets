#include <iostream>
#include "catalogue.h"
                      using namespace std;
Catalogue::Catalogue(const int _nbBarres):
    nbBarres(_nbBarres)
{
    lesBarres = new Barre *[nbBarres];
    index = 0;
}
Catalogue::~Catalogue()
{
    for (int i = 0; i < index; ++i) {
        delete lesBarres[i];
    }
    delete[] lesBarres;
}

bool Catalogue::AjouterBarre(Barre *ptrBarre)
{
    bool retour = true;
    if (index < nbBarres)
        lesBarres[index++] = ptrBarre; // On ajoute un pointeur sur la barre
    else
        retour = false;
    return retour;
}

void Catalogue::AfficherCatalogue()
{
    for (int indice = 0; indice < index ; indice++)
    {
        lesBarres[indice]->AfficherCaracteristiques();
        cout << lesBarres[indice]->CalculerMasse() << endl;
    }
}
