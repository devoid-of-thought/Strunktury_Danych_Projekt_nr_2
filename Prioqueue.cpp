#include <iostream>
#include "Prioqueue.h"
using namespace std;
//konstruktor kolejki inicjalizacja head tail i rozmiaru
Kolejka::Kolejka(): head(nullptr), tail(nullptr), rozmiar(0) {}
//dekonstruktor kolejki
Kolejka::~Kolejka() {
    element* wezel = head;
    while (wezel != nullptr) {
        element* NastepnyWezel = wezel->NastepnyWezel;
        delete wezel;
        wezel = NastepnyWezel;
    }
    head = nullptr;
    tail = nullptr;
}
//wstawienie do kolejki
void Kolejka::insert(int warto, int prio) {
    //tworzenie nowego elementu
    element* nowy_element = new element(warto, prio);
    //jeżeli kolejka jest pusta lub nowy element ma wyższy priorytet
    if (head == nullptr || head->priorytet <prio) {
        //nowy element staje się head, a kolejkę przesuwamy
        nowy_element->NastepnyWezel = head;
        head=nowy_element;
        if (tail== nullptr) tail = nowy_element;
    } else {
        //jeżeli kolejka nie jest pusta
        // ustawiamy wskaźnik na head i przeszukujemy kolejkę dopółki nie znajdziemy taila lub elementu o mniejszym
        element* obecny = head;
        while (obecny->NastepnyWezel != nullptr && obecny->NastepnyWezel->priorytet >= prio) {
            obecny = obecny->NastepnyWezel;
        }
        //wstawienie elementu do kolejki
        nowy_element->NastepnyWezel = obecny->NastepnyWezel;
        obecny ->NastepnyWezel = nowy_element;
        if (tail== nullptr) tail = nowy_element;
    }
    //zwiększenie rozmiaru
    rozmiar++;
}

void Kolejka::extractMax() {
    //flaga czy kolejka jest pusta
    if (head == nullptr) {
        cout <<"Brak elementów w kolejce" << endl;
        return;
    }
    //jeżeli kolejka nie jest pusta
    //przesuwamy kolejkę o jeden i usuwamy pierwszy element
    element* pierwszy_element = head;
    head = head->NastepnyWezel;
    //zmniejszamy rozmiar kolejki
    rozmiar--;
    delete pierwszy_element;
    //jeżeli kolejka jest pusta to ustawiamy tail na nullptr
    if (head == nullptr) {
        tail = nullptr;
    }
}
void Kolejka::findMax() {
    if (head == nullptr) {
        cout <<"Brak elementów w kolejce" << endl;
        return;
    }
    //jeżeli kolejka nie jest pusta
    //wyświetlamy wartość heada
    cout << "Max element: (Priorytet: " << head->priorytet<< ", Wartość: "<< head->wartość << ")" << endl;
}

void Kolejka::modifyKey(int nr_ele, int priority) {
    //flaga czy kolejka nie jest pusta
    if (head == nullptr) {
        cout <<"Brak elementów w kolejce" << endl;
        return;
    }
    //flaga czy zadany indeks jest poprawny
    if ( nr_ele >= rozmiar) {
        cout << "Nieprawidłowy indeks" << endl;
        return;
    }
    //jeżeli kolejka nie jest pusta
    // szukamy węzła o danym indeksie
    element* wezel = head;
    element* poprzedni = nullptr;
    for (int i = 0; i < nr_ele;i++) {
        poprzedni = wezel;
        wezel = wezel->NastepnyWezel;
    }
    //przechowujemy wartość węzła
    int przechowaj = wezel->wartość;
    //jeżeli kolejka ma tylko head usuwamy go
    if (rozmiar==1) {
        head->priorytet = priority;
    } else {
        //przesuwamy kolejkę
        poprzedni->NastepnyWezel = wezel->NastepnyWezel;
        if (wezel == tail) tail = poprzedni;
    }
    //usuwamy węzeł
    delete wezel;
    rozmiar--;
    //wstawiamy ponownie element
    insert(przechowaj, priority);
}
void Kolejka::Wyswietl() {
    //flaga na to czy kolejka jest pusta
    if (head == nullptr) {
        cout <<"Brak elementów w kolejce" << endl;
        return;
    }
    //jeżeli kolejka nie jest pusta
    //ustawiamy wskaźnik na head i przeszukujemy kolejkę wyświetlając element po elemencie
    element* wezel = head;
    while (wezel != nullptr) {
        cout << "(Priorytet: " << wezel->priorytet<< ", Wartość: "<< wezel->wartość << ") " ;
        wezel = wezel->NastepnyWezel;
    }
    cout <<endl;
}

//wyświetl rozmiar
int Kolejka::returnSize() {
    return rozmiar;
}

