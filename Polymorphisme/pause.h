#ifndef PAUSE_H
#define PAUSE_H

#include <iostream>

using namespace std;

class Pause
{
public:
    Pause(const int _tempsAttente);
    int Attendre(int _duree);
private:
    int tempsAttente;
};

#endif // PAUSE_H
