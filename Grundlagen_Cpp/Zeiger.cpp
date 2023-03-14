#include <iostream>


void test_WhoAmI(int* pointer)
{
    std::cout << *pointer << std::endl;

    delete[] pointer;
}

int* test_PointerProvider()
{
    int* ip = new int[100]; 

    return ip;
}

void test_Zeiger()
{
    int* ip = new int[100];    // feld: Liegt am Heap

    // Zusammenspiel Zeiger -- Array Notation
    for (int i = 0; i < 100; ++i)
    {
        ip[i] = 2 * i;      //  Array Notation

        // Oder

        *(ip + i) = 2 * i;  // Zeiger Notation
    }

    test_WhoAmI(ip);

    delete[] ip;
}

void test_Frage()
{
    int feld [100];    // feld: Liegt am Stack

    // Hinweis:
    // Der Name eines Felds ('feld') für
    // die Adresse des ersten Elements

    test_WhoAmI(feld);

    // ZUsammenspiel Zeiger -- Array Notation
    for (int i = 0; i < 100; ++i)
    {
        feld[i] = 2 * i;      //  Array Notation

        // Oder

        *(feld + i) = 2 * i;  // Zeiger Notation
    }

    // delete[] feld;
}

int main_raw()
{
    std::cout << "Hallo Seminar - Zeiger\n";

    test_Frage();

    return 1;
}
