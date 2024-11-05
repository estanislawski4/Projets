#include "rouleau.h"

Rouleau::Rouleau(const QString& _reference, const int _diametre)
    : reference(_reference), diametre(_diametre), rangee(-1), colonne(-1)
{
}

Rouleau::~Rouleau()
{
}

void Rouleau::AffecterLocalisation(const int _rangee, const int _colonne)
{
    rangee = _rangee;
    colonne = _colonne;
}

void Rouleau::ObtenirLocalisation(int& _rangee, int& _colonne) const
{
    _rangee = rangee;
    _colonne = colonne;
}

QString Rouleau::getReference() const
{
    return reference;
}

int Rouleau::getDiametre() const
{
    return diametre;
}
