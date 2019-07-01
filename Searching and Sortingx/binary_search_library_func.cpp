#include<iostream>
#include<algorithm>
using namespace std;

int my_func(int i , int j){  //it performs the same task as default sort
	return i < j;
}

int main(){
	int arr[10] = {1,5,8,5,31,5,45,54,78,88};
	
	sort(arr,arr+10);
	
	//my_func is not needed to write if our array is already a sorted one...
	if(binary_search(arr,arr+10,8,my_func)){
		cout << "found the number " << 8 << endl;
	}
	else cout << "Not found " << endl;
	
	int *low, *high;  //or use iterators if vector is used...
	low = lower_bound(arr,arr+10,5);
	high = upper_bound(arr,arr+10,5);
	
	cout << "lower index of 5 is " << (low - arr) << endl;
	cout << "upper index of 5 is " << (high - arr) << endl;
	
	// 1 ->5 5 5 ->8  31 45 54 78 88  pointing the lower and upper index as above... 
	
	//we may use (equal_range) instead of (lower_bound) and (upper_bound) as follow :
	
	pair<int *, int *> bounds;
	bounds = equal_range(arr,arr+10,5);
	cout << "lower index of 5 is " << (bounds.first - arr) << endl;
	cout << "upper index of 5 is " << (bounds.second - arr) << endl;
	
	return 0;
}
