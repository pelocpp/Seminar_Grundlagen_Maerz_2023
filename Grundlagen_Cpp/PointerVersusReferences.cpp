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


void swap(int n, int m)
{
    int tmp = n;
    n = m;
    m = tmp;
}

// Variante 1: C
void swap1(int* n, int* m)
{
    int tmp = *n;
    *n = *m;
    *m = tmp;
}

// Variante 2: C++
void swap2(int& n, int& m)
{
    int tmp = n;
    n = m;
    m = tmp;
}


void testSwap()
{
    int x = 5;
    int y = 6;

    std::cout << x << ", " << y << std::endl;

    swap(x, y);

    std::cout << x << ", " << y << std::endl;

    swap1(&x, &y);

    std::cout << x << ", " << y << std::endl;

    swap2(x, y);

    std::cout << x << ", " << y << std::endl;
}