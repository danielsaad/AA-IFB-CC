/**
Autor: Daniel Saad Nogueira Nunes
Nome do Problema:
ID do Problema: 
url do Problema: 
Técnica:
Complexidade:
Comentários:
**/

#include <iostream>
#include <vector>
using namespace std;

void backtrack_helper(const vector<int>& v,vector<bool>& b,int i){
	if(i==v.size()){
		cout << "Subconjunto: ";
		for(int j=0;j<b.size();j++){
			if(b[j]==true){
				cout << v[j] << " ";
			}
		}
		cout << endl;
	}
	else{
		b[i] = true;
		backtrack_helper(v,b,i+1);
		b[i] = false;
		backtrack_helper(v,b,i+1);
	}
}

void backtrack(const vector<int>& v){
	vector<bool> b(v.size(),false);
	backtrack_helper(v,b,0);
}



int main(){
	std::ios::sync_with_stdio(false);
	vector<int>	v = {1,2,3,4,5,6,7,8,9,10};
	backtrack(v);//gera todos os subconjuntos
	return 0;
}