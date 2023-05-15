#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int>&v, int i,int heapsize){
    int l,r;
    while(i<heapsize){
        l = 2*i+1;
        r = 2*i+2;
        int maior = i;
        if(l<heapsize && v[l]>v[i]){
            maior = l;
        }
        if(r<heapsize && v[r]>v[maior]){
            maior = r;
        }
        if(maior!=i){
            swap(v[i],v[maior]);
            i = maior;
        }
        else{
            break;
        }
    }
}

void makeheap(vector<int>& v){
    for(int i=v.size()/2;i>=0;i--){
        heapify(v,i,v.size());
    }
}


void heapsort(vector<int>& v){
    makeheap(v);
    for(int i=v.size()-1;i>0;i--){
        swap(v[0],v[i]);
        heapify(v,0,i);
    }
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
    cout << "\nHeapsort!\n";
    heapsort(v);
    cout << "Imprimindo vetor depois da ordenação.\n";
    for(int i=0;i<n;i++){
        cout << "v[" << i << "] = " << v[i] << "\n";
    }
    return 0;
}
