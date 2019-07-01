#include <bits/stdc++.h>

#define ull                          unsigned long long int
#define ll                           long long int
#define endl                         '\n'
#define pb(x)                        push_back(x)
#define mp                           make_pair
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

int main() {
	ALLONS_Y;
	
	int n,e;
	cin >> n >> e;

//	vector< vector<int> > v(n);
	list<int> v[n];

	for(int i = 0; i < e; i++){
		int src,dest;
		cin >> src >> dest;
		v[src-1].pb(dest-1);
		v[dest-1].pb(src-1);
	}

	queue<int> Q;
	Q.push(0);

	int visited[n] = {0};    // false == 0
	visited[0] = 1;		     // true  == 1

	while(!Q.empty()){
		int top = Q.front();
		Q.pop();

		cout << top+1 << " ";

		for(auto it = v[top].begin(); it != v[top].end(); it++){
			if(!visited[*it]){
				Q.push(*it);
				visited[*it] = 1;
			}
		}
	}
		
	return 0;
}

