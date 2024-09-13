#include "segment.h"

Segment::Segment(const double _longueur, const double _angle, const double _vitesse) : longueur(_longueur), angle(_angle) {
    vitesse = _vitesse;
    vecteur = Vecteur();
    duree = longueur/vitesse;
    ObtenirArrivee();
}

double Segment::ObtenirLongueur() {
    return longueur;
}

double Segment::ObtenirDuree() {
    return duree;
}

Vecteur Segment::ObtenirArrivee() {
    vecteur.setX(longueur*cos(angle));
    vecteur.setY(longueur*sin(angle));

    return vecteur;
}

void Segment::Afficher()
{
    cout << left << "(" << getNumero() << ") SEGMENT L = " << setw(5) << longueur << "A = " << setw(10) << angle << " V = " << vitesse << endl;
}
