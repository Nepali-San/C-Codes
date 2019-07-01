#include<iostream>

using namespace std;

void insertion_sort(int arr[],int size);
void print(int arr[],int size){
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
}

int main(){
	int arr[] = {1,4,3,10};
	int size  = sizeof(arr)/sizeof(arr[0]);
	insertion_sort(arr,size);
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	return 0;
}

void insertion_sort(int arr[], int size){
	int value , index;
	for(int i = 1; i < size; i++){
		value = arr[i];
	    index = i - 1;
	    while(index >= 0 && value < arr[index]){
	    	arr[index + 1] = arr[index];
	    	index-- ;
	    }
		arr[index+1] = value;
	}
}
