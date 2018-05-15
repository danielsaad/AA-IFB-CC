#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& A,int l,int r){
    for(int i=l;i<=r;i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int kth_smallest(vector<int>& X, vector<int>& Y, int l_x,int r_x,int l_y,int r_y,int k){
    // print(X,l_x,r_x);
    // print(Y,l_y,r_y);
    if(l_x>r_x)
        return Y[l_y+k-1];
    if(l_y>r_y)  
        return X[l_x+k-1];

    int mid_x = (l_x+r_x)/2;
    int mid_y = (l_y+r_y)/2;
    int n_x = mid_x - l_x +1;
    int n_y = mid_y - l_y + 1;
    if(n_x+n_y > k){
        if(X[mid_x] > Y[mid_y])
            return kth_smallest(X,Y,l_x,mid_x-1,l_y,r_y,k);
        else
            return kth_smallest(X,Y,l_x,r_x,l_y,mid_y-1,k);
    }
    else{
        if(X[mid_x]>Y[mid_y])
            return kth_smallest(X,Y,l_x,r_x,mid_y+1,r_y,k-n_y);
        else
            return kth_smallest(X,Y,mid_x+1,r_x,l_y,r_y,k-n_x);
    }   
}

int main(){
    vector<int> X= {1,2,5,8,12,13};
    vector<int> Y= {3,4,7,9,10,11};
    int k;
    cout << "Digite o valor de k (entre 1 e " << X.size() + Y.size() << "): ";
    cin >> k;
    int res = kth_smallest(X,Y,0,X.size()-1,0,Y.size()-1,k);
    cout << "O k-esimo menor elemento corresponde a: " << res << endl;
    return 0;
}