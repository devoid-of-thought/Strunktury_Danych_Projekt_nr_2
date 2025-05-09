#ifndef SLL_H
#define SLL_H
//Deklarujemy strukturę, value odpowiada wartości "węzła", Następny Węzeł to wskaźnik do następnego węzła
//Wskaźnik do następnego węzła jest inicjowany jako nullptr, ponieważ nie ma następnego węzła na początku
struct SLLNode {
    int value;
    SLLNode* NastepnyWezel;
    SLLNode(int val) : value(val), NastepnyWezel(nullptr) {}
};
///Struktura jedno kierunkowa lista, head to wskaźnik do pierwszego węzła, tail to wskaźnik do ostatniego węzła
class ListaJednokierunkowa {
private:
    SLLNode* head;
    SLLNode* tail;

public:
    ListaJednokierunkowa();
    ~ListaJednokierunkowa();

    void DodajTail(int val);
    void DodajHead(int val);
    void UsunHead();
    void UsunTail();
    void DodajLosowo(int val, int index);
    void UsunLosowo(int index);
    void Znajdz(int val);
    void Wyswietl();
    int Rozmiar();
};

#endif