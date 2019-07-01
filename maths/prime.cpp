#include <bits/stdc++.h>

#define endl                         '\n'
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

int main() {
	ALLONS_Y;
	
	int n;
	cin >> n;
	
	bool isPrime = true;
	int i;
	for(i = 2; i*i <= n; i++){
		if(n % i == 0){
			isPrime = false;
			break;
		}
	}
	
	if(isPrime)
		cout << n << " is a prime number." << endl;
	else
		cout << n << " is divisible by " << i << endl;
		
	return 0;
}
