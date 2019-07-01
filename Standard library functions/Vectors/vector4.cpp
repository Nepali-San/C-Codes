#include<iostream>
#include<vector>
#include<algorithm>  //for library swap function

using namespace std;

void print_vector(vector<int> arr){
	for(int i = 0;i < arr.size(); i++){
		cout << arr[i] << ' ';
	}
	cout << endl;
}

//void sorting(vector<int> & arr , int n){
//	int temp;
//	for(int i = 0 ; i < n-1; i++){
//		for(int j = i+1; j < n;j++){
//			if(arr[i] > arr[j]){
//				temp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = temp;
//			}
//		}
//	
//	}
//	print_vector(arr);
//}

int main(){
	int n , a;
	int i = 0;
	cout << "Enter size of vector" << endl;
	cin >> n;
	vector<int> vet(n);
	for(int i = 0; i < n; i++){
	    cout << "Enter a number" << endl;
     	cin >> vet[i];
    }

	bool flag = true;
	
	for(int i = 0; i < vet.size() - 1; i++){
		if(vet[i] > vet[i+1]){
		   flag = false;
		   break;
		}
	}
	
	if(flag == false){
		cout << "Array is unsorted" << endl;
		//sorting(vet,n);
		sort(vet.begin(),vet.end());
		cout << "The sorted vector is:\n";
		for(int i = 0; i < n; i++){
			cout << vet[i] << endl;
		}
	}
	else{
		cout << "Array is sorted" << endl;
	}
}
	
