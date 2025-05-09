#include <iostream>
#include "Prioqueue.h"
using namespace std;
Kolejka::Kolejka(): head(nullptr), tail(nullptr) {}

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

void Kolejka::insert(int warto, int prio) {
    element* nowy_element = new element(warto, prio);
    if (head == nullptr || head->priorytet <prio) {
        nowy_element->NastepnyWezel = head;
        head=nowy_element;
        if (tail== nullptr) tail = nowy_element;
    } else {
        element* obecny = head;
        while (obecny->NastepnyWezel != nullptr && obecny->NastepnyWezel->priorytet >= prio) {
            obecny = obecny->NastepnyWezel;
        }
        nowy_element->NastepnyWezel = obecny->NastepnyWezel;
        obecny ->NastepnyWezel = nowy_element;
        if (tail== nullptr) tail = nowy_element;
    }
    rozmiar++;
}

void Kolejka::excractMax() {
    if (head == nullptr) {
        cout <<"Brak elementów w kolejce" << endl;
        return;
    }
    element* pierwszy_element = head;
    cout << "Element o największym priorytecie: Wartość: " << pierwszy_element->wartość << " Priorytet: " << pierwszy_element->priorytet << endl;
    head = head->NastepnyWezel;
    rozmiar--;
    delete pierwszy_element;
    if (head == nullptr) {
        tail = nullptr;
    }
}
void Kolejka::findMax() {
    if (head == nullptr) {
        cout <<"Brak elementów w kolejce" << endl;
        return;
    }
}
void Kolejka::modifyKey(int nr_ele, int priority) {
    if (head == nullptr) {
        cout <<"Brak elementów w kolejce" << endl;
        return;
    }
    if ( nr_ele >= rozmiar) {
        cout << "Nieprawidłowy indeks" << endl;
        return;
    }
    element* wezel = head;
    element* poprzedni = nullptr;
    for (int i = 0; i < nr_ele;i++) {
        poprzedni = wezel;
        wezel = wezel->NastepnyWezel;
    }
    int przechowaj = wezel->wartość;
    if (rozmiar==1) {
        head = head->NastepnyWezel;
        if (head == nullptr) tail = nullptr;
    } else {
        poprzedni->NastepnyWezel = wezel->NastepnyWezel;
        if (wezel == tail) tail = poprzedni;
    }

    delete wezel;
    rozmiar--;

    insert(przechowaj, priority);
}
void Kolejka::Wyswietl() {
    if (head == nullptr) {
        cout <<"Brak elementów w kolejce" << endl;
        return;
    }
    element* wezel = head;
    while (wezel != nullptr) {
        cout << "(Priorytet: " << wezel->priorytet<< ", Wartość: "<< wezel->wartość << ") " ;
        wezel = wezel->NastepnyWezel;
    }
    cout <<endl;
}

int Kolejka::returnSize() {
    return rozmiar;
}

