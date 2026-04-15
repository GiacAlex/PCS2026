#include "sort.hpp"
#include "randfiller.hpp"
#include <iostream>
#include <vector>

int main(){
    randfiller rf;
    std::vector<int> dimensioni;
    
    dimensioni.resize(100);
    rf.fill(dimensioni, 1, 1000);
    

    for(int i = 0; i <100; i++){
        int dim = dimensioni[i];
        std::vector<int> v;
        v.resize(dim);
        rf.fill(v, -1000, 1000);
        selectionsort(v);
        bool a = issorted(v);
        if(a == 0){
            return EXIT_FAILURE;
        }
    }
    std::vector<std::string> strvec = {"asduia", "iso","dfsge","trbtcw","123dacsd","jJIROF2NO","PAISP1","1290DWO","ciao","3i902c"};
    bubblesort(strvec);

    return EXIT_SUCCESS;

    }