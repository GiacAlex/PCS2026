#include "sort.hpp"
#include "randfiller.hpp"
#include "timecounter.hpp"
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
    int L = 300;
    std::vector<double> bubble_t(L), insert_t(L), select_t(L), normale_t(L), merge_t(L), quick_t(L);
    int len = 2;
    int test = 100;
    int flag1 = 0;
    int flag2 = 0;
    for(int i = 0; i < L; i++){  
        timecounter tc;
        randfiller rf;
        /*len *= 2;*/
        len++;
        std::vector<std::vector<int>> v(test);
        for(int k = 0; k < test; k++){
            v[k].resize(len);
            rf.fill(v[k], -1000,1000);
        }
    
        

        std::vector<std::vector<int>> vec1 = v;
        tc.tic();
        for(int j = 0; j <test; j++){    
            bubblesort(vec1[j]);
        }
        double tbubble = tc.toc();
        bubble_t[i] = tbubble/test;

        std::vector<std::vector<int>> vec2 = v;
        tc.tic();
        for(int j = 0; j <test; j++){
            selectionsort(vec2[j]);
            
        }
        double tselect = tc.toc();
        select_t[i] = tselect/test;
        
        std::vector<std::vector<int>> vec3 = v;
        tc.tic();
        for(int j = 0; j <test; j++){
            insertionsort(vec3[j]);
            
        }
        double tinsert = tc.toc();
        insert_t[i] = tinsert/test;
        
        
        std::vector<std::vector<int>> vec4 = v;
        tc.tic();
        for(int j = 0; j < test; j++){
            std::sort(vec4[j].begin(), vec4[j].end());
        }
        
        double tempo = tc.toc();
        normale_t[i] = tempo/test;

        std::vector<std::vector<int>> vec5 = v;
        tc.tic();
        for(int j = 0; j <test; j++){
            mergesort(vec5[j], 0, vec5[j].size()-1);
        }
        
        double tmerge = tc.toc();
        merge_t[i] = tmerge/test;
    

        std::vector<std::vector<int>> vec6 = v;
        tc.tic();
        for(int j = 0; j <test; j++){
            quicksort(vec6[j], 0, vec6[j].size()-1);
            
        }
        double tquick = tc.toc();
        quick_t[i] = tquick/test;
        
    }





    std::cout<< "BubbleSort = [";
    print_vector(bubble_t);
    
    std::cout<< "InsertionSort= [ ";
    print_vector(insert_t);
    
    std::cout<< "SelectionSort = [ ";
    print_vector(select_t);
    

    std::cout<< "Sort = [";
    print_vector(normale_t);

    std::cout<< "MergeSort = [ ";
    print_vector(merge_t);
    
    std::cout<< "QuickSort = [";
    print_vector(quick_t);


}




