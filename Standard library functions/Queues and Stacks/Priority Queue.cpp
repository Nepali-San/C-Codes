/*
A priority queue is just a regular container, such as a vector, which is 
sorted based on a certain criterion each time a new item is added. So, if a
vector is used internally to store the elements, that means that particular 
priority queue has all the properties of a vector
*/

#include<iostream>
#include<queue>
using namespace std;

void show(priority_queue<int,vector<int>,greater<int> > pq){
	
	while(!pq.empty()){
		cout << pq.top() << " " ;
		pq.pop();
	}
}

int main(){
	
//	vector is used to store the data and is sorted by functor (function object)
	
	priority_queue<int,vector<int>,greater<int> > pq;
	pq.push(10);	 pq.push(5);   pq.push(1);
	pq.push(20);     pq.push(18);
	
	cout << "Size of queue : " << pq.size() << endl; 
	
	cout << "The priority queue is\n";
	show(pq);
	
	const int *vec = &(pq.top());

	cout << endl << "The intial vector used for priority queue is" << endl;
	for(int i = 0 ; i < pq.size(); i++)
	cout << vec[i] << " ";
	
	return 0;
}
