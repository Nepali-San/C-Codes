#include <bits/stdc++.h>

#define endl                         '\n'
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mp							 make_pair
#define pb(x)						 push_back(x)

using namespace std;

//function to select the min key for unvisited nodes.
int minKey(int key[],int n,bool visited[]){
	int min_value = INT_MAX,min_idx = -1;
	for(int i = 0; i < n; i++){
		if(!visited[i] && min_value > key[i]){
			min_value = key[i];
			min_idx = i;
		}
	}
	return min_idx;
}



void Prims(vector<pair<int,int> > nodes[],int n,int e){
	
	bool visited[n];
	int key[n];
	int parent[n];
	
	//initially all nodes are unvisited,
	//no node has parent and key of each node is initialize to inf.
	for(int i = 0; i < n; i++){
		visited[i] = false;
		parent[i] = -1;
		key[i] = INT_MAX;
	}

	//source vertex is 0.
	key[0] = 0;

	for(int i = 0; i < n; i++){

		//get the minimum key among all the unvisited nodes.
		int u = minKey(key,n,visited);

		//select the node and mark it as visited.
		visited[u] = true;

		//for each nodes adjacent to choosen node, minimize the nodes key if possible.
		for(auto i : nodes[u]){
			if(!visited[i.first] && i.second < key[i.first]){
				//minimize key value,
				key[i.first] = i.second;				
				//mark 'u' as parent of this node
				parent[i.first] = u;
			}
		}
	}

	//print the graph obtained the prims algo.
	cout << "A  | B  | wt" << endl;
	for(int i = 1; i < n; i++){
		cout << i << " " << parent[i] << " " << key[i] << endl;
	}

}

int main() {
	ALLONS_Y;

	int n,e;

	//no. of nodes and edges,
	cin >> n >> e;

	//list/array of src and dest pairs along with edge wt.
	//uses adjacency list representation.
	vector<pair<int,int> > nodes[n];

	int src,dest,wt;
	for(int i = 0; i < e; i++){
		cin >> src >> dest >> wt;
		nodes[src].pb(mp(dest,wt));
		nodes[dest].pb(mp(src,wt));
	}

	Prims(nodes,n,e);	

	return 0;
}

