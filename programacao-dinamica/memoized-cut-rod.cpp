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

int memoized_cut_rod_helper(const vector<int>& p, int n, vector<int>& r){
	if(r[n]>0){
		return r[n];
	}
	if(n==0){
		return 0;
	}
	int q = -1;
	for(int i=1;i<=n;i++){
		q = max(q,p[i] + memoized_cut_rod_helper(p,n-i,r));
	}
	r[n] = q;
	return r[n];
}


int memoized_cut_rod(const vector<int>& p, int n){
	vector<int> r(n+1,-1);
	return memoized_cut_rod_helper(p,n,r);
}


int main(){
	std::ios::sync_with_stdio(false);
	//preos da barra de tamanho i
	vector<int> p = {0,1,5,8,9,10,17,17,20,24,30};
	int n;
	cout << "Digite o tamanho da barra: ";
	cin >> n;
	cout <<  memoized_cut_rod(p,n) << endl;
	return 0;
}