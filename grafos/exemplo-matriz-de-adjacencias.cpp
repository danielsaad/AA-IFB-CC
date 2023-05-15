#include <iostream>
#include <vector>

using namespace std;
/**
 * A matriz de adjacências representa o grafo em espaço O(|V|^2|)
 * e possibilita busca em largura ou profundidade em tempo O(|V|^2)
 */

int main(){
    int n,m;
    vector<vector<bool>> m_adj;
    cout << "Digite o número de vértices: ";
    cin >> n;
    cout << "Digite o número de arestas: ";
    cin >> m;
    m_adj.resize(n);
    for(int i=0;i<m_adj.size();i++){
        m_adj[i].resize(n);
    }
    for(int i=0;i<m;i++){
        int a,b;
        cout << "Dados da Aresta " << i << "\n";
        cout << "Digite o no de origem (0 a " << n << "): ";
        cin >> a;
        cout << "Digite o no de destino (0 a " << n << "): ";
        cin >> b;
        m_adj[a][b] = 1;
        // m_adj[b][a] = 1; //Descomentar se o grafo não for direcionado
    }
    cout << "\n\nImprimindo Matriz de Adjacências \n\n";
    for(int i=0;i<m_adj.size();i++){
        cout << i << " -> ";
        for(int j=0;j<m_adj[i].size();j++){
            if(m_adj[i][j]){
                cout << j;
                cout << " -> ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}
