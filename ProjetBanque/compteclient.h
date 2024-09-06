#ifndef COMPTECLIENT_H
#define COMPTECLIENT_H

#include "comptebancaire.h"
#include "compteepargne.h"
#include <string>
#include <iostream>

using namespace std;

class CompteClient {

public:
    CompteClient(const string _nom, const int _numero);
    ~CompteClient();

    void OuvrirCompteEpargne();
    void GererCompteBancaire();
    void GererCompteEpargne();
private:
    CompteBancaire *compteBancaire;
    CompteEpargne *compteEpargne;
    string nom;
    int numero;
};

#endif // COMPTECLIENT_H
