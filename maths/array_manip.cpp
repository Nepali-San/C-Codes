#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int a,b,c;
	vector<int> array(n,0);
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		array[a-1] += c;
		if(b < n)
			array[b] -= c;
	}

	for(int i = 1; i < n; i++){
		array[i] = array[i-1] + array[i];
	}

	m = array[0];
	for(int i = 0; i < n; i++){
		m = max(m,array[i]);
	}

	cout << m << endl;

	return 0;
}
