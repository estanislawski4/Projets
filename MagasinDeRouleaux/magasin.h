#ifndef MAGASIN_H
#define MAGASIN_H

#include <QWidget>
#include "alveoleslibres.h"
#include "stock.h"
#include "chariot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Magasin; }
QT_END_NAMESPACE

class Magasin : public QWidget
{
    Q_OBJECT

public:
    Magasin(QWidget *parent = nullptr);
    ~Magasin();

private slots:
    void on_pushButtonNouveau_clicked();
    void on_pushButtonRetrait_clicked();
    void on_pushButtonSupression_clicked();

private:
    Ui::Magasin *ui;
    Stock stock;
    AlveolesLibres alveolesLibres;
    Chariot chariot;
    QList<Rouleau> rouleauxEnceinte;

    void afficherStock();
    void afficherRouleauEnceinte();
};

#endif // MAGASIN_H
