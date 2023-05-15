#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>& v,vector<int>& v1,vector<int>& v2){
    unsigned int i,j,k;
    i = j = k = 0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i]<=v2[j]){
            v[k++] = v1[i++];
        }
        else{
            v[k++] = v2[j++];
        }
    }
    while(i<v1.size()){
        v[k++] = v1[i++];
    }
    while(j<v2.size()){
        v[k++] = v2[j++];
    }
}

vector<int> mergesort(vector<int>& v){
    if(v.size()<=1){
        return v;
    }
    std::vector<int>::iterator middle = v.begin() + (v.size() / 2);
    vector<int> v1(v.begin(), middle);
    vector<int> v2(middle, v.end());
    v1 = mergesort(v1);
    v2 = mergesort(v2);
    merge(v,v1,v2);
    return v;
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
    cout << "\nMergesort!\n";
    vector<int> vs = mergesort(v);
    v.clear();
    cout << "Imprimindo vetor depois da ordenação.\n";
    for(int i=0;i<n;i++){
        cout << "v[" << i << "] = " << vs[i] << "\n";
    }
    return 0;
}
