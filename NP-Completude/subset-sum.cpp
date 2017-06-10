#include <iostream>
#include <vector>

bool subset_sum_solver(std::vector<int>& S,int k,int i,int partial_sum){
	if(partial_sum==k)
		return true;
	else if(partial_sum>k || i==S.size())
		return false;
	bool b = subset_sum_solver(S, k,i+1, partial_sum + S[i]);
	b = b || subset_sum_solver(S, k,i+1, partial_sum);
	return b;
}

bool subset_sum(std::vector<int>& S,int k){
	return subset_sum_solver(S, k,0,0);
}

int main(){
	std::vector<int> S = {1, 3, 8, 13, 22, 37, 62, 47, 83, 20, 33, 100, 65};
	int k = 205;
	bool res = subset_sum(S,k);
	res ? std::cout << "Verdadeiro\n" : std::cout << "Falso\n";
	return 0;
}
