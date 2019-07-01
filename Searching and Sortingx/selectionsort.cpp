#include<iostream>

using namespace std;

void selection_sort(int [], int);

int main(){
	int arr[] = {5,4,1,7,9,10};
	int size  = sizeof(arr)/sizeof(arr[0]);
	selection_sort(arr,size);
	for(int i = 0; i < size; i++){
		cout << arr[i] << ' ';
	}
	return 0;
}

void selection_sort(int arr[] , int size){
	int min , min_index;
	for(int i = 0; i < size-1; i++){
		for(int j = i+1; j < size; j++){
			if(arr[i] > arr[j]){
			   swap(arr[i],arr[j]);	
			}
		}
	}
}
