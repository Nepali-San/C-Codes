#include<bits/stdc++.h>
using namespace std;

int root(int x, int parent[]){
	if(parent[x] == -1){
		return x;
	}
	return root(parent[x],parent);
}

void Union(int src, int dest,int parent[]){
	int a = root(src,parent);
	int b = root(dest,parent);
	parent[a] = b;
}

int cycle_detector(pair<int,int> p[],int v, int e){
	int parent[v];
    fill(parent,parent+v,-1);
    
	for(int i = 0; i < e; i++){
		int source = p[i].first;
		int dest   = p[i].second;
		if(root(source,parent) == root(dest,parent)){
			return 1;
		}
		Union(source,dest,parent);
	}
	return 0;
}

int main(){
	int e;
	int v; 
	cin >> v;
	cin >> e;
	
	pair<int, int> p[e];
	for(int i = 0; i < e; i++){
		int src,dest;
		cin >> src >> dest;
		p[i] = make_pair(src,dest);
	}
	
	int status = cycle_detector(p,v,e);
	
	if(status) cout << "Cycle is detected" << endl;
	else cout << "Cycle is not detected" << endl;
	return 0;
}
