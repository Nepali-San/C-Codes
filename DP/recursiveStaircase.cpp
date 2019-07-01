#include<iostream>
#include <map>
using namespace std;
map<int, long long int>memo;

long long int chance(int i , int n){
	n = n - i;	
	if(n == 0){
		return 1;
	}
	else if(n < 0){
		return 0;
	}
	else{
		if(memo.find(n) != memo.end()) {
			return memo[n];
		} else {
			long long int sum = chance(1,n) + chance(2,n) + chance(3,n);	
			memo.insert(make_pair(n, sum));
			return sum;
		}
	}
	
}

int main(){
	int n; 
	cin >> n;
	cout << chance(1,n) + chance(2,n) + chance(3,n);
	return 0;
}
