# include <iostream>
using namespace std;
int main(){
static const int N = 10;
int arr[N] = {23, 5433, 23, 4, 5, 923, 0, -12, -238, 2};
cout << &arr[1] << "  " << &arr[2] << "   " << &arr[3];
int flag = 1;
int a = 0;
while (flag){
    flag = 0;
    for ( int i = 0; i < N-1; i++){
        if(arr[i] > arr[i+1]){
            a = arr[i+1];
            int* pos1 = &arr[i];
            arr[i+1] = *pos1;
            //arr[i+1] = arr[i]
            arr[i] = a;
            flag = 1;

        }

    }

}
for ( int i = 0; i < N-1; i++){
cout << arr[i] << "  ";
}
cout << '\n';
return 0;
};