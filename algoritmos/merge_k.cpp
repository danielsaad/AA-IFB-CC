/**
Autor: Daniel Saad Nogueira Nunes
Técnica: Merge de k vetores utilizando uma Heap
Complexidade: \Theta(nk \lg k)
Comentários: utilizar uma heap para fazer o merge de k vetores
é mais rápido que utilizar o merge força bruta
**/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


class no_heap{
public:
	no_heap(int valor,int id){
		m_valor = valor;
		m_id = id;
	}

	no_heap(const no_heap& other){
		m_valor = other.m_valor;
		m_id = other.m_id;
	}

	bool operator<(const no_heap& other)const {
		if(m_valor < other.m_valor){
			return false;
		}
		return true;
	}

	int m_valor;
	int m_id;
};

int main(){
	std::ios::sync_with_stdio(false);
	vector<vector<int>> m;
	m.resize(3);
	m[0] = {1,2,5,7,9,12,15,18,20,21};
	m[1] = {3,4,5,8,10,13,14,17,19,30};
	m[2] = {2,4,6,8,11,15,16,21,22,24};
	vector<int> ponteiros(m.size(),0);
	vector<no_heap> heap;
	for(int i=0;i<m.size();i++){
		heap.push_back(no_heap(m[i][0],i));
	}
	make_heap(heap.begin(),heap.end());
	while(!heap.empty()){
		no_heap no = heap.front();
		pop_heap(heap.begin(),heap.end());
		heap.pop_back();
		cout << no.m_valor << "\n";
		int id  =  no.m_id;
		ponteiros[id]++;
		if(ponteiros[id]<m[id].size()){
			no_heap n2(m[id][ponteiros[id]],id);
			heap.push_back(n2);
			push_heap(heap.begin(),heap.end());
		}
	}
	return 0;
}