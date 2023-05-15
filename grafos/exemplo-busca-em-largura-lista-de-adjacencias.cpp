#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
/**
 * A lista de adjacências representa o grafo em espaço O(|V|+|E|)
 * e possibilita busca em largura ou profundidade em tempo O(|V|+|E|)
 */

void bfs(vector<vector<int>>& g, int v){
    const int white = 0; //vértice não processado
    const int grey = 1; //vértice em processamento
    const int black = 2; // vértice processado
    vector<int> color(g.size(),white); //cor
    vector<int> d(g.size(),numeric_limits<int>::max()); //informação de distância
    vector<int> pai(g.size(),-1); //informação do pai
    color[v]=grey;
    d[v] = 0;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int u = q.front(); // retira o nó da fila
        q.pop();
        cout << "Nó visitado = " << u << endl;
        cout << "Pai do nó = " << pai[u] << endl;
        cout << "Distância da origem " << v << " = " << d[u] << endl;
        for(size_t j=0;j<g[u].size();j++){ //percorre a lista de adjacências
            int w = g[u][j]; //retira o nó adjacente
            if(color[w]==white){ //se o nó ainda não foi visitado, inclue ele na lista
                color[w] = grey; // marca o nó como em processamento
                pai[w] = u; //atualiza o pai
                d[w] = d[u]+1; //atualiza a distância
                q.push(w); //coloca o nó na fila
            }
        }
        color[u] = black;       
    }
}





int main(){
    vector<vector<int>> g;
    g.resize(5);
    g[0] = {1,4};
    g[1] = {2,3};
    g[2] = {3,4};
    g[3] = {3,3};
    g[4] = {0,1};
    bfs(g,4);
    return 0;
}
