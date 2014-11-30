#include "merge_sort.h"


// sort an array using merge method
void MergeSort::merge_sort(int a[], int n) {
    divide_and_merge(a, 0, n - 1);
}

void MergeSort::divide_and_merge(int* arr, int from, int to) {
    if (from < to) {
        int m = from + (to - from) / 2;
        divide_and_merge(arr, from, m);
        divide_and_merge(arr, m + 1, to);
        merge(arr, from, to);
    }
}

// merge two parts of array
void MergeSort::merge(int* arr, int from, int to) {
    int* b = new int[to + 1];
    
    for (int i = from; i <= to; i++) {
        b[i] = arr[i];
    }
    
    int m = from + (to - from) / 2;
    int p1 = from;
    int p2 = m + 1;
    
    for (int k = from; k <= to; k++) {
        if ((p1 > m) || (p2 > to)) {
            if (p1 > m) {
                arr[k] = b[p2];
                p2++;
            } else {
                arr[k] = b[p1];
                p1++;
            }
        } else {
            if (b[p1] > b[p2]) {
                arr[k] = b[p2];
                p2++;
            } else {
                arr[k] = b[p1];
                p1++;
            }
        }
    }
    
    delete[] b;
}