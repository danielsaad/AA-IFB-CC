#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int busca_binaria(const vector<int>& v,int chave){
    int l = 0;
    int r = v.size()-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(chave < v[mid]){
            r = mid -1;
        }
        else if(chave > v[mid]){
            l = mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

void testa_busca(const vector<int>& v,int chave){
    int pos = busca_binaria(v,chave);
    if(pos!=-1){
        cout << "Chave ocorre na posicao " << pos << endl;
    }
    else{
        cout << "Chave não encontrada\n";
    }
}

int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(13);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(10);
    v.push_back(11);
    sort(v.begin(),v.end());
    testa_busca(v,0);
    testa_busca(v,2);
    testa_busca(v,7);
    testa_busca(v,4);
    testa_busca(v,99);
    testa_busca(v,10);
    testa_busca(v,14);
    return 0;
}
