#include<iostream>
#include<vector>

using namespace std;
void functions(vector<vector<int>> vets);

int main(){
	vector<vector<int>> vet;
	for(int i = 0; i < 3; i++){
		vector<int> temp;
		for(int j = 0; j < 3; j++){
			temp.push_back(i);
		}
		vet.push_back(temp);
	}
	
	for(int i = 0 ; i < vet.size(); i++){
		for(int j = 0 ; j < vet[i].size(); j++){
			cout << vet[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\nBy using the functions\n";
	functions(vet);
	return 0;
}
//passing by value
void functions(vector<vector<int>> vets){  
	for(int i = 0; i < vets.size(); i++){
		for(int j = 0; j < vets[i].size(); j++){
			cout << vets[i][j] << " ";
		}
		cout << endl;
	}
}
