#include "comptebancaire.h"

CompteBancaire::CompteBancaire(float _solde) : solde(_solde) {}

void CompteBancaire::Deposer(float _montant) {
    if (_montant > 0) {
        solde += _montant;
    }
}

bool CompteBancaire::Retirer(float _montant) {
    if (_montant > 0 && solde >= _montant) {
        solde -= _montant;
        return true;
    }
    return false;
}

float CompteBancaire::Consulter() const {
    return solde;
}
