#ifndef VECTEUR_H
#define VECTEUR_H

#include <string>
#include <iostream>

using namespace std;

class Vecteur
{
public:
    Vecteur(const double _x = 0, const double _y = 0);

    Vecteur operator+(const Vecteur &_autre);
    Vecteur operator-(const Vecteur &_autre);

    void Afficher();

    double getX() const;
    void setX(double newX);

    double getY() const;
    void setY(double newY);

private:
    double x;
    double y;
};

#endif // VECTEUR_H
