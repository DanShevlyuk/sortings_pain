
#include <iostream>
#include <ctime>
#include <fstream>
#include "sort.h"
#include "test_sort_time.h"

int main(int argc, const char * argv[]) {
    
    
    srand(time(0));

    int *a;
    
    ofstream outstr;
    outstr.open("result.csv", ios::ate);
    
    typedef map<std::string, sort_func>::iterator sortings_iterator;
    typedef map<std::string, array_type>::iterator types_iterator;

    unsigned long mean, max;
    
    for (sortings_iterator s_iterator = Sort::sortings.begin(); s_iterator != Sort::sortings.end(); ++s_iterator) {
        for (types_iterator t_iterator = Test::array_types.begin(); t_iterator != Test::array_types.end(); ++t_iterator) {
            
            outstr << s_iterator->first << "," << t_iterator->first <<",\n";
            outstr << "size, sort time(clock),"<<"\n";
            outstr << "," << s_iterator->first<<",max" <<"\n";
            
            a = new int[9000];
            t_iterator->second(a, 9000); // generate an array
            
            int *b;
            
            for (int n = 1000; n <= 9000; n += 1000) {
                b = new int[n];
                
                memcpy(b, a, n * sizeof(int));
                
                if (!((s_iterator->first == "CountingSort" || s_iterator->first == "Counting256") &&
                    t_iterator->first == "generate_from_0_to_maxInt")) {
                    
                    Test::test_sort_method(a, n, s_iterator->second, mean, max);
                    outstr << n << ","<< mean << "," << max << "\n";
                    
                } else {
                    outstr << "---\n";

                }
                delete [] b;
                outstr.flush();
            }
            
            outstr << '\n';
        }
        outstr << ",,,\n";
    }
    
    outstr.close();
    
    return 0;
}
