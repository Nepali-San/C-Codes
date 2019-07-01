//Recursive approach to coin change problem...

#include <bits/stdc++.h>

#define ull                          unsigned long long int
#define ll                           long long int
#define endl                         '\n'
#define all(v)                       begin(v), end(v)
#define pb(x)                        push_back(x)
#define mp                           make_pair
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define contains(container, value)   container.find(value) != container.end()
#define rep(i,a,b)                   for(int i  = a; i < b; i++)

using namespace std;

ull find1(int n,int coins[],int k,int s_i){

	if(n == 0) return 1;
	if(n < 0)  return 0;

	ull sum = 0;
	for(int i = s_i; i < k; i++){
		sum += find1(n-coins[i],coins,k,i);
	}

	return sum;

}

ull find2(int sum,int arr[],int m){
	if(sum == 0) return 1;
	if(sum < 0) return 0;
	if(m <= 0 && sum > 0) return 0;

	return find2(sum,arr,m-1) + find2(sum-arr[m-1],arr,m);
}

int main() {
	
	int n,k;
	scanf("%d%d",&n,&k);

	int coins[k];

	for(int i = 0; i < k ;i++){
		scanf("%d",&coins[i]);
	}

	cout << find1(n,coins,k,0) << endl; //first approach...	
	cout << find2(n,coins,k) << endl;   //second approach...
		
	return 0;
}

