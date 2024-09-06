#include <iostream>
#include "barre.h"
#include "barreronde.h"

using namespace std;

int main()
{
    BarreRonde test("1154", "Laiton", 73, 200.8, 4);
    test.AfficherCaracteristiques();
    return 0;
}
