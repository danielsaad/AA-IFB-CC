#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

void insertionsort(vector<int>& v){
    for(unsigned int i=1;i<v.size();i++){
        int chave = v[i];
        int j=i-1;
        for( ;j>=0 && v[j]>chave;j--){
            v[j+1] = v[j];
        }
        v[j+1] = chave;
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
    cout << "\nInsertionsort!\n";
    insertionsort(v);
    cout << "Imprimindo vetor depois da ordenação.\n";
    for(int i=0;i<n;i++){
        cout << "v[" << i << "] = " << v[i] << "\n";
    }
    return 0;
}
