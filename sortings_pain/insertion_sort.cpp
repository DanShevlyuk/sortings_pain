#include "insertion_sort.h"


void InsertionSort::insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int b = a[i];
        int j;
        
        for (j = i - 1; b < a[j] && j >= 0; j--) {
            a[j + 1] = a[j];
        }
        
        a[j + 1] = b;
    }
}

void InsertionSort::binary_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int lf = 0, rg = i - 1;
        int c = count_center(lf, rg);
        
        while (lf != c) {
            if (a[c] > a[i]) {
                rg = c - 1;
            } else {
                lf = c;
            }
            
            c = count_center(lf, rg);
        }
        
        if (a[i] > a[rg]) {
            lf = rg + 1;
        } else {
            lf = rg;
        }
        
        int p = a[i];
        
        for (int k = i; k > lf; k--) {
            a[k] = a[k - 1];
        }
        
        a[lf] = p;
    }
}


// count center between two indexes
int InsertionSort::count_center(int lf, int rg) {
    if ((lf + rg) % 2 == 0)
        return (lf + rg) / 2;
    else
        return (lf + rg) / 2 + 1;
}