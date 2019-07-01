#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
	return a.second < b.second;
}

int main(){
	int n;
	cin >> n;
	pair<int,int> p[n];
	for(int i = 0; i < n; i++){
		int start , end;
		cin >> start >> end;
		p[i] = make_pair(start,end);
	}
	
	sort(p,p+n,compare);  //this sorts the pair with end time
	
	int k = 0;
	cout << p[k].first << "  " << p[k].second << endl;
	
	for(int i = 1; i < n; i++){
		if(p[k].second <= p[i].first){
			cout << p[i].first << "  " << p[i].second << endl;			
			k  = i;
		}
	}

	return 0;
}
