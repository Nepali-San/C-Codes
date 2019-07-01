#include <bits/stdc++.h>

using namespace std;

int ks(int n,int values[],int wt,int weight[]){

	if(n == 0 || wt == 0) return 0;

	if(wt < weight[n-1]) return 0;
	
	int ans = max( ks(n-1,values,wt,weight), values[n-1] + ks(n-1,values,wt-weight[n-1],weight) );

	return ans;

}

int main() {
	
	int n,wt;

	cin >> n >> wt;
	int values[n],weight[n];
	for(int i = 0; i  < n; i++) cin >> values[i];
	for(int i = 0; i  < n; i++) cin >> weight[i];

	cout << ks(n,values,wt,weight) << endl;
		
	return 0;
}

