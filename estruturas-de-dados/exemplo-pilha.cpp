#include <iostream>
#include <stack> //necessário para utilizar stack

using namespace std;

/**
 * A pilha é uma Estrutura de Dados que permite inserção no início e remoção no início.
 * Segue a filosofia LIFO (último a entrar é o primeiro a sair).
 *
 * A complexidade de inserção/remoção é O(1).
 * Normalmente a pilha é implementada através de uma lista duplamente ligada.
 *
 * Métodos para utilização:
 * push ()- Insere no fim.
 * pop() - Remove no início
 * top() - acessa o elemento do topo da pilha.
 * is_empty() - retorna verdadeiro se a pilha está vazia e falso caso contrário
 */

int main(){
	stack<int> s; //declaração de uma pilha de inteiros
	s.push(2);
	s.push(5);
	s.push(4);
	while(!s.empty()){
		int elem = s.top();
		s.pop();
		cout << "Elemento do topo = " << elem << "\n";
	}
	return 0;
}
