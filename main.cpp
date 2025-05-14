#include <iostream>
#include "Prioqueue.h"
#include "kopiec.h"
#include <fstream>

#include "test.h"

void menukopiec(Kopiec& kopiec) {
    int opcja;
    do {
        std::cout << "\n--- Menu Kopiec ---\n";
        std::cout << "1. Buduj z pliku\n";
        std::cout << "2. Usun element\n";
        std::cout << "3. Dodaj element\n";
        std::cout << "4. Znajdz max\n";
        std::cout << "5. Utworz losowo\n";
        std::cout << "6. Podaj wielkosc\n";
        std::cout << "0. Powrot\n";

        std::cout << "Twoj wybor: ";
        std::cin >> opcja;

        switch (opcja) {
            case 1: {
                kopiec.clear(); // zakładam, że masz funkcję clear()
                std::ifstream file("dane.txt");
                int val, pri;
                while (file >> val >> pri) {
                    kopiec.insert(val, pri);
                }
                file.close();
                break;
            }
            case 2:
                kopiec.extractMax();
                break;
            case 3: {
                int val, pri;
                std::cout << "Podaj wartosc i priorytet: ";
                std::cin >> val >> pri;
                kopiec.insert(val, pri);
                break;
            }
            case 4:
                std::cout << "Max element: " << kopiec.findMax().wartosc << "Max priorytet: " << kopiec.findMax().priorytet << "\n";
                break;
            case 5: {
                int ile;
                std::cout << "Ile elementow wygenerowac losowo? ";
                std::cin >> ile;
                kopiec.clear();
                srand(time(0));
                for (int i = 0; i < ile; i++) {
                    int val = rand() % 10000;
                    int pri = rand() % 10000;
                    kopiec.insert(val, pri);
                }
                break;
            }
            case 6:
                std::cout << "Wielkosc kopca: " << kopiec.returnSize() << "\n";
                break;
            case 0:
                break;
            default:
                std::cout << "Nieprawidlowy wybor!\n";
        }
    } while (opcja != 0);
}
void menuPrio(Kolejka& Kolejka) {
    int opcje;
    do {
        std::cout << "\n--- Menu HeapPriorityQueue ---\n";
        std::cout << "1. Usun element\n";
        std::cout << "2. Dodaj element\n";
        std::cout << "3. Znajdz max\n";
        std::cout << "4. Podaj wielkosc\n";
        std::cout << "5. Wyswietl kolejke\n";
        std::cout << "0. Powrot\n";
        std::cout << "Twoj wybor: ";
        std::cin >> opcje;

        switch (opcje) {
            case 1:
                Kolejka.extractMax();
                break;
            case 2: {
                int val, pri;
                std::cout << "Podaj wartosc i priorytet: ";
                std::cin >> val >> pri;
                Kolejka.insert(val, pri);
                break;
            }
            case 3:
                Kolejka.extractMax();
            case 4:
                std::cout << "Wielkosc kolejki: " << Kolejka.returnSize() << "\n";
                break;
            case 5:
                Kolejka.Wyswietl();
                break;
            case 0:
                break;
            default:
                std::cout << "Nieprawidlowy wybor!\n";
        }
    } while (opcje != 0);
}

int main() {
 
    Kopiec kopiec;
    Kolejka Kolejka;

    int wybor;
    do {
        std::cout << "=== MENU GLOWNE ===\n";
        std::cout << "1. Kolejka priorytetowa na liscie wiązanej\n";
        std::cout << "2. Kolejka priotytetowa na kopcu\n";
        std::cout << "3. Testuj\n";

        std::cout << "0. Wyjscie\n";
        std::cout << "Twoj wybor: ";
        std::cin >> wybor;

        switch (wybor) {
            case 1:
                menuPrio(Kolejka);
                break;
            case 2:
                menukopiec(kopiec);
                break;
            case 3:
                testowanie();
                break;
            case 0:
                std::cout << "Koniec programu.\n";
                break;
            default:
                std::cout << "Nieprawidlowy wybor!\n";
        }
    } while (wybor != 0);

    return 0;
}
