#include "kopiec.h"
#include <stdexcept>
#include <iostream>
using namespace std;
Kopiec::Kopiec() {}

bool Kopiec::empty() const {
    return heap.empty();
}
void Kopiec::clear() {
    heap.clear();
}
int Kopiec::returnSize() const {
    return heap.size();
}
void Kopiec::insert(int wartosc, int priorytet) {
    Element newElement = {wartosc, priorytet};
    heap.push_back(newElement);
    int index = heap.size() - 1;

    // Bubble Up
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index].priorytet > heap[parent].priorytet) {
            std::swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
    
}

Element Kopiec::extractMax() {
    if (heap.empty()) {
        throw std::runtime_error("Kopiec jest pusty!");
    }

    Element maxElement = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    int index = 0;
    int size = heap.size();

    // Bubble Down
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && heap[left].priorytet > heap[largest].priorytet) {
            largest = left;
        }
        if (right < size && heap[right].priorytet > heap[largest].priorytet) {
            largest = right;
        }

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
    return maxElement;
}
Element Kopiec::findMax() const {
    return heap[0];
}

void Kopiec::modifyKey(int index, int newpriorytet) {

    if (index < 0 || index >= heap.size()) {
        throw invalid_argument("Element not found");
    }

    int oldpriorytet = heap[index].priorytet;
    heap[index].priorytet = newpriorytet;

    if (newpriorytet > oldpriorytet) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index].priorytet > heap[parent].priorytet) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    else if (newpriorytet < oldpriorytet) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left].priorytet > heap[largest].priorytet) {
                largest = left;
            }
            if (right < size && heap[right].priorytet > heap[largest].priorytet) {
                largest = right;
            }

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }
}
