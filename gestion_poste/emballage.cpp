#include "emballage.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Emballage::Emballage(const string _format, const int _resistance, const int _largeur, const int _longueur, const int _hauteur) {
    format = _format;
    resistance = _resistance;
    largeur = _largeur;
    longueur = _longueur;
    hauteur = _hauteur;
    stock = 0;

    cout << "Constructeur: Emballage / " << format << "." << endl;
}

void Emballage::Visualisation() {
    cout << "| " << setw(2) << format << " | ";
    cout << setw(5) << resistance << " kg | ";
    cout << setw(3) << largeur << " X " << setw(3) << longueur;

    if (hauteur != 0) {
        cout << " X " << setw(3) << hauteur;
    } else {
        cout << setw(6) << " ";
    }

    cout << " | " << setw(2) << stock << " en stock |" << endl;
}

Emballage::~Emballage()
{
    cout << "Destructeur: Emballage / " << format << "." << endl;
}

bool Emballage::operator<(const Emballage& autre) const {
    float volume1 = static_cast<float>(longueur) * largeur * (hauteur == 0 ? 1 : hauteur) / 1000.0;
    float volume2 = static_cast<float>(autre.longueur) * autre.largeur * (autre.hauteur == 0 ? 1 : autre.hauteur) / 1000.0;
    return volume1 < volume2;
}

bool Emballage::operator==(const Emballage& autre) const {
    return (format == autre.format &&
            resistance == autre.resistance &&
            largeur == autre.largeur &&
            longueur == autre.longueur &&
            hauteur == autre.hauteur);
}

Emballage::operator float() const {
    return static_cast<float>(longueur) * largeur * (hauteur == 0 ? 1 : hauteur) / 1000.0;
}
