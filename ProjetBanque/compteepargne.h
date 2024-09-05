#ifndef COMPTEEPARGNE_H
#define COMPTEEPARGNE_H

#include "comptebancaire.h"

class CompteEpargne : public CompteBancaire {
public:
    // Constructeur avec taux d'intérêt et solde initial
    CompteEpargne(float _tauxInterets = 3.0f, float _solde = 0.0f);

    // Méthode pour calculer et ajouter les intérêts au solde
    void CalculerInterets();

    // Méthode pour modifier le taux d'intérêt
    void ModifierTaux(float _newTaux);

private:
    float tauxInterets;  // Taux d'intérêt en pourcentage
};

#endif // COMPTEEPARGNE_H
