#include <iostream>
#include <vector>

using namespace std;
/**
 * A lista de adjacências representa o grafo em espaço O(|V|+|E|)
 * e possibilita busca em largura ou profundidade em tempo O(|V|+|E|)
 */

int main(){
    int n,m;
    vector<vector<int>> l_adj;
    cout << "Digite o número de vértices: ";
    cin >> n;
    cout << "Digite o número de arestas: ";
    cin >> m;
    l_adj.resize(n);
    for(int i=0;i<m;i++){
        int a,b;
        cout << "Dados da Aresta " << i << "\n";
        cout << "Digite o no de origem (0 a " << n << "): ";
        cin >> a;
        cout << "Digite o no de destino (0 a " << n << "): ";
        cin >> b;
        l_adj[a].push_back(b);
        // l_adj[b].push_back(a); //Descomentar se o grafo não for direcionado
    }
    cout << "\n\nImprimindo Lista de Adjacências \n\n";
    for(int i=0;i<l_adj.size();i++){
        cout << i << " -> ";
        for(int j=0;j<l_adj[i].size();j++){
            cout << l_adj[i][j];
            cout << " -> ";
        }
        cout << "\n";
    }
    return 0;
}
