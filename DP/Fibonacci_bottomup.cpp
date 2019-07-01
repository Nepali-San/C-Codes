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

int main(){
	int n;
	cin >> n;
	cout << fibo2(n) << endl;
	return 0; 
}
