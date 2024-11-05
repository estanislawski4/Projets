#include "magasin.h"
#include "ui_magasin.h"

#include <QMessageBox>
#include <QDebug>

Magasin::Magasin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Magasin)
    , alveolesLibres(3,3)
{
    ui->setupUi(this);
}

Magasin::~Magasin()
{
    delete ui;
}

void Magasin::on_pushButtonNouveau_clicked()
{
    QString reference = ui->lineEditReference->text();
    int diametre = ui->LineEditDiametre->text().toInt();

    if (!reference.isEmpty() && diametre > 0) {
        Rouleau nouveauRouleau(reference, diametre);

        int rangee, colonne;
        if (alveolesLibres.Reserver(rangee, colonne)) {
            nouveauRouleau.AffecterLocalisation(rangee, colonne);
            stock.AjouterRouleau(nouveauRouleau);

            chariot.DeplacerVers(rangee, colonne, true);

            afficherStock();

            ui->lineEditReference->clear();
            ui->LineEditDiametre->clear();
        }
        else {
            QMessageBox::warning(this, "Erreur", "Plus d'alvéoles libres disponibles.");
        }
    }
    else {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une référence et un diamètre valides.");
    }
}

void Magasin::on_pushButtonRetrait_clicked()
{
    QList<QMultiMap<int, Rouleau>::iterator> rouleauxASortir = stock.RechercherSerie();

    if (!rouleauxASortir.isEmpty())
    {
        QList<Rouleau> rouleauxToProcess;
        QList<QPair<int, int>> locations;

        for (auto it = rouleauxASortir.begin(); it != rouleauxASortir.end(); ++it)
        {
            Rouleau rouleau = it->value();
            int rangee, colonne;
            rouleau.ObtenirLocalisation(rangee, colonne);
            rouleauxToProcess.append(rouleau);
            locations.append(qMakePair(rangee, colonne));
        }

        for (const auto& it : rouleauxASortir)
        {
            stock.RetirerRouleauDuStock(it);
        }

        for (int i = 0; i < rouleauxToProcess.size(); ++i)
        {
            const Rouleau& rouleau = rouleauxToProcess[i];
            int rangee = locations[i].first;
            int colonne = locations[i].second;

            chariot.DeplacerVers(rangee, colonne, false);

            alveolesLibres.Liberer(rangee, colonne);

            rouleauxEnceinte.append(rouleau);
        }

        afficherStock();
        afficherRouleauEnceinte();
    }
    else
    {
        QMessageBox::information(this, "Information", "Aucun rouleau disponible pour le retraitement.");
    }
}

void Magasin::on_pushButtonSupression_clicked()
{
    if (!rouleauxEnceinte.isEmpty())
    {
        rouleauxEnceinte.clear();

        afficherRouleauEnceinte();
    }
    else
    {
        QMessageBox::information(this, "Information", "Aucun rouleau dans l'enceinte à supprimer.");
    }
}


void Magasin::afficherStock()
{
    ui->listWidgetStock->clear();
    QStringList contenuStock = stock.ObtenirContenuDuStock();
    ui->listWidgetStock->addItems(contenuStock);
}

void Magasin::afficherRouleauEnceinte()
{
    ui->listWidgetRouleauxRetenus->clear();
    for (const Rouleau& rouleau : rouleauxEnceinte)
    {
        QString itemText = QString("Rouleau: %1, Diamètre: %2").arg(rouleau.getReference()).arg(rouleau.getDiametre());
        ui->listWidgetRouleauxRetenus->addItem(itemText);
    }
}
