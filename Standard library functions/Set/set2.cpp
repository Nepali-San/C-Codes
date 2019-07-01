// Unordered sets uses hash tables to store data
// unordered multiset allows multiples data
#include<iostream>
#include<unordered_set>

using namespace std;

int main(){
    cout << "\n\nUnordered set\n\n";
	
	unordered_set<int> st2;
	
	for(int j = 0; j <= 4; j++){
		st2.insert(j+10);
	}
	
	for(auto it = st2.begin(); it != st2.end(); it++){
		cout << *it << endl;
	}	
}

