class MergeSort {
    
public:
    static void merge_sort(int a[], int n);
private:
    static void divide_and_merge(int* arr, int from, int to);
    static void merge(int* arr, int from, int to);
    
};
