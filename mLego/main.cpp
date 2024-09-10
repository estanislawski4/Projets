#include <iostream>
#include "barre.h"
#include "barreronde.h"
#include "barrerectangle.h"
#include "barrecarree.h"

using namespace std;

int main()
{
    BarreRonde testRond("1154", "Laiton", 73,8.64, 4);
    testRond.AfficherCaracteristiques();
    BarreRectangle testRectangle("1154", "Laiton", 73,8.64, 4);
    testRectangle.AfficherCaracteristiques();
    BarreCarree testCarree("1154", "Laiton", 73,8.64, 4);
    testCarree.AfficherCaracteristiques();
    return 0;
}
