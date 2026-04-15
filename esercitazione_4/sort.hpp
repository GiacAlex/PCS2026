#pragma once
#include <iostream>
#include <vector>
template<typename T>

void bubblesort(std::vector<T>& vec){
    int len = vec.size();
    for (int i = 0; i< len-1; i++){
        for( int j = len-1; j>i; j--){
            if(vec[j] < vec[j-1]){
                T cambio = vec[j];
                vec[j] = vec[j-1];
                vec[j-1] = cambio;
            }
        }
    }

};
template<typename T>
void selectionsort(std::vector<T>& vec){
    int len = vec.size();
    for (int j = 1; j < len; j++){
        T key = vec[j];
        int i = j-1;
        while (i >= 0 && vec[i] > key){
            vec[i+1] = vec[i];
            i--;
        };
        vec[i+1] = key;
    }
};

template<typename T>
void insertionsort(std::vector<T>& vec){
    int len = vec.size();
    for(int i = 0; i < len -1; i++){
        int min = i;
        for( int j = i+1; j < len; j++){
            if (vec[j] < vec[min]){
                min = j;
            }
        }
        T cambio = vec[i];
        vec[i] = vec[min];
        vec[min] = cambio;
    }

}






template<typename T>
bool issorted(std::vector<T>& vec){
    int len = vec.size();
    for (int i = 0; i<len-1; i++){
        if(vec[i] > vec[i+1]){
            return false;
        }
    }
    return true;
};