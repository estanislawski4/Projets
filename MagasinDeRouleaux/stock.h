#ifndef STOCK_H
#define STOCK_H

#include "rouleau.h"
#include <QMultiMap>
#include <QStringList>
#include <QList>

class Stock
{
public:
    Stock();

    void AjouterRouleau(const Rouleau _nouveau);

    QList<QMultiMap<int, Rouleau>::iterator> RechercherSerie();

    bool RetirerRouleauDuStock(QMultiMap<int, Rouleau>::iterator position);

    QStringList ObtenirContenuDuStock() const;

private:
    QMultiMap<int, Rouleau> lesRouleaux;
};

#endif // STOCK_H
