#include "pause.h"

Pause::Pause(const int _tempsAttente) : tempsAttente(_tempsAttente) {}

int Pause::Attendre(int _duree) {
    cout << "Pause D = " << tempsAttente << endl;
    return _duree += tempsAttente;
}
