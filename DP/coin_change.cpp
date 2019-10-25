#include <bits/stdc++.h>

using namespace std;

//bottom up solutions for coin change...

int no_of_ways(int total,int size,int coins[]){
	
	int table[total+1][size];

	for(int i = 0; i < size; i++) table[0][i] = 1;	

	for(int i = 1; i < total+1; i++){
		for(int j = 0; j < size; j++){
			
			int x = (i - coins[j]) >= 0 ? table[i-coins[j]][j] : 0;
			int y = (j > 0) ? table[i][j-1] : 0;

			table[i][j] = x+y;

		
		}
	}

	return table[total][size-1];
	
}

//another space optimized bottom up solution for coin change...
int no_of_ways2(int total,int size,int coins[]){

	int table[total+1] = {1};		

	for(int i = 0; i < size; i++){
		for(int j = coins[i]; j < total+1; j++){
			table[j] += table[j-coins[i]];
		}
	}

	return table[total];
}

int main() {

	int n;
	scanf("%d",&n);

	int k;
	scanf("%d",&k);
	
	int coins[k];
	for(int i = 0; i < k; i++) scanf("%d",&coins[i]);

    cout << no_of_ways(n,k,coins) << endl;
	cout << no_of_ways2(n,k,coins) << endl;
		
	return 0;
}

