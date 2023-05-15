#include <iostream>
#include <vector>
#include <algorithm> //necessário para o método sort
#include <string>
/**
 * Este programa cria um vetor de cinco elementos do tipo pessoa
 * e ordena as mesmas por ordem crescente de idade.
 */
using namespace std;

class pessoa{
public:
    pessoa(string nome, int idade){
        m_nome = nome;
        m_idade = idade;
    }

    string m_nome;
    int m_idade;

    bool operator<(const pessoa& other) const{
        if(m_idade < other.m_idade){
            return true;
        }
        return false;
    }
};

int main(){
    vector<pessoa> v;
    for(int i=0;i<5;i++){
        string nome;
        int idade;
        cout << "Digite o nome da " << i+1 << " pessoa: ";
        cin >> nome;
        cout << "Digite a idade da " << i+1 << " pessoa: ";
        cin >> idade;
        v.push_back(pessoa(nome,idade));
    }
    sort(v.begin(),v.end()); //ordena de acordo com o criterio estabelecido pelo operador <
    for(int i=0;i<5;i++){
        cout << "Nome da " << i+1 << " pessoa ordenada = " << v[i].m_nome << endl;
        cout << "Idade da " << i+1 << " pessoa ordenada = " << v[i].m_idade << endl << endl;
    }
    return 0;
}
