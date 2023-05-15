#include <iostream>
#include <vector>
#include <stack>
#include <limits>
using namespace std;
/**
 * A lista de adjacências representa o grafo em espaço O(|V|+|E|)
 * e possibilita busca em largura ou profundidade em tempo O(|V|+|E|)
 */

void dfs(vector<vector<int>>& g, int v){
    const int white = 0; //vértice não processado
    const int grey = 1; //vértice em processamento
    const int black = 2; // vértice processado
    vector<int> color(g.size(),white); //cor
    vector<int> pai(g.size(),-1); //informação do pai
    color[v]=grey;
    stack<int> s;
    s.push(v);
    while(!s.empty()){
        int u = s.top(); // retira o nó da pilha
        s.pop();
        cout << "Nó visitado = " << u << endl;
        cout << "Pai do nó = " << pai[u] << endl;
        for(size_t j=0;j<g[u].size();j++){ //percorre a lista de adjacências
            int w = g[u][j]; //retira o nó adjacente
            if(color[w]==white){ //se o nó ainda não foi visitado, inclue ele na lista
                color[w] = grey; // marca o nó como em processamento
                pai[w] = u; //atualiza o pai
                s.push(w); //coloca o nó na pilha
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
    dfs(g,4);
    return 0;
}
