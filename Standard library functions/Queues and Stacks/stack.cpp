#include<iostream>
#include<stack>

using namespace std;

int main(){
	stack<int> st;
	
	if(st.empty()) cout << "Stack is empty\n";
	else           cout << "Stack is not empty\n";
	
	for(int i = 0; i < 5; i++){
		st.push(i);
	}
	
	while(!st.empty()){
		cout << "Size of stack is " << st.size() << endl;
		cout << "Top = " << st.top() << endl;
		st.pop();
    }
	return 0;
}
