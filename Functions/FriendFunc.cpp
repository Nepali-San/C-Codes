//Using friend function to access private member outside of class...

#include<iostream>
using namespace std;

class two;

class one {
	int roll ;
	string name;
	public:
		
	void getroll(int n){ roll = n;}
	void getname(string names){ name = names;}
	void putdata(){cout << name << " - " << roll << endl;}
	
	friend void swaproll(one &, two &);
};

class two {
	int roll ; 
	string name;
	public:
		
	void getroll(int n){ roll = n;}
	void getname(string names){ name = names;}
	void putdata(){	cout << name << " - " << roll << endl;}
	
	friend void swaproll(one &, two &);
};


void swaproll(one &a,two &b){
	int temp = a.roll;
	a.roll = b.roll;
	b.roll = temp;
}

int main(){
	one a;
	two b;
	a.getname("San");
	a.getroll(2);
	b.getname("xyz");
	b.getroll(1);
	
	a.putdata();
	b.putdata();
	
	swaproll(a,b);  //pass by reference
	cout << "\nAfter exchanging the roll number\n";
	a.putdata();
	b.putdata();
}
