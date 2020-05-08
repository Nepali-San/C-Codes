#include <bits/stdc++.h>

//Kadane algorithm , to find the max sum of contiguous subarray in 1D array.

using namespace std;

int maxSubarrSum(int arr[],int size){
	
	int max_sum = arr[0];
	int max_ans = arr[0];

	for(int i= 1; i < size; i++){
		max_sum =  max(arr[i],max_sum+arr[i]);
		max_ans = max(max_ans,max_sum);		
	}

	return max_ans;
}

int main() {
	int n;
	cin >> n;

	int arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];

	cout << maxSubarrSum(arr,n) << endl;
		
	return 0;
}

