#include <bits/stdc++.h>

using namespace std;

void sorter() {
    vector<int> grida(5);
    for(int i = 0; i < 5; i++){
        grida[i] = i;
	}
    sort(grida.begin(),grida.end(),greater<int>());
    for(int i = 0; i < 5; i++){
    	cout << grida[i];
	}
   
}

int main() {
    sorter();
    return 0;
}
