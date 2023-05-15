#include <iostream>
#include <vector>
#include <stack>
#include <limits>
using namespace std;
/**
 * A lista de adjacências representa o grafo em espaço O(|V|+|E|)
 * e possibilita busca em largura ou profundidade em tempo O(|V|+|E|)
 */
static const int white = 0; //vértice não processado
static const int grey = 1; //vértice em processamento
static const int black = 2; // vértice processado

void dfs_helper(vector<vector<int>>& g,vector<int>& color,vector<int>& pai,int v){
    color[v] = grey;
    cout << "Nó visitado = " << v << endl;
    cout << "Pai de " << v << " = " << pai[v] << endl;
    for(size_t i=0;i<g[v].size();i++){
        int w = g[v][i];
        if(color[w]==white){
            pai[w] = v;
            dfs_helper(g,color,pai,w);
        }
    }
    color[v] = black;
}



void dfs(vector<vector<int>>& g, int v){
    vector<int> color(g.size(),white);
    vector<int> pai (g.size(),-1);
    dfs_helper(g,color,pai,v);
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
