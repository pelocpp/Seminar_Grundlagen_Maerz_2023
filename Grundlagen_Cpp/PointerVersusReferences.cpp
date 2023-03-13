#include <iostream>

void PointerAndReferences()
{
    int n = 123;

    // 1. Möglichkeit des indirekten Zugriffs (C)
    // ------------------------------------------

    int* ip;   // Zeiger / Pointer

    ip = &n;   // Adresse von ...

    n = 456;   // direkten Zugriff

    // Zeiger - Arithmetik / Pointer - Arithmetik
    ip++;
    ip--;

    *ip = 789; // Indirekter Zugriff ...

    // ===========================================

    // 2. Möglichkeit des indirekten Zugriffs (C++)

    int& rp = n;   // Referenz

    n = 798;       // direkten Zugriff

    rp = 799;      // Indirekter Zugriff ...

    rp++;

    rp = 700;
}
