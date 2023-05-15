#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> c;

class evento{
public:
    int s,f;
    evento(int s,int f){
        this->s = s;
        this->f = f;
    }
    bool operator<(evento& other) const {
        return(f<other.f);
    }
};


bool checa(vector<bool>& c,vector<evento>& e,int k){
    for(int i=0;i<e.size();i++){
        if(c[i]){
            if(e[k].s < e[i].f ||
                e[k].f > e[i].s){
                    return false;
                }
        }
    }
    return true;
}



int t(vector<evento>& e,int i,int j){
    if(i>j){
        return 0;
    }
    int m = 0;
    for(int k=i;k<=j;k++){
        c[k] = true;
        if(checa(c,e,k)){
            m = max(m,t(e,i,k-1)+1+t(e,k+1,j));
        }
        c[k] = false;
    }
    return m;
}


int main(){
    vector<evento> e;
    e.push_back(evento(0,6));
    e.push_back(evento(5,7));
    e.push_back(evento(2,14));
    e.push_back(evento(1,4));
    e.push_back(evento(3,9));
    e.push_back(evento(6,10));
    e.push_back(evento(12,16));
    e.push_back(evento(8,11));
    e.push_back(evento(3,5));
    e.push_back(evento(5,9));
    e.push_back(evento(8,12));

    c = vector<bool>(e.size(),false);
    sort(e.begin(),e.end());
    cout << t(e,0,e.size()-1) << endl;
}
