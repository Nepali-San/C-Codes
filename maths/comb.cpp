//finds the all possible combinations with r = 3 and given n.

#include <bits/stdc++.h>

#define ULL unsigned long long
#define LL long long
#define endl '\n'
#define ALL(v) begin(v), end(v)
#define CONTAINS(container, value) container.find(value) != container.end()

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;	

	for(int i = 1; i <= n-2; i++){
		for(int j = i+1; j <= n-1; j++){
			for(int k = j+1; k <= n; k++){
				cout << i <<' ' << j<< ' ' << k << endl;
			}
		}
	}
	
	return 0;
}

