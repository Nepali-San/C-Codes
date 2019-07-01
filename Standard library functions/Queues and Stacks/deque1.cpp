//Deques unlike vectors they also have push_front ,pop_front and back ones too
#include<iostream>
#include<deque>

using namespace std;

void print_queue(deque<int> dq);

int main(){
	//Intialization of deque...
	deque<int> dq1(5,3); //intially 5 locations initialized to 3
	deque<int> dq2(4);  //intially 4 locations intialized to 0
	deque<int> dq3;
	
	int el1 = dq1.at(1); //similar as el = dq1[1];
	int el2 = dq2[2];
	cout << "dq1[1] = " << el1 << "  dq2[2] = " << el2 << endl;
	
	bool flag = dq3.empty();
	cout << "flag is " << flag << " for dq3 (1 if empty else 0)"<< endl;
	
	dq3.push_back(10); dq3.push_back(20); dq3.push_back(30);
	cout << "After push back 10,20,30 on dq3\n";
	print_queue(dq3);
	
	dq3.pop_front();
	cout << "After pop front on dq3\n";
	print_queue(dq3);
	
	dq3.pop_back();
	cout << "After pop back on dq3\n";
	print_queue(dq3);
	
	dq3.push_front(35);
	cout << "After push_front(35) on dq3\n";
	print_queue(dq3);
	
	cout << endl << dq3.back() << endl;  //rear element of queue
	
	cout << dq3.front(); //front element of queue

	
	return 0;
}

void print_queue(deque<int> dq){
	for(int i = 0; i < dq.size(); i++){
		cout << dq.at(i) << ' ';
	}
	cout << endl;
}
