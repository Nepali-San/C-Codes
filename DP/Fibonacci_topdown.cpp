//program to calculate nth fibonacci number : 0 1 1 2 3 5 8 ...
//using memoization technique 
#include<iostream>
using namespace std;

int fibo(int n,int memo[]){
	if(memo[n] != -1) return memo[n];
    memo[n] = fibo(n-1,memo) + fibo(n - 2,memo);
    return memo[n];
}

int main(){
	int memo[40];
	fill(memo,memo+40,-1);
	memo[0] = 0; memo[1] = 1; 
	int n;
	cin >> n;
	cout << fibo(n,memo) << endl;
	return 0; 
}
