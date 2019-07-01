#include<iostream>
using namespace std;

void Demo(int a){
	if(a < 1) return;
	else{
		cout << a << " " ;
		Demo(a-1);
		cout << a << " " ;
	}
}

int main(){
	int x;
	cin >> x;
	Demo(x);
	return 0;
}
