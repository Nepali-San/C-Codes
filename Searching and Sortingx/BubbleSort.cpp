#include<iostream>
#include<algorithm>

using namespace std;

void bubble_sort(int a[],int n){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-i-1; j++){
			if(a[j] > a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}

int main(){
	int arr[] = {5,4,1,7,9,10};
	int size  = sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr,size);
	for(int i = 0; i < size; i++){
		cout << arr[i] << ' ';
	}
	return 0;
}
