//Kruskal algo. using disjoint set, union by rank
//to find the minimum spanning tree.

#include <bits/stdc++.h>

#define  mp  make_pair

using namespace std;

int find(int src,int parent[]){
	if(src == parent[src]) return src;
	parent[src] = find(parent[src],parent);
	return parent[src];	
}

void unite(int src,int dest,int parent[],int rank[]){
	src = find(src,parent);
	dest = find(dest,parent);

	if(rank[src] > rank[dest]){
		parent[dest] = src;
	}
	else if(rank[dest] > rank[src]){
		parent[src] = dest;
	}else{
		parent[dest] = src;
		rank[src]++;
	}
}

void kruskal(pair<int,pair<int,int> > p[],int v,int e){
	
	int parent[v],rank[v];
	for(int i = 0; i < v; i++){
		parent[i] = i;
		rank[i] = 0;
	}
	
	int vi = 0,ei = 0;
	int min_wt = 0;
	while(vi < v-1){
		int src = p[ei].second.first;
		int dest = p[ei].second.second;
		int wt = p[ei].first;

		if(find(src,parent) != find(dest,parent)){
			unite(src,dest,parent,rank);
			min_wt += wt;
			vi++;
		}

		ei++;
	}

	cout << min_wt << endl;
	
}

int main() {
	
	int v,e;
	cin >> v >> e;

	pair<int,pair<int,int>> p[e];
	
	int src,dest,wt;
	for(int i = 0; i < e; i++){
		cin >> src >> dest >> wt;
		p[i] = mp(wt,mp(src-1,dest-1));
	}

	sort(p,p+e);

	kruskal(p,v,e);
		
	return 0;
}

