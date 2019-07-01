#include<iostream>
#include<list>

using namespace std;

void display(list<int> ls){
	for(list<int>::iterator it = ls.begin(); it != ls.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}
int main(){
	list<int> list1(5);
	int data; //to store the data into list
	
	//put data in list
	for(list<int>::iterator it = list1.begin(); it != list1.end();it++){
		cin >> data; //get data
		*it = data;  //put data
	}

	
	//basic operations
	list1.push_back(10);
	list1.push_front(12);
	list1.pop_front();

	list<int> list2(3,8);
	list1.merge(list2); //Merge the lists
	list1.sort();   //sorts the list
	list1.reverse();
 	display(list1);
	
	return 0;
}
