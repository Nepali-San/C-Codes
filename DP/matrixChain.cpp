#include <bits/stdc++.h>

#define ull                          unsigned long long int
#define endl                         '\n'
#define mp                           make_pair

using namespace std;

int dims[100];
int n;

ull matrixChain(){
	ull m[n][n];
	int q,j;

	for(int i = 0; i < n; i++) m[i][i] = 0;

	for(int len = 2; len < n; len++){
		for(int i = 1; i < n-len+1; i++){
			j = i+len-1;
			m[i][j] = INT_MAX;
			for(int k = i; k <= j-1; k++){
				q = m[i][k] + m[k+1][j] + dims[i-1]*dims[k]*dims[j];
				if(q < m[i][j]){
					m[i][j] = q;
				}
			}
		}
	}
	
	return m[1][n-1];
}

int main() {
	
	cout << "Enter the size of matrix array : ";	
	cin >> n;
	cout << "Enter the dimension of matrix array :\n";
	for(int i = 0; i < n; i++) cin >> dims[i];
	
	int ans = matrixChain();
	cout <<"The minimum possible no. of multiplication is " << ans << endl;
			
	return 0;
}