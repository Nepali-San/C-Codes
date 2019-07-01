#include<iostream>
#include<vector>

using namespace std;

void print_vector(vector<int> arr){
	for(int i = 0;i < arr.size(); i++){
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main(){
	vector<int> vet;
	int a;
	
	do{
	cout << "Enter a number : " << endl;
	cin >> a;
	if(a == 0) break;
	vet.push_back(a) ;
    }while(1);
    
    int sum = 0;
    for(int i = 0 ; i < vet.size() ; i++)
    	sum = sum + vet[i];
    	
	cout << sum;
}
