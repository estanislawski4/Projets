#include "compteepargne.h"

CompteEpargne::CompteEpargne(float _tauxInterets, float _solde)
    : CompteBancaire(_solde), tauxInterets(_tauxInterets) {}

void CompteEpargne::CalculerInterets() {
    float interets = Consulter() * (tauxInterets / 100);
    Deposer(interets);
}

void CompteEpargne::ModifierTaux(float _newTaux) {
    if (_newTaux > 0 && _newTaux <= 100) {
        tauxInterets = _newTaux;
    }
}
