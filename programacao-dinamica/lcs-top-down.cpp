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
#include <vector>
using namespace std;


int lcs_top_down(const string& x,const string& y, int n,int m,vector<vector<int>>& c){
	if(n==0 || m==0){
		return 0;
	}
	if(c[n-1][m-1]!=-1){
		return c[n-1][m-1];
	}
	if(x[n-1]==y[m-1]){
		c[n-1][m-1] = 1+ lcs_top_down(x,y,n-1,m-1,c);
		return (c[n-1][m-1]);
	}
	else{
		c[n-1][m-1] = max(lcs_top_down(x,y,n-1,m,c),lcs_top_down(x,y,n,m-1,c));
		return c[n-1][m-1];
	}
}

int lcs(const string& x,const string& y){
	vector<vector<int>> c(x.size(),vector<int>(y.size(),-1));
	return(lcs_top_down(x,y,x.size(),y.size(),c));
}

int main(){
	std::ios::sync_with_stdio(false);
	string x,y;
	cout << "Digite as sequencias X e Y: ";
	cin >> x >> y;
	cout << "A maior subsequencia comum de X e Y tem tamanho: " 
	<< lcs(x,y) << endl;
	return 0;
}