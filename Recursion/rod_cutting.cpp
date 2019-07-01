#include <bits/stdc++.h>

#define ull                          unsigned long long int
#define ll                           long long int
#define endl                         '\n'
#define all(v)                       begin(v), end(v)
#define pb(x)                        push_back(x)
#define mp                           make_pair
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define contains(container, value)   container.find(value) != container.end()
#define rep(i,a,b)                   for(int i  = a; i < b; i++)

using namespace std;

int rod[100];

int rod_cut(int l,int arr[]){

	if(l < 1) return 0;
	if(rod[l] != -1) return rod[l];

	
	int m = 0;
	for(int i = 0; i < l; i++){
		m = max(m,arr[i] + rod_cut(l-i-1,arr));
	}
	rod[l] = m;

	return rod[l];
}

int main() {
	ALLONS_Y;
	
	int l;
	cin >> l;
	int arr[l];

	fill(rod,rod+100,-1);

	for(int i =0; i< l; i++){
		cin >> arr[i];
	}

	cout << rod_cut(l,arr) << endl;
	
	return 0;	
}

