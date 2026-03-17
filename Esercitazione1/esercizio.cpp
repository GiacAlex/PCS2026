#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, const char *argv[])
{if (argc == 2){
        string filename = argv[1];
        ifstream ifs(filename);
        if (ifs.is_open()){
            while (!ifs.eof()) {
            string city;
            double temp1, temp2, temp3, temp4;
            ifs >> city >> temp1 >> temp2 >>temp3>> temp4;
            double media = (temp1 + temp2 + temp3+ temp4)/4; 
            cout << city << "   " << media << '\n';
            } 
        }
        else{
            cerr << "File non trovato" <<'\n';
        }   
    }
    else{
        cerr << "Troppi o non abbastanza argomenti\n" ;
    }
    return 0;
}
