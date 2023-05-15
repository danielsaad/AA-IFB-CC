#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;




int partition(vector<int>& v,int l,int r){
    int k = l; //marca o fim da primeira partição
    int i = l; //elemento a ser analizado
    int pivo = r; //pivo é o elemento do final
    while(i<r){
        if(v[i]<=v[pivo]){
            swap(v[k],v[i]);
            k++;
        }
        i++;
    }
    swap(v[k],v[pivo]); //colocamos o pivo na posição correta
    return k; //retornamos a posição do pivo
}

void recursive_quicksort(vector<int>& v,int l,int r){
    if(l<r){
        int p = partition(v,l,r);
        recursive_quicksort(v,l,p-1);
        recursive_quicksort(v,p+1,r);
    }
}


void quicksort(vector<int>& v){
    recursive_quicksort(v,0,v.size()-1);
}


int main(){
    const int min = 0;
    const int max = 1000;
    const int n = 1000;
    std::ios::sync_with_stdio(false);
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased
    vector<int> v(1000);
    for(int i=0;i<n;i++){
        v[i] = uni(rng);
    }
    cout << "Imprimindo vetor antes da ordenação.\n";
    for(int i=0;i<n;i++){
        cout << "v[" << i << "] = " << v[i] << "\n";
    }
    cout << "\nQuicksort!\n";
    quicksort(v);
    cout << "Imprimindo vetor depois da ordenação.\n";
    for(int i=0;i<n;i++){
        cout << "v[" << i << "] = " << v[i] << "\n";
    }
    return 0;
}
