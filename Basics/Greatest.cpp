#include<iostream>
using namespace std;

class Greater{
	public:
	int greater(int a , int b, int c){
		if(a > b && a > c){
			return a;
		}
		else if ( b > c && b > a){
			return b;
		}
		else return c;
	}
};

int main(){
	int a , b ,c;
	cout << "Enter any 3 numbers " ;
	cin >> a >> b >> c;
	Greater g;
	cout << "Greater no. is " << g.greater(a,b,c);
}
