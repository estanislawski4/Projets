#include <iostream>
#include "segment.h"
#include "trajectoire.h"

using namespace std;

int main()
{
    Segment *segment1 = new Segment(34.0, 44.0);
    Trajectoire trajectoireBasique(6);
    trajectoireBasique.Ajouter(segment1);
    trajectoireBasique.Afficher();
    return 0;
}
