#include "sort.hpp"
#include "randfiller.hpp"
#include "timecounter.h"
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void
print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << ", ";
    }
    std::cout << "\n";
}

int main(){
    std::vector<double> bubble_t(12), insert_t(12), select_t(12), normale_t(12);
    int len = 2;
    for(int i = 0; i <= 11; i++){  
        timecounter tc;
        randfiller rf;
        len *= 2;
        std::vector<int> v;
        
        v.resize(len);
        rf.fill(v, -1000,1000);
        std::vector<int> v1 = v;
        std::vector<int> v2 = v;
        std::vector<int> v3 = v;
        std::vector<int> v4 = v;
        

        tc.tic();
        bubblesort(v1);
        double tbubble = tc.toc();
        bubble_t[i] = tbubble;

        tc.tic();
        insertionsort(v2);
        double tinsert = tc.toc();
        insert_t[i] = tinsert;


        tc.tic();
        selectionsort(v3);
        double tselect = tc.toc();
        select_t[i] = tselect;


        tc.tic();
        std::sort(v4.begin(), v4.end());
        double tempo = tc.toc();
        normale_t[i] = tempo;
       
        
    }
    std::cout<< "BubbleSort = [";
    print_vector(bubble_t);

    std::cout<< "InsertionSort= [ ";
    print_vector(insert_t);

    std::cout<< "SelectionSort = [ ";
    print_vector(select_t);

    std::cout<< "std::Sort = [";
    print_vector(normale_t);
}