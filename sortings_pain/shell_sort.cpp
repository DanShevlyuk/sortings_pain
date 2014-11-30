#include "shell_sort.h"

void ShellSort::shell_sort(int a[], int n) {
    
    int increment;
    int temp;
    int j;
    
    for (increment = n / 2;  increment > 0; increment /= 2) {
        for (int i = increment; i < n; i++) {
            temp = a[i];
            
            for (j = i; j >= increment; j -= increment) {
                if (temp < a[j - increment]) {
                    a[j] = a[j - increment];
                } else {
                    break;
                }
            }
            
            a[j] = temp;
        }
    }
}