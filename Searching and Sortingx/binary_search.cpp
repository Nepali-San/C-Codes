#include <bits/stdc++.h>

#define ull                          unsigned long long int
#define endl                         '\n'
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

ull prices[100009];
int n;

using namespace std;

int bin_search(ull spend){
	int left = 0; 
	int right = n-1;
	int mid;
	int idx = -1;
	
	while(left <= right){		

		mid = left + (right-left)/2;

	 	if(prices[mid] <= spend){				
			idx = mid;
			left = mid+1;
		}
		else{			
			right = mid -1;
		}	
	}

	return idx;
}

int main() {
	ALLONS_Y;
	
	int q;
	cin >> n;  //no. of elements in array...

	for(int i = 0; i<n; i++) cin >> prices[i]; //array on which we search...

	sort(prices,prices+n); //sort the array...

	cin >> q;   //no. of elements to search...
	ull today;	//variable for element to search...
	for(int i = 0; i < q; i++){
		cin >> today;  //search this element
		cout << bin_search(today)+1 << endl;   //custom method to get upper_bound
		cout << upper_bound(prices,prices+n,today); //library method to get upper_bound
		cout << lower_bound(prices,prices+n,today); //library method to get lower_bound
	}
			
	return 0;
}

