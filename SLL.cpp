    #include "SLL.h"
    #include <iostream>
    using namespace std;
    //Konstruktor i destruktor
    ListaJednokierunkowa::ListaJednokierunkowa() : head(nullptr), tail(nullptr) {}

    ListaJednokierunkowa::~ListaJednokierunkowa() {
        SLLNode* wezel = head;
        while (wezel != nullptr) {
            SLLNode* NastepnyWezel = wezel->NastepnyWezel;
            delete wezel;
            wezel = NastepnyWezel;
        }
        head = nullptr;
        tail = nullptr;
    }
    //DodajHead - dodaje element na początek listy
    void ListaJednokierunkowa::DodajHead(int val) {
        SLLNode* NowyWezel = new SLLNode(val); //tworzymy nowy węzeł
        if (head == nullptr) {
            head = tail = NowyWezel; //jeśli lista jest pusta, to nowy węzeł staje się zarówno head, jak i tail
        } else {
            NowyWezel->NastepnyWezel = head; //ustawiamy wskaźnik nowego węzła na aktualny head
            head = NowyWezel; //aktualizujemy head na nowy węzeł
        }
    }
    //DodajTail - dodaje element na koniec listy
    void ListaJednokierunkowa::DodajTail(int val) {
        SLLNode* NowyWezel = new SLLNode(val);
        if (tail == nullptr) {
            head = tail = NowyWezel;
        } else {
            tail->NastepnyWezel = NowyWezel;
            tail = NowyWezel;
        }
    }
    //UsunHead - usuwa element z początku listy
    void ListaJednokierunkowa::UsunHead() {
        if (head == nullptr) return;

        SLLNode* temp = head;
        head = head->NastepnyWezel;
        delete temp;
    //aktualizujemy tail, jeśli lista stała się pusta
        if (head == nullptr) {
            tail = nullptr;
        }
    }
    ///UsunTail - usuwa element z końca listy
    void ListaJednokierunkowa::UsunTail() {
        if (head == nullptr) return;

        SLLNode* wezel = head;
        while (wezel->NastepnyWezel != tail) {
            wezel = wezel->NastepnyWezel;
        }
        delete tail;
        tail = wezel;
        tail->NastepnyWezel = nullptr;
    }
    //DodajLosowo - dodaje element w losowym miejscu listy
    void ListaJednokierunkowa::DodajLosowo(int val, int index) {
            if (index <= 0) {
                DodajHead(val);
                return;
            }

            SLLNode* wezel = head;

            // Przechodzimy do węzła na pozycji index - 1

            for (int i = 0; i < index - 1 && wezel != nullptr; ++i) {
                wezel = wezel->NastepnyWezel;
            }
            // Jeśli index jest większy niż rozmiar listy, dodajemy na końcu
            if (wezel == nullptr) {
                DodajTail(val);
            } else {
                // Tworzymy nowy węzeł i wstawiamy go po węźle na pozycji index - 1
                SLLNode* NowyWezel = new SLLNode(val);
                NowyWezel->NastepnyWezel = wezel->NastepnyWezel;
                wezel->NastepnyWezel = NowyWezel;
            }
    }
    //UsunLosowo - usuwa element z losowego miejsca listy
    void ListaJednokierunkowa::UsunLosowo(int index) {
        if (head == nullptr) return;

        SLLNode* wezel = head;
        SLLNode* poprzedniWezel = nullptr;
    // Przechodzimy do węzła na pozycji index
        for (int i = 0; i < index && wezel != nullptr; ++i) {
            poprzedniWezel = wezel;
            wezel = wezel->NastepnyWezel;
        }

        if (wezel == nullptr) return;

        if (poprzedniWezel == nullptr) {
            head = wezel->NastepnyWezel;
            delete wezel;
        } else {
            // Jeśli usuwamy węzeł z listy, aktualizujemy wskaźnik poprzedniego węzła
            poprzedniWezel->NastepnyWezel = wezel->NastepnyWezel;
            delete wezel;
        }
    }
    //Znajdz - wyszukuje element w liście
    //Jeśli element zostanie znaleziony, wyświetli jego indeks, w przeciwnym razie wyświetli komunikat, że nie znaleziono elementu
    void ListaJednokierunkowa::Znajdz(int val) {
        SLLNode* wezel = head;
        int index = 0;
        while (wezel != nullptr) {
            if (wezel->value == val) {
                cout << "Znaleziono " << val << " na indeksie " << index << ".\n";
                return;
            }
            wezel = wezel->NastepnyWezel;
            index++;
        }
        cout << "Nie znaleziono " << val << ".\n";
    }
    //Wyswietl - wyświetla całą listę
    //Wyświetla elementy w formacie: 1 -> 2 -> 3 -> nullptr
    void ListaJednokierunkowa::Wyswietl() {
        SLLNode* wezel = head;
        while (wezel != nullptr) {
            cout << wezel->value << " -> ";
            wezel = wezel->NastepnyWezel;
        }
        cout << "nullptr\n";
    }
    //Rozmiar - zwraca rozmiar listy
    //Zlicza liczbę węzłów w liście, przechodząc przez każdy węzeł i zwiększając licznik
    int ListaJednokierunkowa::Rozmiar() {
        int rozmiar = 0;
        SLLNode* wezel = head;
        while (wezel != nullptr) {
            rozmiar++;
            wezel = wezel->NastepnyWezel;
        }
        return rozmiar;
    }