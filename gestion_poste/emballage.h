#ifndef EMBALLAGE_H
#define EMBALLAGE_H

#include <string>

using namespace std;

class Emballage
{
public:
    Emballage(const string _format, const int _resistance, const int _largeur, const int _longueur, const int _hauteur);
    void Visualisation();
    ~Emballage();

    bool operator<(const Emballage& autre) const;

    bool operator==(const Emballage& autre) const;

    operator float() const;

private:
    string format;
    int resistance;
    int largeur;
    int longueur;
    int hauteur;
    int stock;
};

#endif // EMBALLAGE_H
