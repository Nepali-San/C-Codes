#include<iostream>
#include<algorithm>

using namespace std;

int find(int src,int parent[]){
	if(src == parent[src]) return src;
	parent[src] = find(parent[src],parent);
	return parent[src];
}

void merge(int src, int dest , int parent[],int rank[]){
	
	int s = find(src,parent);
	int d = find(dest, parent);
	if(rank[s] > rank[d]) parent[d] = s;
	else if (rank[d] > rank[s]) parent[s] = d;
	else{
		rank[s]++;
		parent[d] = s;
	}
}


void krus(pair<long, pair<int,int> > p[],int &v, int &e){
	int parent[v];
	int rank[v];
	for(int i = 0; i < v; i++){ 
		parent[i] = i;
		rank[i] = 0;
	}
	long min_cost = 0;
	for(int i = 0; i < e; i++){
		int src = p[i].second.first;
		int dest = p[i].second.second;
		long wt = p[i].first;
		if(find(src,parent) != find(dest,parent)){
			min_cost+= wt;
			merge(src,dest,parent,rank);
		}
	}
	cout << min_cost << endl;
}

int main(){
	int v , e;
	cin >> v >> e;
	pair<long, pair<int,int> > p[e];
	for(int i = 0; i < e; i++){
		int src, dest; long wt;
		cin >> src >> dest >> wt;
		p[i] = make_pair(wt,make_pair(src-1,dest-1));
	}
	sort(p,p+e);
	krus(p,v,e);
	return 0;
}