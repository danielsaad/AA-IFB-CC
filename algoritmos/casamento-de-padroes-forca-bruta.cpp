#include <iostream>

using namespace std;
int main(){
    string p,t;
    cout << "Digite o texto: ";
    getline(cin,t);
    cout << "Digite o padrão: ";
    getline(cin,p);
    for(int i=0;i<t.size()-p.size()+1;i++){
        bool achou = true;
        for(int j=0;j<p.size();j++){
            if(t[i+j]!=p[j]){
                achou = false;
            }
        }
        if(achou){
            cout << "Padrão ocorre na posição " << i << " do texto.\n";
        }
    }
    return 0;
}
