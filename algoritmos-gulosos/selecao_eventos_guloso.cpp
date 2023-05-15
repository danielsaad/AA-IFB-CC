#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
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

    sort(e.begin(),e.end());
    int max = 0;
    int ultimo = 0;
    for(int i=0;i<e.size();i++){
        if(i==0 || e[i].s>=e[ultimo].f){
            ultimo = i;
            max++;
        }
    }
    cout << max << endl;
}
