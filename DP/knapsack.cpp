#include <bits/stdc++.h>

using namespace std;

int KnapSackFunc(int n,int w,int weights[],int values[]){
	int table[n+1][w+1];

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= w; j++){

			if(i == 0 || j == 0){
				table[i][j] = 0;
			}
			else if(weights[i-1] <= j){
				table[i][j] = max(values[i-1] + table[i-1][j-weights[i-1]],table[i-1][j]);
			}
			else{
				table[i][j] = table[i-1][j];
			}
		}
	}


	return table[n][w];
}

int main() {
	
	int n,w;
	cin >> n >> w;
	int weights[n],values[n];

	for(int i = 0; i < n; i++) cin >> weights[i];
	for(int i = 0; i < n; i++) cin >> values[i];

	cout << KnapSackFunc(n,w,weights,values) << endl;	
		
	return 0;
}

