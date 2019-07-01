#include<iostream>
#include<map>

using namespace std;

bool is_prime(int num){
	bool isprime = true;
	for(int i = 2; i*i <= num; i++){
		if(num % i == 0){
			isprime = false;
			break;
		}
	}
	return isprime;
}

int main(){
	int k;
	map<int,int> prime;
	cout << "Enter the maximum range of numbers :\n";
	int n;
	cin >> n;
	int m = 1;
	for(int i = 2; i <= n; i++){
		if(is_prime(i)){
			prime.insert(make_pair(m,i));
			m++;
		}
	}
	cout << "Enter the index : ";
	cin >> k;
	cout << "The " << k << " th prime number is " << prime[k];

	return 0;
}
