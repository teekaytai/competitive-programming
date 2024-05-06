#include "heap.h"
#include <bits/stdc++.h>

using namespace std;

vector<int> heap(1);

void sink() {
    int curr = 0;
    while (true) {
        int l = 2 * curr;
        int r = 2 * curr + 1;
        if (l >= heap.size()) break;
        if (r >= heap.size()) {
            if (heap[curr] > heap[l]) break;
            swap(heap[curr], heap[l]);
            curr = l;
        } else {
            int m = heap[l] > heap[r] ? l : r;
            if (heap[curr] > heap[m]) break;
            swap(heap[curr], heap[m]);
            curr = m;
        }
    }
}

void swim() {
    int curr = heap.size() - 1;
    while (curr > 1) {
        int p = curr / 2;
        if (heap[p] >= heap[curr]) break;
        swap(heap[p], heap[curr]);
        curr = p;
    }
}

int getMax() {
    return heap[1];
}

int getSize() {
    return heap.size() - 1;
}

void insert(int element) {
    heap.push_back(element);
    swim();
}

void removeMax() {
    heap[0] = heap.back();
    heap.pop_back();
    if (heap.size() > 1) sink();
}
