#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

void bubblesort(vector<int>& v){
    bool trocou = true;
    for(unsigned int i=0;i<v.size() && trocou;i++){
        trocou = false;
        for(unsigned int j=0;j<v.size()-1;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                trocou = true;
            }
        }
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
    cout << "\nBubblesort!\n";
    bubblesort(v);
    cout << "Imprimindo vetor depois da ordenação.\n";
    for(int i=0;i<n;i++){
        cout << "v[" << i << "] = " << v[i] << "\n";
    }
    return 0;
}
