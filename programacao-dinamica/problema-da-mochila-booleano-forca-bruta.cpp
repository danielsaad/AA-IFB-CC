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
#include <iomanip>

using namespace std;

int mochila_booleana_forca_bruta(int H, vector<int>& h,vector<int>& b, int i){
	if(i==-1){
		return 0;
	}
	int v1,v2;
	v1 = v2 = -1;
	if(H-h[i]>=0){
		v1 = mochila_booleana_forca_bruta(H-h[i],h,b,i-1)+b[i];
	}
	v2 = mochila_booleana_forca_bruta(H,h,b,i-1);
	return (max(v1,v2));
}

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	int H;
	vector<int> h; 
	vector<int> b;

	cout << "Digite o numero de namorados: ";
	cin >> n;
	cout  << "Digite o numero de horas disponiveis para namoro: ";
	cin >> H;
	h.resize(n);
	b.resize(n);
	for(int i=0;i<n;i++){
		cout << "Digite o numero de horas demandadas pelo namorado " << i << ": ";
		cin >> h[i];
		cout << "Digite o beneficio dado pelo namorado " << i << ": ";
		cin >> b[i];
	}
	cout << "A quantidade de beneficio máxima é de: " << mochila_booleana_forca_bruta(H,h,b,n-1) << endl;
//	cout << "\n";
//	for(int i=-1;i<n;i++){
//		for(int j=0;j<=H;j++){
//			cout << fixed << setw(4) << mochila_booleana_forca_bruta(j,h,b,i) << " ";
//		}
//		cout << "\n";
//	}
	return 0;
}