#include<iostream>
#include<vector>
using namespace std;
int v;

int minKey(bool visited[],int key[]){
	int min = INT_MAX, minidx = -1;
	for(int i = 0; i < v; i++){
		if(!visited[i] && key[i] <= min){
			min = key[i];
			minidx = i;
		}	
	}
	return minidx;
}

void dijkstra(vector<vector<int> >  &graph){
	int src = 0;
	bool visited[v];
	fill(visited,visited+v,false);
	int key[v];
	fill(key,key+v,INT_MAX);
	key[src] = 0;
	
	for(int i = 1; i < v - 1; i++){
		int u = minKey(visited,key);
		visited[u] = true;
		
		for(int j = 1; j < v; j++){
			if(graph[u][j] && !visited[j]  && key[u] != INT_MAX 
			                              && graph[u][j] + key[u] < key[j]){
				key[j] = graph[u][j] + key[u];
			}
		}
	}
	cout << endl;
	cout << "src" << "| dis" << endl;
	cout << "--------" << endl;
	for(int a = 0 ; a < v; a++){
		cout << " " << a << " | " << key[a] << endl;
	}
	
}

int main(){
	int e;
	cin >> v >> e;
	vector< vector<int> > graph(v,vector<int>(v,0));
	for(int i = 1; i <= e; i++){
		int src,dest,wt;
		cin >> src >> dest >> wt;
		graph[src][dest] = wt;
		graph[dest][src] = wt;
	}
	dijkstra(graph);
	return 0;
}
