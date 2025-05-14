#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H
struct element {
    int wartość;
    int priorytet;
    element* NastepnyWezel;
    element(int val, int prio) : wartość(val),priorytet(prio), NastepnyWezel(nullptr) {}
};
class Kolejka{
public:
    Kolejka(const Kolejka& other);
    Kolejka();
    ~Kolejka();
    void insert(int warto, int prio);
    void extractMax();
    void findMax();
    void modifyKey(int element, int priority);
    void Wyswietl();
    int returnSize();
    element* head;
    element* tail;
    int rozmiar;

};
#endif //PRIOQUEUE_H
