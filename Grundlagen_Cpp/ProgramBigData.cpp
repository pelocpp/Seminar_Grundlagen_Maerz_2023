#include <iostream>

#include "BigData.h"

int main_big_data()
{
    int a, b, c;

    a = (b = (c = 123));   // Mehrfachwertzuweisung

    BigData data (100);
    BigData anotherData(200);
    BigData moreData(300);

    data = (anotherData = moreData);

    // --------------------------

    int n (a);

    BigData againMoreData(data);  // Kopie von Data

    return 0;
}