#ifndef KOPIEC_H
#define KOPIEC_H

struct Element {
    int wartosc;
    int priorytet;
};

class Kopiec {
private:
    Element* heap;
    int size;
    int capacity;
    void resize();

public:
    Kopiec();
    ~Kopiec();
    void insert(int wartosc, int priorytet);
    Element extractMax();
    Element findMax() const;
    void modifyKey(int wartosc, int newPriorytet);
    int returnSize() const;
    void clear();
    bool empty() const;
};

#endif