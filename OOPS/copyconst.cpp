#include<iostream>
using namespace std;

class fact{
	int f = 1;
	
	public:
	fact(int a){
		for(int i = 1; i <= a; i++)
		f = f * i;
	}
	fact(fact & c){
		f = c.f;
	}
    int display(){
		return f;
	}
};

int main(){
	fact a(3);
	fact b(a);
	cout << b.display() << endl;
	cout << a.display();
	return 0;
}
