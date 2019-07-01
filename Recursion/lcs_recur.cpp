//longest common subsequence , top down recursion with memoization table...

#include <bits/stdc++.h>

using namespace std;

string s1,s2;
vector<vector<int> > table(100,vector<int>(100,-1));


int lcs(int i,int j){

	if(table[i][j] != -1) return table[i][j];

	if(s1[i] == '\0' || s2[j] == '\0') return 0;	
    else if(s1[i] == s2[j]){
		table[i][j] =  1+lcs(i+1,j+1);
		return table[i][j];
	}
	else{ 
		table[i][j] =   max(lcs(i+1,j),lcs(i,j+1));
		return table[i][j];
	}
}

int main() {
	
	cin >> s1 >> s2;
	
	cout << lcs(0,0) << endl;

	return 0;
}

