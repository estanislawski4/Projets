#include "vecteur.h"

Vecteur::Vecteur(const double _x, const double _y) : x(_x), y(_y) {}

Vecteur Vecteur::operator+(const Vecteur &_autre)
{
    x += _autre.getX();
    y += _autre.getY();
    return *this;
}

Vecteur Vecteur::operator-(const Vecteur &_autre)
{
    x -= _autre.getX();
    y -= _autre.getY();
    return *this;
}

void Vecteur::Afficher()
{
    cout << "Vecteur en (" << x << "," << y << ")" << endl;
}

double Vecteur::getX() const
{
    return x;
}

void Vecteur::setX(double newX)
{
    x = newX;
}

double Vecteur::getY() const
{
    return y;
}

void Vecteur::setY(double newY)
{
    y = newY;
}

