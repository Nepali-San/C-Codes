#include<iostream>

using namespace std;
int main(){
	int arr[10];
	int ar_size;
	cout << "Enter array size\t";
	cin >> ar_size;
	cout << "Enter the array \n";
	for(int i = 0; i < ar_size; i++){
		cin >> arr[i];
	}
	
	int num;
	cout << "Enter the number to search : ";
	cin >> num;
	bool check = true;
	for(int i = 0; i < ar_size/2; i++){
		if(arr[i] == num){
			cout << "Found at index " << i+1 << endl;
			check = false;
		}
		if(arr[ar_size-i] == num){
			cout << "Found at indes " << ar_size-i+1 << endl;
			check = false;
		}
	}
	if(check) cout << "Not found";
	return 0;
}
