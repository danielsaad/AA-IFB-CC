/**
Autor: Daniel Saad Nogueira Nunes
Nome do Problema:
ID do Problema: 
url do Problema: 
Técnica:
Complexidade:
Comentários:
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class tarefa{
public:
	int m_beneficio; 
	int m_deadline;
	tarefa(){}
};

class ordena_tarefa{
public:
	bool operator()(const tarefa& t1,const tarefa& t2){
		if(t1.m_beneficio>t2.m_beneficio){
			return true;
		}
		if(t1.m_beneficio==t2.m_beneficio){
			if(t1.m_deadline>=t2.m_deadline){
				return true;
			}
		}
		return false;
	}
};


int main(){
	std::ios::sync_with_stdio(false);
	vector<tarefa> t;
	int n;
	cout << "Digite o numero de tarefas: ";
	cin >> n;
	t.resize(n);
	for(int i=0;i<n;i++){
		cout << "Digite o beneficio da " << i+1 << " tarefa: ";
		cin >> t[i].m_beneficio;
		cout << "Digite o deadline da " << i+1 << " tarefa: ";
		cin >> t[i].m_deadline;
	}
	sort(t.begin(),t.end(),ordena_tarefa());
		for(int i=0;i<n;i++){
		cout << "Beneficio da " << i+1 << " tarefa ordenada: ";
		cout  << t[i].m_beneficio << endl;
		cout << "Deadline da " << i+1 << " tarefa ordenada: ";
		cout << t[i].m_deadline << endl;
	}
	return 0;
}