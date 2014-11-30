#include "bubble.h"


void BubbleSort::bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]); // меняем местами
            }
        }
    }
}

void BubbleSort::iverson_1_sort(int a[], int n) {
    bool flag = true; // флаг, который показывает были ли обмены
    
    for (int i = 0; i < (n - 1) && flag; i++) {
        flag = false; // в начале каждого прохода готовимся к тому, что обменов не будет
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]){
                swap(a[j], a[j + 1]); // меняем местами
                flag = true; // обмен был!
            }
        }
    }
}

void BubbleSort::iverson_2_sort(int a[], int n) {
    bool flag = true;
    int t = n - 1;
    int Bound; // верхняя граница прохода внутреннего цикла
    
    for (int i = 0; i < (n - 1) && flag; i++) {
        flag = false;
        Bound = t; // верхняя граница равна индексу последнего обмена
        t = 0;
        for (int j = 0; j < Bound; j++) {
            if (a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                flag = true;
                t = j; // фиксируем индекс обмена
            }
        }
        
        // если обменов не было, то массив уже отсортирован
        if (t == 0) {
            break;
        }
    }
}