#ifndef ALVEOLESLIBRES_H
#define ALVEOLESLIBRES_H

#include <QStack>

class AlveolesLibres : public QStack<int>
{
public:
    AlveolesLibres(const int _nbRangees=2, const int _nbColonnes=3);
    bool Reserver(int& _rangee, int& _colonne);
    void Liberer(const int _rangee, const int _colonne);

private:
    int nbRangees;
    int nbColonnes;
};

#endif // ALVEOLESLIBRES_H