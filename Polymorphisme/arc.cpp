#include "arc.h"

Arc::Arc(const double _rayon, const double _angleDebut, const double _angleFin, const double _vitesse) : rayon(_rayon), angleDebut(_angleDebut), angleFin(_angleFin) {
    vecteur = Vecteur();
    vitesse = _vitesse;
    duree = ObtenirLongueur()/vitesse;
    ObtenirArrivee();
}

Vecteur Arc::ObtenirArrivee()
{
    Vecteur ptCentre(rayon * cos(angleDebut),rayon * sin(angleDebut));
    Vecteur ptArrivee(rayon * cos(angleFin),rayon * sin(angleFin));
    return (ptArrivee - ptCentre);
}

double Arc::ObtenirLongueur() {
    return fabs(angleDebut - angleFin) * rayon;
}

double Arc::ObtenirDuree() {
    return duree;
}

void Arc::Afficher() {
    cout << left << "ARC R = " << setw(5) << rayon << " Angle Début = " << setw(10) << angleDebut << " Angle Fin = " << setw(10) << angleFin << " V = " << vitesse << endl;
}
