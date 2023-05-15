/**
Autor: Daniel Saad Nogueira Nunes
Seleção do k-ésimo em tempo linear.
**/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;


int find_median(vector<int>& v,int l, int size){
    sort(v.begin()+l,v.begin()+l+size);
    return(v[l+(size/2)]);
}

int partition(vector<int>& v,int l,int r,int x){
    int j;
    for(j=l;j<=r;j++){
        if(v[j]==x){
            break;
        }
    }
    swap(v[j],v[r]);
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
    return k-l; //retornamos a posição do pivo
}



int select_k (vector<int>& v,int k,int l,int r){
    
    int n = (r-l+1);
    if(k<0 || k>=n){
        return numeric_limits<int>::max();
    }
    if(n==1){
        return(v[l]);
    }
    vector<int> medianas;
    int i;
    for(i=0;i<n/5;i++){
        int med = find_median(v,l+(i*5),5);
        medianas.push_back(med);
    }
    if(n%5!=0){
        int med = find_median(v,l+(i*5),n%5);
        medianas.push_back(med);
    }

    int med = select_k(medianas,medianas.size()/2,0,medianas.size()-1);
    int kth_pos = partition(v,l,r,med);

    if(kth_pos<k){
        return select_k(v,k-kth_pos-1,l+kth_pos+1,r);
    }
    else if(k<kth_pos){
        return select_k(v,k,l,l+kth_pos-1);
    }
    return v[l+kth_pos];
}

int main(){
    vector<int> v = {5,3,1,7,9,2,0,4,6,8};
    int k;
    cin >> k;
    int kth = select_k(v,k,0,v.size()-1);
    cout << k << "-ésimo menor elemento = " << kth << "\n";
    return 0;
}
