#include <iostream>
#include "segment.h"
#include "trajectoire.h"

using namespace std;

int main()
{
    Segment s1(9.0, 0.0, 3);
    Segment s2(5.0, 0.927295, 1);
    Segment s3(6.0, 1.5708, 2);
    Trajectoire trajectoireBasique(6);
    trajectoireBasique.Ajouter(&s1);
    trajectoireBasique.Ajouter(&s2);
    trajectoireBasique.Ajouter(&s3);
    trajectoireBasique.Afficher();
    return 0;
}
