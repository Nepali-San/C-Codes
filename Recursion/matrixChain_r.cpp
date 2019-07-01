#include <bits/stdc++.h>

using namespace std;

int mcr(int arr[],int init,int fin){
	if(init == fin){
		return 0;
	}
	
	int ans = INT_MAX;
	for(int i = init; i < fin; i++){
		ans = min(ans,mcr(arr,init,i) + mcr(arr,i+1,fin) + arr[init-1]*arr[i]*arr[fin]);
	}

	return ans;
}

int main() {
	
	int n;
	cin >> n;
	int arr[n];

	for(int i = 0; i< n; i++) cin >> arr[i];

	cout << mcr(arr,1,n-1) << endl;
			
	return 0;
}

