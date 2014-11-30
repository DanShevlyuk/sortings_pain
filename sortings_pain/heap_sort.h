#include <iostream>

using namespace std;

class HeapSort {
    
public:
    static void heap_sort(int a[], int n);
    
private:
    static int HEAP_SIZE;
    
    static void heapify(int a[], int n, int i);
    static void build_heap(int a[], int n);
    static int right(int i);
    static int left(int i);
};