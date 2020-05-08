#include <bits/stdc++.h>

using namespace std;
string s1,s2;

int lcs(){
	int table[s1.size()+1][s2.size()+1];

	for(int i= 0; i <= s1.size(); i++){
		for(int j = 0; j <= s2.size(); j++){

			if(i == 0 || j == 0){
				table[i][j] = 0;
			}

			else if(s1[i-1] == s2[j-1]){
				table[i][j] = table[i-1][j-1] + 1;
			}

			else{
				table[i][j] = max(table[i-1][j],table[i][j-1]);
			}
		}
	}

	return table[s1.size()][s2.size()];
}

int main() {
	
	cin >> s1 >> s2;

	cout << lcs() << endl;
	return 0;
}

