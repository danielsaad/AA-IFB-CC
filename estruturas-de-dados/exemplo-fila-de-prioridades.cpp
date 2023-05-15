#include <iostream>
#include <queue> //necessário para utilizar fila de prioridades

using namespace std;

/**
 * A fila de prioridades é uma Estrutura de Dados que permite que elementos com maior prioridade
 * sejam retirados primeiro.
 *
 * A complexidade de inserção/remoção é O(lg n).
 * Normalmente a fila é implementado através de uma heap.
 *
 * Métodos para utilização:
 * push - Insere no fim.
 * pop() - Remove no início
 * top() - Retorna elemento no início da Fila de Prioridades
 * is_empty() - retorna verdadeiro se a fila está vazia e falso caso contrário
 */


class pessoa{
public:
    pessoa(string nome, int idade){
        m_nome = nome;
        m_idade = idade;
    }

    bool operator<(const pessoa& other) const{
        if(m_idade<other.m_idade){
            return true;
        }
        return false;
    }
    string m_nome;
    int m_idade;
};

int main(){
    priority_queue<pessoa> pq; //declaração de uma fila de prioridade de pessoas
    for(int i=0;i<5;i++){
        string nome;
        int idade;
        cout << "Digite o nome da " << i+1 << " pessoa: ";
        cin >> nome;
        cout << "Digite a idade da " << i+1 << " pessoa: ";
        cin >> idade;
        cout << "\n";
        pq.push(pessoa(nome,idade));
    }
    cout << "\n\nRetirando pessoas com base na prioridade.\n\n";
    while(!pq.empty()){
        cout << "Nome: " << pq.top().m_nome << "\n";
        cout << "Idade: " << pq.top().m_idade << "\n\n";
        pq.pop();
	}
	return 0;
}
