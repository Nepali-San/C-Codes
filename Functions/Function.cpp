//Functions in cpp
#include<iostream>
using namespace std;

inline int adder(int a,int b); //Inline function as like macro use for one or two line function
int add(int,int);
double add(double , double);
int add(int,int,int);
int mul(int a, int b, int c = 100); //c is 100 by default ,here c is default arguement
    
int main(){	
	//Function overloading and polymorphism
	cout << add(10,20) << endl;
	cout << add(23.23,34.78) << endl;
	cout << add(10,20,30) << endl; 
	
	 
	cout << mul(10,20) << endl;  //Only two arguements instead of three
	cout << mul(10,20,30) << endl; //Giving all the arguements
		
	cout << adder(20 , 10);	//Inline function adder
	return 0;
}

int add(int a , int b){
	return a+b;
}

double add(double a,double b){
	return a+b;
}

int add(int a , int b, int c){
   return a+b+c;
}

int mul(int a , int b , int c ){  //If c in not passed 100 is by default as per function definition;
	return a*b*c;
}

inline int adder(int a , int b){
	return a+b;
}
