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
#include <algorithm>
using namespace std;


int bottom_up_cut_rod(const vector<int>& p, int n){
	vector<int> r(n+1,-1);
	r[0] = 0;
	for(int j=1;j<=n;j++){
		int q = -1;
		for(int k=1;k<=j;k++){
			q = max(q,p[k]+r[j-k]);
		}
		r[j] = q;
	}
	return r[n];
}


int main(){
	std::ios::sync_with_stdio(false);
	//preos da barra de tamanho i
	vector<int> p = {0,1,5,8,9,10,17,17,20,24,30};
	int n;
	cout << "Digite o tamanho da barra: ";
	cin >> n;
	cout <<  bottom_up_cut_rod(p,n) << endl;
	return 0;
}