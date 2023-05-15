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
#include <algorithm>
using namespace std;


int lcs_forca_bruta(const string& x, const string& y, int n,int m){
	if(n==0 || m==0){
		return 0;
	}
	if(x[n-1]==y[m-1]){
		return 1+lcs_forca_bruta(x,y,n-1,m-1);
	}
	else{
		return max(lcs_forca_bruta(x,y,n-1,m),lcs_forca_bruta(x,y,n,m-1));
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	string x,y;
	cout << "Digite as sequencias X e Y: ";
	cin >> x >> y;
	cout << "A maior subsequencia comum de X e Y tem tamanho: " 
	<< lcs_forca_bruta(x,y,x.size(),y.size()) << endl;
	return 0;
}