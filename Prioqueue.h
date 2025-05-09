//
// Created by userbrigh on 5/9/25.
//

#ifndef PRIOQUEUE_H
#define PRIOQUEUE;_H
struct element {
    int wartość;
    int priorytet;
    int value;
    element* NastepnyWezel;
    element(int val, int prio) : wartość(val),priorytet(prio), NastepnyWezel(nullptr) {}
};
class Kolejka{
public:
    Kolejka();
    ~Kolejka();
    void insert(int warto, int prio);
    void excractMax();
    void findMax();
    void modifyKey(int element, int priority);
    void Wyswietl();
    int returnSize();
private:
    element* head;
    element* tail;
    int rozmiar;

};
#endif //PRIOQUEUE_H
