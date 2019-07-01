//find the all possible comibinations with given n and r...

#include <bits/stdc++.h>

#define ULL unsigned long long
#define LL long long
#define endl '\n'
#define ALL(v) begin(v), end(v)
#define CONTAINS(container, value) container.find(value) != container.end()

using namespace std;
int c;

void get_combinations(int n, int a, int r,vector<int> vec){

	vec.push_back(a);

	if(vec.size() == r){
		for(int i = 0; i < r; i++) cout << vec[i] << "  ";
		cout << endl;
		c++;
	}
	else{
		for(int i = a+1; i <= n; i++){
			get_combinations(n,i,r,vec);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,r;
	cin >> n >> r;
    
	if(n < r){
		cout << "improper values !!!" << endl;
		exit(0);
	}

	vector<int> vec;
	
	for(int i = 1; i <= n-r+1; i++)
		get_combinations(n,i,r,vec);
	
	string v;
    if(c != 1) v = "are";
	else v = "is";

	cout << "There " << v << " "  << c << " combination." << endl;
		
	return 0;
}

