#include<iostream>
using namespace std;

void pattern(int x){
	if(x < 1) return;
	func(x-1);
	
	for(int i = 0; i < x; i++){
		cout << "*" << " " ;
	}
	cout << endl;
}

int main(){
	pattern(5);
}
