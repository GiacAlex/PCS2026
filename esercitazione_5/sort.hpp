#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

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
void insertionsort(std::vector<T>& vec){
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
void selectionsort(std::vector<T>& vec){
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
void merge(std::vector<T>& vec, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    std::vector<T> L(n1+1);
    std::vector<T> R(n2+1);
    for(int i = 0; i< n1; i++){
        L[i] = vec[p+i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = vec[q+j+1];
    }
    

    int i = 0;
    int j = 0;
    for(int k= p; k <= r; k++){
        if(j == n2){
            vec[k] = L[i];
            i++;
        }
        else{if (i ==n1){
            vec[k] = R[j];
            j++;
        } else{if(L[i] <= R[j]){
            vec[k] = L[i];
            i++;
        }
        else{
            vec[k] = R[j];
            j++;
        }}}
        
    }
}



template<typename T>
void mergesort(std::vector<T>& vec, int p, int r){
    if(p < r){
        int q = ((p+r)/2);
        mergesort(vec, p, q);
        mergesort(vec,q+1, r);
        merge(vec,p,q,r);
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



template<typename T>
int partition(std::vector<T>& vec, int p, int r){
    T x = vec[r]; //prendo l'utimo elemento del vettore come pivot
    int i = p-1;
    for(int j = p; j <= r-1; j++){
        if (vec[j] <= x){
            i++;
            std::swap(vec[i], vec[j]); //dopo questo, i punta all'ultimo elemento ordinato
            //i+1 rappresenta il posto dove metto un nuovo elemento ordinato se lo trovo
        }
    }
    std::swap(vec[i+1], vec[r]);
    return i+1;

}




template<typename T>
void quicksort(std::vector<T>& vec, int p, int r){
    int n = vec.size();
    if (n <= 55){
        insertionsort(vec);
    }
    else{
    if(p<r){
        int q = partition(vec, p, r); //q rappresenta la posiizone in cui ho messo il pivot
        quicksort(vec, p, q-1); //per come è definita partition prendo l'ultimo come pivot
        quicksort(vec, q+1, r);
        }
    }

}
