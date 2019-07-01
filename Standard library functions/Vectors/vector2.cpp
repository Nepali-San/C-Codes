#include<iostream>
#include<vector>

using namespace std;

void print_vector(vector<int> arr){
	for(int i = 0;i < arr.size(); i++){
		cout << arr[i] << ' ';
	}
	cout << endl;
}
int main(){
	vector<int> arr(5,0);  //first five location intialized to 0
	cout << "arr :\n";
	print_vector(arr);
	
	vector<int> arr1(4,1);
	arr.insert(arr.end(),arr1.begin(),arr1.end()); //Inserts the arr1 (from begining to end) elements after the last location of arr 
	cout << "arr with arr1 inserted at last:\n";
	print_vector(arr);
	
	int arr2[5] = {1,2,3,4,5};
	arr.insert(arr.begin()+5,arr2,arr2+5); //to insert in middle of vector the elements of arr2
	cout << "arr with array (arr2) inserted in middle:\n";
	print_vector(arr);
	
	arr.erase(arr.end()-4,arr.end());
	cout << "Erased the last four elements of arr\n";
	print_vector(arr);
	
	cout << "size of arr = " << arr.size() << endl; //size of arr
	
	//Swapping vector ;
	vector<int> vector1(5,0); //Orignal vectors
	vector<int> vector2(5,1);
	
	cout << "vector1 : ";
	print_vector(vector1);
	cout << "vector2 : ";
	print_vector(vector2);
	
	vector1.swap(vector2);  //swaps vector1 and vector2;
	
	cout << "After swapping\n";
	cout << "vector1 : ";
	print_vector(vector1);
	cout << "vector2 : ";  //printing the vectors after swapping
	print_vector(vector2);
	
//	vector1.reverse(vector1.begin(),vector1.end()); //to reverse the vector within the range 
//	print_vector(vector1);
	
	vector1.clear(); //to clear the vector1
	
	cout << "\nAfter clear\n";
	print_vector(vector1);
	
	bool emp = vector1.empty(); //returns 1(true) if vector1 is empty
	cout << emp ;
	
	return 0;
}
