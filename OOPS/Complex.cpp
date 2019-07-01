#include<iostream>
using namespace std;

class Complex{
	private:
		int r = 0, i = 0;
	public:
	Complex(){};
	Complex(int a) : r(a) , i(a){} //A way to initialize contructor outside it's block
	
	Complex(int a , int b){
		r = a; 
		i = b;
	} 	
	
	Complex operator+(Complex &x){
		Complex temp;
		temp.r  = r + x.r;
		temp.i =  i + x.i;
		return temp;
	}		
	
	friend Complex operator-(Complex &x, Complex &y){
		Complex temp;
		temp.r = x.r - y.r;
		temp.i = x.i - y.i;
		return temp;
	}
	
	friend void display(Complex &x){
		if(x.i >= 0)
		cout << x.r << " + " << x.i << " i" << endl;
		else 
		cout << x.r << " - " << -x.i << " i " << endl;
	}
};
int main(){
	Complex x = 4;                //Way 1 
	display(x);	
	Complex x1 = Complex(5);      //Way 2
	display(x1);	
	Complex y  = Complex(3,2);    //Way 2 for multiple arguements
	display(y);
	Complex c1(2,4), c2(1,6);     //Way 4
	display(c1);
	display(c2);
	cout << "After addition" << endl;
	Complex c3;
	c3 = c1 + c2;                 //overloading operatior '+' and using implicit copy constructor
	display(c3);
	cout << "After subraction" << endl;
	Complex c4;
	c4 = c1 - c2;
	display(c4);		
	return 0;
}
