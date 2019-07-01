#include<iostream>
using namespace std;

class Swap{
	public :
	void swapper(int a , int b){
		 a = a + b;
		 b = a - b;
		 a = a - b;
		 cout << "After swapping a = " << a << " and b = " << b;
	}
};

int main(){
	Swap s;
	int a , b;
	cout << "Enter two numbers a and b to swap " << endl;
	cin >> a >> b;
	s.swapper(a,b);
	return 0;
}
