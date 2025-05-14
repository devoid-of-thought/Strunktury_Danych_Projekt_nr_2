#include "kopiec.h"
#include <iostream>
using namespace std;

Kopiec::Kopiec() : heap(nullptr), size(0), capacity(0) {}

Kopiec::~Kopiec() {
    delete[] heap;
}

bool Kopiec::empty() const {
    return size == 0;
}

void Kopiec::clear() {
    delete[] heap;
    heap = nullptr;
    size = 0;
    capacity = 0;
}

int Kopiec::returnSize() const {
    return size;
}

void Kopiec::resize() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    Element* newHeap = new Element[capacity];
    for (int i = 0; i < size; ++i) {
        newHeap[i] = heap[i];
    }
    delete[] heap;
    heap = newHeap;
}

void Kopiec::insert(int wartosc, int priorytet) {
    if (size == capacity)
    {
        resize();
    }
    Element newElement = {wartosc, priorytet};
    heap[size] = newElement;
    int index = size;
    size++;

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

Element Kopiec::extractMax() {
    Element maxElement = heap[0];
    heap[0] = heap[size - 1];
    size--;

    int index = 0;
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < size && heap[left].priorytet > heap[largest].priorytet) largest = left;
        if (right < size && heap[right].priorytet > heap[largest].priorytet) largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
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

void Kopiec::modifyKey(int wartosc, int newpriorytet) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (heap[i].wartosc == wartosc) {
            index = i;
            break;
        }
    }
    if (index == -1) return;

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
    } else if (newpriorytet < oldpriorytet) {
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left].priorytet > heap[largest].priorytet) largest = left;
            if (right < size && heap[right].priorytet > heap[largest].priorytet) largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }
}