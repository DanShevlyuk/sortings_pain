#include <iostream>
#include <map>

//sort methods
#include "insertion_sort.h"
#include "counting_sort.h"
#include "merge_sort.h"
#include "bubble.h"
#include "q_sort.h"
#include "shell_sort.h"
#include "heap_sort.h"


using namespace std;

typedef void (*sort_func)(int *, int);

// sort class aggregate all aveliable sorting methods
class Sort {
public:
    static map<std::string, sort_func> sortings;
    
    
};