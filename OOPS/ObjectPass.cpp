//Here we pass two objects to a function as arguements
#include<iostream>
using namespace std;

class Time{
	int h , m;
	public:
		
	void gettime(int a , int b){  //for very short function declare in class, it will be inline.
		h = a , m = b;
	}
	
	void puttime(){
		cout << h << ":" << m << endl;
	}
	
	//Declaring a sum function
	void sum(Time , Time );  //add * and replace . by -> , it will be pass by address
	                         //add & it will be pass by reference
};

void Time::sum(Time t1 , Time t2){  //Here also
	int ho =  t1.m + t2.m;
	h = t1.h + t2.h + (ho / 60);
	m = ho % 60;
} 

int main(){
	Time t1,t2,t3;
	
	t1.gettime(2,30);
	t2.gettime(3,55);
	
	t3.sum(t1,t2);  //pass by value
	
	t1.puttime();
	t2.puttime();
	t3.puttime();
	
	return 0;
}
