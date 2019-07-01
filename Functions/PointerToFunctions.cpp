//Pointer to function , also known as callback function.
#include<iostream>
typedef void (*FunPtr)(int, int); 
using namespace std;

void add(int i , int j){
	cout << i << " + " << j << " = " << i+j << endl;
}

void sub(int i , int j){
	cout << i << " - " << j << " = " << i-j << endl;
}

int main(){
	FunPtr ptr;
		
	ptr = &add;
	ptr(1,2);
	
	ptr = &sub;
	ptr(3,1 );
	
	//The other way around...
	void (*ptr1) (int,int) = add;   //can also use &add
	ptr1(3,5);                      //similar to as calling add(3,5)
	
	return 0;
}
