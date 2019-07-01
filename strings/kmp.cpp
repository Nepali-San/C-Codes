#include <bits/stdc++.h>

#define ULL unsigned long long
#define LL long long
#define endl '\n'
#define ALL(v) begin(v), end(v)
#define CONTAINS(container, value) container.find(value) != container.end()

using namespace std;

void kmp(string ,string);
vector<int> compute_lps(string);

int main() {

	string txt,pat;

	cin >> txt;
	cin >> pat;

	kmp(txt,pat);
		
	return 0;
}

void kmp(string txt,string pat){
	int n = txt.size();
	int m = pat.size();
	
	vector<int> lps = compute_lps(pat);

	int i = 0,j = 0;
	while(i < n){
		if(pat[j] == txt[i]){
			i++;
			j++;			
		}
		if(j == m){
			cout << "found at " << i - j << endl;
			j = lps[j-1];
		}
		else if(i < n && txt[i] != pat[j]){
			if(j != 0) j = lps[j-1];
			else	   i++;			
		}
	}
}

vector<int> compute_lps(string pat){
	int m = pat.size();

	vector<int> lps(m);
	int len = 0, i =1;
	lps[0] = 0;
	while(i < m){
		if(pat[len] == pat[i]){
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if(len != 0){
				len = lps[len-1];
			}else{
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}
