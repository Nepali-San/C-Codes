#include <bits/stdc++.h>

//get the prime factorization of an integer.

using namespace std;

int main() {
	
	int n;
	cout << " Factorize : ";
	cin >> n;
	int num = n;
	vector<int> fact;

	cout << endl;

	for(int i = 2; i*i <= n; i++){
		if(n % i == 0){
			do{ 
				n = n/i;
				fact.push_back(i);
			}while(n % i == 0);
		}
	}
	
	if(n != 1)
		fact.push_back(n);
	
	cout << num << " = ";
	for(int i = 0; i < fact.size(); i++){		
		cout << fact[i];
		i != fact.size()-1 ? cout << " * " : cout << endl;
	}

	return 0;
}

