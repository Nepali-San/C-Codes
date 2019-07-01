#include<iostream>
using namespace std;

void swap1(int &a , int &b); //uses a new name a and b to passed arguements
void swap2(int *a , int *b); //Assigns original address of passed arguemens

int main(){
	int a = 10 , b = 20;
	cout << "Before swapping " << a << "  " << b << endl;
	swap2(&a , &b);
	cout << "After swapping using c - pointer method : " << a << "  " << b << endl;
	swap1(a,b);
	cout << "After swapping using c++ & method : " << a << "  " << b << endl << endl;
	
	//More about & 
	int data = 100;
	
	int &c = data;  //Assign a new name to data
	cout << "data is " << data << " c is " << c << endl;
	
	c+= 300;  //if altered the value of c then data is also altered simultaneusly
	cout << "data is " << data << " c is " << c << endl;
	
	return 0;
}

void swap1(int &a , int &b){
	int t = a;
	a = b;
	b = t;
}

void swap2(int *a ,int *b){
	int t = *a;
	*a = *b;
	*b = t;
}
