#include <iostream>
#include <ctime>
#include <map>
#include <time.h>

using namespace std;

typedef void (*sort_func)(int *, int);
typedef void (*array_type)(int *, int);

class Test {
public:
    static map<std::string, array_type> array_types;
    static void test_sort_method(int a[], int n, sort_func sort, unsigned long &mean, unsigned long &max);
    
private:
    
    static unsigned long sort_and_count(int a[], int n, sort_func sort);
    static void array_generation(int a[], int n, int min, int max);
    static void generate_from_0_to_7(int a[], int n);
    static void generate_from_0_to_maxInt(int a[], int n);
    static void generate_sorted_from_0_to_8000(int a[], int n);
    static void almost_sorted(int a[], int n);
    static void reverse_sorted(int a[], int n);
};
