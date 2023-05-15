#include <iostream>
#include <queue> //necessário para utilizar deque

using namespace std;

/**
 * O deque pode ser visto como uma fila em que é possível inserção/remoção no início e no final.
 *
 * A complexidade de inserção/remoção é O(1), em ambos os lados.
 * Normalmente o deque é implementado através de uma lista duplamente ligada.
 *
 * Métodos para utilização:
 * push_front() - Insere no início.
 * push_back() - Insere no final
 * pop_front() - Remove no início.
 * pop_back() - Remove no final.
 * front() - acessa o primeiro elemento.
 * back() - acessa o último elemento.
 * is_empty() - retorna verdadeiro se o deque está vazio e falso caso contrário
 */

int main(){
    deque<int> d; //declaração de um deque de inteiros
    d.push_front(1); //inserção na frente
    d.push_front(2); //inserção na frente
    d.push_back(4); //inserção no final
    d.push_back(3); //inserção no final
    while(!d.empty()){
        int elem = d.front();
        cout << "Elemento do início do deque " << elem << "\n";
        d.pop_front();
	}
	return 0;
}
