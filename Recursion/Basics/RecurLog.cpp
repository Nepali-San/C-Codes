#include<iostream>
using namespace std;

int log_2(int a){
	if(a == 1) return 0;  			//no log2 of -ve values
	return 1 + log_2(a/2);          //put /3 to get log3 and similar for others
}

int main(){
	int n;
	cin >> n;
	cout << log_2(n);
}
