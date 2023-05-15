#include <iostream>
#include <queue> //necessário para utilizar fila

using namespace std;

/**
 * A fila é uma Estrutura de Dados que permite inserção no final e remoção no início.
 * Segue a filosofia FIFO (primeiro a entrar é o primeiro a sair).
 *
 * A complexidade de inserção/remoção é O(1).
 * Normalmente a fila é implementado através de uma lista duplamente ligada.
 *
 * Métodos para utilização:
 * push - Insere no fim.
 * pop() - Remove no início
 * front() - acessa o primeiro elemento.
 * is_empty() - retorna verdadeiro se a fila está vazia e falso caso contrário
 */

int main(){
    queue<int> q; //declaração de uma fila de inteiros
    q.push(1); //insere no final
    q.push(2); //insere no final
    q.push(3); //insere no final
    while(!q.empty()){
        int elem = q.front();
        cout << "Elemento do início da fila = " << elem << "\n";
        q.pop();
	}
	return 0;
}
