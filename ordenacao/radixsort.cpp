#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

int get_max(const vector<int>& v){
    int m  = numeric_limits<int>::min();
    for(int i=0;i<v.size();i++){
        m = max(m,v[i]);
    }
    return m;
}
void countingsort(vector<int>& v, int exp){
    vector<int> v2(v); //cria uma cópia de v
    vector<int> vc(10,0);
    for(int i=0;i<v2.size();i++){
        vc[(v2[i]/exp)%10]++;
    }

    for(int i=1;i<vc.size();i++){
        vc[i]+=vc[i-1];
    }
    for(int i=v.size()-1;i>=0;i--){
        v[--vc[(v2[i]/exp)%10]] = v2[i];
    }
}

void radixsort(vector<int>& v){
    int m = get_max(v);
    for(int exp=1;m/exp>0;exp*=10){
        countingsort(v,exp);
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
    cout << "\nRadixsort!\n";
    radixsort(v);
    cout << "Imprimindo vetor depois da ordenação.\n";
    for(int i=0;i<n;i++){
        cout << "v[" << i << "] = " << v[i] << "\n";
    }
    return 0;
}
