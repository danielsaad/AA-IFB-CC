#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

void countingsort(vector<int>& v,int max){
    vector<int> v2(v); //cria uma cópia de v
    vector<int> vc(max+1,0);
    for(int i=0;i<v2.size();i++){
        vc[v2[i]]++;
    }

    for(int i=1;i<vc.size();i++){
        vc[i]+=vc[i-1];
    }
    for(int i=v.size()-1;i>=0;i--){
        v[--vc[v2[i]]] = v2[i];
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
    cout << "\nCountingsort!\n";
    countingsort(v,max);
    cout << "Imprimindo vetor depois da ordenação.\n";
    for(int i=0;i<n;i++){
        cout << "v[" << i << "] = " << v[i] << "\n";
    }
    return 0;
}
