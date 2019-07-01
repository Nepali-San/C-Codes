#include<iostream>

using namespace std;

class prime{
	public:
	bool is_prime(int n){
		if(n == 1) return false;
		for(int i = 2; i*i <= n; i++ ){
			if(n % i == 0) return false;
		}
		return true;
	}
};

int  main(){
	prime obj;
	int n;
	cout << "Enter a number: ";
	cin >> n;
	bool x = obj.is_prime(n);
	cout << "x = " << x << endl;
	if(x) cout << "is prime\n";
	else cout << "Not prime" << endl;
	return 0;
}
