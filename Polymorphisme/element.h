#ifndef ELEMENT_H
#define ELEMENT_H

#include "vecteur.h"

class Element
{
public:
    Element();
    virtual ~Element();
    virtual void Afficher() = 0;
    int getNumero() const;
    void setNumero(int newNumero);
    virtual double ObtenirLongueur() = 0;
    virtual double ObtenirDuree() = 0;
    virtual Vecteur ObtenirArrivee() = 0;

protected:
    int numero;
    double vitesse;
    double duree;
    Vecteur vecteur;
};

#endif // ELEMENT_H
