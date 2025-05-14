#ifndef kopiec_h
#define kopiec_h
#include <vector>
using namespace std;

struct Element {
    int wartosc;
    int priorytet;
};

class Kopiec {
private:
    vector<Element> heap;

public:
    Kopiec();
    void insert(int wartosc, int priorytet);    
    Element extractMax();                    
    Element findMax() const;                  
    void modifyKey(int wartosc, int nowyPriorytet);
    int returnSize() const;         
    void clear();
    bool empty() const;                       
};

#endif