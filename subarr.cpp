#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int myfunc(int i , int j ) { return i > j; }

//int maxsubarr(vector<int> &arr){
//	int ans = INT_MIN;
//	for(int size = 1; size <= arr.size(); size++){
//		for(int si = 0; si < arr.size(); si++){
//			if(si + size > arr.size()) break;
//			int sum = 0;		
//			for(int i = si; i < (size + si); i++){
//				sum += arr[i];				
//			}
//			ans = max(sum,ans);
//		}
//	}
//	return ans;	
//}


//int maxsubarr(vector<int> &arr){
//	int ans = INT_MIN;
//	for(int si = 0; si < arr.size(); si++){
//		int sum = 0;
//		for(int size = 1; size <= arr.size(); size++){
//			if(si + size > arr.size()) break;
//			sum += arr[si+size-1];
//			ans = max(sum,ans);
//		}
//	}	
//	return ans;	
//}

int maxsubarr(int arr[], int n){
	if(n == 1) return arr[0];
	int m = n/2;
	int left_mss = maxsubarr(arr,m);
	int right_mss = maxsubarr(arr+m,n-m);
	int left_sum = INT_MIN, right_sum = INT_MIN, sum = 0;
	for(int i = m; i < n; i++){
		sum += arr[i];
		right_sum = max(right_sum,sum);
	}
	sum = 0;
	for(int i = (m-1); i >= 0; i--){
		sum += arr[i];
		left_sum = max(left_sum,sum);
	}
	int ans = max(right_mss,left_mss);
	return max(ans,left_sum+right_sum);
}

int maxsubseq(int arr[],int size){
	sort(arr,arr+size,myfunc);
	int max = arr[0];
	for(int i = 1; i < size; i++){
		if(max + arr[i] > max) max += arr[i];
		else break;
	}
	return max;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++) cin >> arr[i];
		cout << maxsubarr(arr,n) << " ";
		cout << maxsubseq(arr,n) << endl;			
	}
	return 0;
}
