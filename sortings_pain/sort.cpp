#include "sort.h"

map<std::string, sort_func> Sort::sortings = {
    {"BubbleSort", BubbleSort::bubble_sort,},
    {"Iverson1", BubbleSort::iverson_1_sort},
    {"Iverson2", BubbleSort::iverson_2_sort},
    {"InsertionSort", InsertionSort::insertion_sort},
    {"BinarySort", InsertionSort::binary_sort},
    {"CountingSort", CountingSort::counting_sort},
    {"Counting256", CountingSort::radix_sort256},
    {"MergeSort", MergeSort::merge_sort},
    {"HeapSort", HeapSort::heap_sort},
    {"QuickSortMiddle", QuickSort::quicksort_middle},
    {"QuickSortLast", QuickSort::quicksort_last},
    {"ShellSort", ShellSort::shell_sort},
};






