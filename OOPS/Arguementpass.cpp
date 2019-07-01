#include<iostream>
using namespace std;

void swap(int a,int b){
	a = a + b;
	b = a - b;
	a = a - b;
}

void swap(int *c , int * d){
	*c = *c + *d;
	*d = *c - *d;
	*c = *c - *d;
}

void swap1(int &a , int &b){
	a = a + b;
	b = a - b;
	a = a - b;
}

int main(){
	int a = 30 , b = 60;
	swap(a,b);     //values are not swapped
	cout << "a = " << a << " b = " << b << endl;
	swap(&a,&b);   //Pass by address
	cout << "a = " << a << " b = " << b << endl;
	swap1(a,b);    //Pass by reference
	cout << "a = " << a << " b = " << b << endl;
	return 0;
}
