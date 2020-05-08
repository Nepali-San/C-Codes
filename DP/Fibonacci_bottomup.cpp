//program to calculate nth fibonacci number : 0 1 1 2 3 5 8 ...
#include<iostream>
using namespace std;

//Normal recursive method: O(2^n) ...top down approach
int fibo(int n){
	if(n <= 1) return n;
	return fibo(n-1) + fibo(n - 2);   
}

//bottom up approach : O(n)
int fibo2(int n){
	if(n <= 1) return n;
	int arr[50];
	arr[0] = 0 ; arr[1] = 1;
	for(int i = 2; i  <= n; i++){
		arr[i] = arr[i-1] + arr[i-2];
	}
	return arr[n];
}

//space optimized bottom up approach : O(n)
int fibo3(int n){
	if(n <= 1) return n;

	int a = 0,b = 1,c;		
	for(int i = 2; i  <= n; i++){
		c = a+b;
		a = b;
		b = c;
	}
	return c;
}

int main(){
	int n;
	cin >> n;
	cout << fibo2(n) << endl;
	cout << fibo3(n) << endl;
	return 0; 
}
