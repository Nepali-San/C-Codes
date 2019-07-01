#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
	int v;
	int e;
	int a, b;
	cin >> v >> e;
	stack<int> st;
	bool visited[v+1];
	fill(visited,visited+v+1,false);	
    vector<vector<int> > graph(v + 1, vector<int> (v + 1,0));
    
	for(int i = 0; i < e; i++){
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	
	}

     st.push(1);
     visited[1] = true;
     
     while(!st.empty()){
     	int a = st.top();
     	cout << a << " ";
     	st.pop();
     	for(int i = 1; i <= v; i++){
     		if(visited[i] == false && graph[a][i]){
     			st.push(i);
     			visited[i] = true;
			 }
		 }
	 }		
	return 0;
}
