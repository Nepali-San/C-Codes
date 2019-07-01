#include<iostream>
using namespace std;

int multiply_5(int x){
	cout << "You called me with " << x << endl;
	return 5*x;
}

int multiply_3(int a){
	cout << "You called me with " << a << endl;
	return 3*a;
}

int Func_chooser(int data, int (*f) (int) ){
	return (*f)(data);
}

int main(){
	int (*a) (int)   = multiply_5;      //a takes the address of function
	cout << Func_chooser(5,a) << endl;  //passing data and appropriate function address
	cout << Func_chooser(5,multiply_3) << endl;
	cout << Func_chooser(4,multiply_5) << endl;
	return 0;
}
