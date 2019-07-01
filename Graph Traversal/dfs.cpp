#include <bits/stdc++.h>

#define ull                          unsigned long long int
#define ll                           long long int
#define endl                         '\n'
#define pb(x)                        push_back(x)
#define mp                           make_pair
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

void dfs(int src, vector< vector<int> > &v,int visited[]){
	cout << src + 1 << " ";
	visited[src] = 1;

	for(auto it = v[src].begin(); it != v[src].end(); it++){
		if(!visited[*it]){
			dfs(*it,v,visited);
		}
	}
}

int main() {
	ALLONS_Y;
	
	int n,e;
	cin >> n >> e;
	
	vector< vector<int>  > v(n);

	int src,dest;
	for(int i = 0; i < e; i++){
		cin >> src >> dest;
		v[src-1].pb(dest-1);
		v[dest-1].pb(src-1);
	}

	int s = 0;
	int visited[n] = {0};

	dfs(s,v,visited);
	cout << endl;
	
	return 0;
}

