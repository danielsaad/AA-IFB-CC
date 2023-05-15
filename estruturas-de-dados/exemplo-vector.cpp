#include <iostream>
#include <vector> //necessário para utilizar vector

using namespace std;

/**
 * O vector pode ser vista como um vetor dinâmico que permite a inserção de elementos
 *
 * A complexidade de inserção/remoção é O(1) amortizado desde que seja feita no final do vetor.
 * Métodos para utilização:
 * push_back() - inserção no final
 * pop_back() - remoção no final
 * size() - número de elementos
 * operador [] - retorna elemento na i-ésima posição do vetor. Exemplo: v[i]
 */

int main(){
    vector<int> v; //declaração de um vetor de inteiros
    for(int i=0;i<100;i++){
        v.push_back(100-i);
    }
    for(int i=0;i<100;i++){
        cout << "v[" << i << "] = " << v[i] << "\n";
    }

    cout << "Número de elementos  = " << v.size() << "\n";
	return 0;
}
