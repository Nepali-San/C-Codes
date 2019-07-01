//Topological sorting using DFS
#include<iostream>
#include<stack>
#include<list>
using namespace std;

void topological_sort(list<int> ls[],bool visited[],int src,stack<int> &st){
	visited[src] = true;
	list<int>::iterator it;
	for(it = ls[src].begin(); it != ls[src].end(); it++){
		if(!visited[*it]){
			topological_sort(ls,visited,*it,st);
		}
	}
	
	st.push(src);

}

int main(){
	int v,e;
	cin >> v >> e;
	list<int> ls[v+1];
	for(int i = 0; i < e; i++){
		int a , b; 
		cin >> a >> b;
		ls[a].push_back(b);
	}
	stack<int> st;
	
	bool visited[v+1];
	fill(visited,visited+v+1,false);
	
	for(int i = 1; i <= v; i++)
	if(!visited[i])
	topological_sort(ls,visited,i,st);
	
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
	
}
