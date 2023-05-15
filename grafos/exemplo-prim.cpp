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
#include <queue>
#include <limits>
using namespace std;

class no{
public:
	int id;
	int d;
	void operator=(const no& other){
		id = other.id;
		d = other.d;
	}
};


struct compara_no{
	bool operator()(const no& n1, const no& n2) const{
		if(-n1.d < -n2.d){
			return true;
		}
		return false;
	}
};

void djikstra(vector<vector<int>>& g,
	vector<vector<int>>& w, int v){
	vector<int> color(g.size(),0);
	vector<int> distancia(g.size(),numeric_limits<int>::max());
	priority_queue<no,vector<no>,compara_no> q;
	distancia[v] = 0;
	no n;
	n.id = v;
	n.d = distancia[v];	
	q.push(n);
	while(!q.empty()){
		n = q.top();
		q.pop();
		int u = n.id;
		if(color[u]==2){
			continue;
		}
		color[u] = 1;
		cout << "Retirei o nó "  << u << endl;
		cout << "Distância de " << v << " até " << u << " = " << distancia[u] << endl;
		for(size_t i=0;i<g[u].size();i++){
			int z = g[u][i];
			int peso_aresta = w[u][i];
			cout << "Vizinho de " << u << " = " << z << endl;
			cout << "Distancia de " << v << " até " << z << " = " << distancia[z] << endl;
			cout << "Peso da aresta de " << u << " a " << z << " = " << peso_aresta << endl;
			if(color[z]!=2 && distancia[z] > peso_aresta){
				distancia[z] = peso_aresta;
				cout << "Atualizando a distância de " << z << " para " << distancia[z]<<endl;
				no ins;
				ins.id = z;
				ins.d = distancia[z];
				q.push(ins);
			}
		}
		color[u] = 2;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	int n,m;
	cout << "Digite o número de vértices: ";
	cin >> n;
	cout << "Digite o número de arestas: ";	
	cin >> m;
	vector<vector<int>> g(n);
	vector<vector<int>> w(n);
	for(int i=0;i<m;i++){
		int u,v,peso;
		cout << "Digite a aresta (u,v,peso): ";
		cin >> u >> v >> peso;
		g[u].push_back(v);
		g[v].push_back(u);
		w[u].push_back(peso);
		w[v].push_back(peso);
	}
	djikstra(g,w,0);
	return 0;
}