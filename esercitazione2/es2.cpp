# include <iostream>
# include <cmath>
using namespace std;
int main(){
static const int N = 10;
double arr[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
double minimo = arr[0], massimo = arr[0], mean, stdev, somma = 0, var = 0;


for (int i = 1; i <N; i++){
    if (arr[i] < minimo){
        minimo = arr[i];   
    }
    if (arr[i] > massimo){
        massimo = arr[i];
    }
    somma += arr[i];
}
mean = somma/N;
for (int j = 0; j <N; j++){
    var += (arr[j]-mean)*(arr[j]-mean);
}
stdev = std::sqrt(var/(N-1));

cout << "Minimo:  " << minimo << "  Massimo:   " << massimo << '\n';
cout << "Media:  " << mean << '\n';
cout << "Deviazione standard:  "<< stdev << '\n';
return 0;
}

