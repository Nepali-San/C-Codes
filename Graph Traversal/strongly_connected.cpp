#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> g[],int src,vector<bool> &visited,stack<int> &st){
	visited[src] = true;
	for(auto it : g[src]){
		if(!visited[it]) dfs(g,it,visited,st);
	}

	st.push(src);
}

void dfs2(vector<int> g[],int src,vector<bool> &visited){
	visited[src] = true;
	cout << src << " ";
	for(auto it : g[src]){
		if(!visited[it]) dfs2(g,it,visited);
	}
}


int main() {
	
	int nodes,edges;
	cin >> nodes >> edges;

	vector<int> g[nodes];
	int src,dest;
	for(int i = 0; i < edges; i++){
		cin >> src >> dest;
		g[src].push_back(dest);
	}
	
	vector<bool> visited(nodes,false);

	stack<int> st;
	for(int i = 0; i < nodes; i++)
		if(!visited[i])
				dfs(g,i,visited,st);

	//upto here it is same as topological sort algorithm...				
	
	//a new graph , graph gi is invert of graph g
	vector<int> gi[nodes];

	for(int i = 0; i < nodes; i++){
		for(auto it : g[i]){
			gi[it].push_back(i);
		}
	}
	
	//all vertices of gi are unvisited...
	for(int i = 0; i < nodes; i++) visited[i] = false;

	while(!st.empty()){

		//use dfs using stack top on gi...
		int top = st.top();
		st.pop();
		
		//only call dfs for unvisited node, for others just pop only...
		if(!visited[top]){
			dfs2(gi,top,visited);	//prints all connected components using dfs...
			cout << endl;
		}
	}
			
	return 0;
}

