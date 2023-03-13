#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

#include <iostream>

#include "Time.h"

// forward declaration
void StackVersusHeap();
void PointerAndReferences();

// globales Objekt
Time ende (17, 0, 0);

int main_die_erste ()
{
    std::cout << "Hallo Seminar\n";

    Time jetzt(10, 18, 20);
    jetzt.print();

    Time leer;
    leer.print();

    return 0;
}

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    PointerAndReferences();

    return 0;
}

void Unterprogramm()
{
    // Objekt am Stack // temp. Variablen
    Time t(10, 40, 0);
    t.print();
}

void StackVersusHeap()
{
    // Objekt am Stack
    Time t1( 10, 30, 0);
    t1.print();

    Unterprogramm();

    // Objekt auf der Halde
    Time* t2 = new Time(10, 31, 0);
    t2->print();

    // ............

    // muss freigegeben werden - explizit
    delete t2;
}
