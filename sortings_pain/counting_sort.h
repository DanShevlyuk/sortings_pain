#include <iostream>
#include <math.h>

using namespace std;


class CountingSort {
    
public:
    static void counting_sort(int a[], int n);
    static void radix_sort256(int a[], int n);
    
private:
    static int max(int a[], int n);

};