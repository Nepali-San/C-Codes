#include<iostream>
#include<vector>

using namespace std;

void print_vector(vector<int> arr){
	for(int i = 0;i < arr.size(); i++){
		cout << arr[i] << '\t';
	}
	cout << endl;
}
int main(){
	vector<int> arr;  //vector are like arrays and uses larger memory and is dynamic
	arr.push_back(10);  //add a integer location and puts 10 in that location;
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);
	print_vector(arr);
	
	arr.pop_back();     //Pops the last added integer location
	print_vector(arr);
	
	int el = arr.at(1); // or el = arr[1];
	cout << el;
	
	return 0;
}

