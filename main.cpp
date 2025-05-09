#include <iostream>

#include "Prioqueue.h"

int main() {
    Kolejka k1;
    k1.insert(5, 1);
    k1.insert(10, 5);
    k1.insert(2,3);
    k1.insert(19999, 2);
    k1.insert(1,999);
    k1.Wyswietl();
    k1.excractMax();
    k1.modifyKey(3,4444);
    k1.Wyswietl();


    return 0;
}
