//
// Daniil Shevlyuk, 201pi
// 09.11.2014
//
#include "q_sort.h"

// Quicksort with middle element in array as pivot
void QuickSort::quicksort_middle(int* arr, int n) {
    recursive_call_qsort(arr, 0, n - 1, &get_middle_pivot);
}

// Quicksort with last element in array as pivot
void QuickSort::quicksort_last(int* arr, int n) {
    recursive_call_qsort(arr, 0, n - 1, &get_last_pivot);
}

// Getting position of middle pivot in array in the current bounds
//
// Additional space: O(1)
// Complexity: O(1)
int QuickSort::get_middle_pivot(int from, int to) {
    return (from + to) / 2;
}

// Getting position of last pivot in array in the current bounds
//
// Additional space: O(1)
// Complexity: O(1)
int QuickSort::get_last_pivot(int from, int to) {
    return to;
}

// Rearranges values in the array using pivot in the current bounds
//
// Additional space: O(1)
// Complexity: O(n)
// RETURNS: new position of the pivot in the array.
int QuickSort::recompute_with_pivot(int* arr, int from, int to, int pivot_pos) {
    std::swap(arr[from], arr[pivot_pos]);
    pivot_pos = arr[from];
    
    int lo = from + 1, hi = to;
    
    while (lo <= hi) {
        while (arr[hi] > pivot_pos) {
            hi--;
        }
        while (lo <= hi && arr[lo] <= pivot_pos) {
            lo++;
        }
        if (lo <= hi) {
            swap(arr[lo], arr[hi]);
            lo ++;
            hi --;
        }
    }
    swap(arr[from], arr[hi]);
    
    return hi;
}

// Recursive call for qsort that sorts the array
// in the current bounds
//
// Additional space: O(1)
// Complexity: O(n*log(n)) - average. O(n*n) - the worst case.
void QuickSort::recursive_call_qsort(int* arr, int from, int to, pivot_chooser pivot_chooser) {
    if (from < to) {
        int q = recompute_with_pivot(arr, from, to, pivot_chooser(from, to));
        recursive_call_qsort(arr, from, q - 1, pivot_chooser);
        recursive_call_qsort(arr, q + 1, to, pivot_chooser);
    }
}
