#include "alveoleslibres.h"
#include <QDebug>

AlveolesLibres::AlveolesLibres(const int _nbRangees, const int _nbColonnes) : nbRangees(_nbRangees), nbColonnes(_nbColonnes) {
    this->reserve(_nbRangees*_nbColonnes);
    for (int i = 0; i < _nbRangees * _nbColonnes; i++) {
        this->push(i + 1);
    }
}

bool AlveolesLibres::Reserver(int& _rangee, int& _colonne)
{
    if (!this->isEmpty()) {
        int numeroAlveole = this->pop();
        _rangee = (numeroAlveole - 1) / nbColonnes + 1;
        _colonne = (numeroAlveole - 1) % nbColonnes + 1;
        qInfo() << "Reserver :" << *this;
        return true;
    }
    qInfo() << "Reserver :" << *this;
    return false;
}

void AlveolesLibres::Liberer(const int _rangee, const int _colonne)
{
    int numeroAlveole = (_rangee - 1) * nbColonnes + _colonne;
    if (!this->contains(numeroAlveole)) {
        this->push(numeroAlveole);
    }
    qInfo() << "Liberer :" << *this;
}
