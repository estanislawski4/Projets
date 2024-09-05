#ifndef COMPTEBANCAIRE_H
#define COMPTEBANCAIRE_H

class CompteBancaire
{
public:
    CompteBancaire(float _solde = 0.0f);
    void Deposer(const float _montant);
    bool Retirer(const float _montant);
    float Consulter() const;
protected:
    float solde;
};

#endif // COMPTEBANCAIRE_H
