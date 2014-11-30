#include "test_sort_time.h"
#include "q_sort.h"


map<std::string, array_type> Test::array_types = {
    {"generate_from_0_to_7", Test::generate_from_0_to_7,},
    {"generate_from_0_to_maxInt", Test::generate_from_0_to_maxInt},
    {"generate_sorted_from_0_to_8000", Test::generate_sorted_from_0_to_8000},
    {"almost_sorted", Test::almost_sorted},
    {"reverse_sorted", Test::reverse_sorted}
};


void Test::test_sort_method(int a[], int n, sort_func sort, unsigned long &mean, unsigned long &max) {

    unsigned long sum = 0;
    unsigned long time = 0;
    mean = 0;
    max = 0;
    
    int *b = new int[n];
    
    
    int number_of_tests = 50;
    for (int i = 0; i < number_of_tests; i++) {
        memcpy(b, a, n * sizeof(int));
        
        time = sort_and_count(b, n, sort);
        
        sum += time;
        
        if (time > max) {
            max = time;
        }
        
    }
    
    mean = sum / number_of_tests;
}

unsigned long Test::sort_and_count(int a[], int n, sort_func sort) {
    
    unsigned time_edx, time_eax, time_edx1, time_eax1;
    
    asm volatile ("cpuid\n\t"
                  "rdtsc\n\t"
                  "mov %%edx, %0\n\t"
                  "mov %%eax, %1\n\t" : "=r"(time_edx), "=r"(time_eax) ::
                  "%rax", "%rbx", "%rcx", "%rdx");
    
    
    sort(a, n);
    
    asm volatile ("rdtscp\n\t"
                  "mov %%edx, %0\n\t"
                  "mov %%eax, %1\n\t"
                  "cpuid\n\t" : "=r"(time_edx1), "=r"(time_eax1) ::
                  "%rax", "%rbx", "%rcx", "%rdx");
    
    return  ((uint64_t)(time_edx1) << 32 | time_eax1) -
    ((uint64_t)(time_edx)  << 32 | time_eax);
}

int random_number(int min, int max) {
    return min + rand() % (max - min + 1);
}

void random_pair_swap(int a[], int n) {
    int i, k;
    
    i = random_number(0, n - 1);
    k = random_number(0, n - 1);
    
    swap(a[i], a[k]);
}

void swap_some_pairs(int a[], int n, int number_of_pairs) {
    for (int i = 0; i < number_of_pairs; i++) {
        random_pair_swap(a, n);
    }
}

void Test::generate_from_0_to_7(int a[], int n) {
    array_generation(a, n, 0, 7);
}

void Test::generate_from_0_to_maxInt(int a[], int n) {
    array_generation(a, n, 0, std::numeric_limits<int>::max());
}

void Test::generate_sorted_from_0_to_8000(int a[], int n) {
    array_generation(a, n, 0, 8000);
    QuickSort::quicksort_middle(a, n);
}

void Test::almost_sorted(int a[], int n) {
    generate_sorted_from_0_to_8000(a, n);
    swap_some_pairs(a, n, 8);
}

void reverse_insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int b = a[i];
        int j;
        
        for (j = i - 1; b > a[j] && j >= 0; j--) {
            a[j + 1] = a[j];
        }
        
        a[j + 1] = b;
    }
}

void Test::reverse_sorted(int a[], int n) {
    array_generation(a, n, 0, 8000);
    reverse_insertion_sort(a, n);
}

void Test::array_generation(int a[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        a[i] = random_number(min, max);
    }
}


