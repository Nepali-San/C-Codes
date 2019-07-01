#include<iostream>
#include<list>
#include<queue>
using namespace std;

int main(){
	int v, e;
	cin >> v >> e;
	//vector< vector<int> > graph(v+1,vector<int>(v+1,0));
	list<int> lst[v+1];
	for(int i = 1; i <= e; i++){
		int a, b;
		cin >> a >> b;
		lst[a].push_back(b);
		lst[b].push_back(a);
	}

	//BFS logic

	int src = 1;
	queue<int> q;
    	vector<bool> visited(v+1,false);
	q.push(src);
	visited[src] = true;
	while(!q.empty()){
		int u = q.front();
		cout << u << " ";
		q.pop();
		for(list<int>::iterator it = lst[u].begin(); it != lst[u].end(); it++){
			if(!visited[*it]){
				q.push(*it);
				visited[*it] = true;
			}
		}
	}
	return 0;
}
