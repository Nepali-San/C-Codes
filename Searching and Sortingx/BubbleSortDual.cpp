//To put the records (name) and keys (weight) in order with respect to keys...

#include<iostream>
#include<vector>
#include<string>

using namespace std;

void bubble_sort(int wt[], string name[],int size){
	for(int i = 0; i < size-1; i++){
		for(int j = 0; j < size-i-1; j++){
			if(wt[j] > wt[j+1]){
				swap(wt[j],wt[j+1]);
				swap(name[j],name[j+1]);
			}
		}
		
	}
}

int main(){
	int wt[5];
	string name[5];
	int size = 5;
	cout << "Enter the 5 names and their weights respectively :\n";
	cout << "\n\nName\t\t" << "Weight\n";
	for(int i = 0; i < 5; i++){
		cin >> name[i] ;
		cin >> wt[i]   ;
	}
	bubble_sort(wt,name,size);
	cout << "\n\nAfter sorting:\n\n";
	cout << "\n\nName\t\t" << "Weight\n"; 
	for(int i = 0; i < 5; i++){
		cout << name[i] << "\t\t" << wt[i] << endl;
	}
	return 0;
}
