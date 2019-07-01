//bit manipulation in cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
	int a , b;
	cout << "Enter the value for a" << endl;
	cin >> a;
	cout << " part with - " << 2 << endl;
	cout << (a >> 1) << endl;  //  divide by 2^1
	cout << (a << 1) << endl;  //  multiply by 2^1
	cout << " part with - " << 16 << endl;
	cout << (a >> 4) << endl;  //  divide by 2^4
	cout << (a << 4) << endl;  //  multiply by 2^4
	cout << " part with - " << 4 << endl;
	cout << (a << 2) << endl;  //  divide by 2^2
	cout << (a >> 2) << endl;  //  multiply by 2^2	
	cout << "Enter value for b" << endl;
	cin >> b;
	cout << " a * 2^b = " << ( a << b) << endl;
	cout << " a & b = " << (a & b) << endl;
	cout << " a | b = " << (a | b) << endl;
	cout << " a ^ b = " << (a ^ b) << endl;
	cout << " ~a = " << ~a << endl;
return 0;
}
