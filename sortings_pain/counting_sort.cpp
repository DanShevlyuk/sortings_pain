#include "counting_sort.h"

void CountingSort::counting_sort(int a[], int n) {
    
    int k = max(a, n); //value of maximum array element
    int *b = new int[n]; //
    int *c = new int[k + 1];
    
    for (int i = 0; i <= k; i++) {
        c[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        c[a[i]]++;
    }
    
    for (int j = 1; j <= k; j++) {
        c[j] += c[j - 1];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
    
    memcpy(a, b, sizeof(int) * n);
    
    //clean up
    delete [] b;
    delete [] c;
}

void CountingSort::radix_sort256(int a[], int n) {
    union UN {
        unsigned int int_numb;
        unsigned char char_numb[4];
    };
    
    int radix = 256;
    UN *numbers = new UN[n];
    int *c = new int[radix];
    
    for (int i = 0; i < 4 ; i++) {
        memcpy(numbers, a, n * sizeof(int));
        
        for (int j = 0; j < radix; j++) {
            c[j] = 0;
        }
        
        for(int j = 0; j < n; j++) {
            c[numbers[j].char_numb[i]]++;
        }
        
        for (int j = 1; j < radix; j++) {
            c[j] = c[j] + c[j - 1];
        }
        
        for (int j = n - 1; j >= 0; j--) {
            a[c[numbers[j].char_numb[i]] - 1] = numbers[j].int_numb;
            c[numbers[j].char_numb[i]]--;
        }
    }
    
    //clean up
    delete [] numbers;
    delete [] c;
}


int CountingSort::max(int a[], int n) {
    int max = 0;
    
    for (int i = 0; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    
    return max;
}
