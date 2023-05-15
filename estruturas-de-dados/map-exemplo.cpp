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
#include <map>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	map<string,string> m;
	m["fish"] = "peixe";
	m["dog"] = "cachorro";
	m["cat"] = "gato";
	m["cow"] = "vaca";
	while(1){
		string animal;
		cout << "Digite o nome de um animal em inglês: ";
		cin >> animal;
		if(m.find(animal)!=m.end()){
			cout << "Tradução de " << animal << " = " << m[animal] << "." << endl;
		}
		else{
			cout << "Não existe tradução de " << animal << " no nosso dicionário." << endl;
		}
	}
	return 0;
}