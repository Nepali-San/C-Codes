//About constructors
#include<iostream>
using namespace std;

class Complex{
	float x , y;
	public:  //Constructors must be public member
	Complex(){}  // Default constructor , set x and y to 0
	Complex(float a , float b ){  //Constructor sets x = a and y = b,overloaded constructor
		x = a;
		y = b;
	}
	Complex(float a){ //sets both value to a
		x = y = a;
	}
	
	/*
	
	//Constructor with default arguement,
	//it takes single or double variable
	//Make cause ambuigity if used,since there will be 2 constructor that takes 2 arguements
	
	Complex(float a,float b = 0){  
       x = a;
       y = b;
	}
	
	*/
	
	friend Complex sum(Complex & , Complex &);
	friend void show(Complex &);
};

Complex sum(Complex &a,Complex &b){
	Complex ans;
	ans.x = a.x + b.x;
	ans.y = a.y + b.y;
	return ans;
}

void show(Complex &c){
	cout << c.x << "+" << c.y << "i" << endl;
	return;
}

int main(){
	Complex c1(3.2,1.5);
	Complex c2(8.2);
	Complex c3 = sum(c1,c2);
	cout << " c1 = "; show(c1);
	cout << " c2 = "; show(c2);
	cout << " c3 = "; show(c3);
	return 0;
}
