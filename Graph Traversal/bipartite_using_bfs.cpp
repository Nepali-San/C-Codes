/*
    Time  : 2019-10-15,Tuesday
    Desc  : checking if graph is bipartite using BFS.
*/

#include <bits/stdc++.h>

using namespace std;

enum color{
	white,
	black,
	none
};

int main(){

	int v, e;
	int a, b;
	cin >> v >> e;

	vector<vector<int>> g(v);

	for (int i = 0; i < e; i++){
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<color> colors(v, none);
	bool isBipartite = true;

	queue<int> Q;
	Q.push(0);
	colors[0] = color::white;

	while (!Q.empty()){
		int top = Q.front();
		Q.pop();

		for (auto it : g[top]){

			if (colors[it] == color::none){
				colors[it] = (color)(1 - colors[top]);
				Q.push(it);
			}
			else if (colors[it] == colors[top]){
				isBipartite = false;
				break;
			}
		}

		if (!isBipartite) break;
	}

	if (isBipartite)
		cout << "Bipartite" << endl;
	else
		cout << "Not Bipartite" << endl;

	return 0;
}