//naive pattern searching...
#include <bits/stdc++.h>

#define ULL unsigned long long
#define LL long long
#define endl '\n'
#define ALL(v) begin(v), end(v)
#define CONTAINS(container, value) container.find(value) != container.end()

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string txt,pat;
	cin >> txt >> pat;

	int j;
	for(int i = 0; i <= txt.size()-pat.size(); i++){

		for(j = 0; j < pat.size(); j++){
			if(txt[i+j] != pat[j]) break;
		}
		
		if(j == pat.size()) cout << "found" << endl;	
	}
		
	return 0;
}

