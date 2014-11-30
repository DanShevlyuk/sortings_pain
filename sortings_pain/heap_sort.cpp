#include "heap_sort.h"

int HeapSort::HEAP_SIZE = 0;

void HeapSort::heap_sort(int a[], int n) {
    build_heap(a, n);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        HEAP_SIZE -= 1;
        heapify(a, n, 0);
    }
}

void HeapSort::build_heap(int a[], int n) {
    HEAP_SIZE = n - 1;
    
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
}

void HeapSort::heapify(int a[], int n, int i) {
    int l = left(i);
    int r = right(i);
    int largest = 0;
    
    if (l <= HEAP_SIZE && a[l] > a[i]) {
        largest = l;
    }
    else {
        largest = i;
    }
    
    if (r <= HEAP_SIZE && a[r] > a[largest]) {
        largest = r;
    }
    
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}


//index of left child
int HeapSort::left(int i) {
    return 2 * i + 1;
}

//index of right child
int HeapSort::right(int i) {
    return 2 * i + 2;
}