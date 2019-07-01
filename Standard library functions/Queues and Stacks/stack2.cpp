
#include<iostream>
#include<stack>

using namespace std;
int main(){
	stack<char> stk;
	char st[50] ;
	cin >> st ;
	char a;
	int i = 0;
	while(st[i] != '\0'){
	  switch(st[i]){
		case '(':
		    stk.push(st[i]);
		    i++;
		    break;
		case '{':
			stk.push(st[i]);
			i++;
			break;
		case '[':
			stk.push(st[i]);
			i++;
			break;
		case ']':
			a = stk.top();
			stk.pop();
			if(a == '['){
				i++;
			}
			else{
				cout << "Not correct\n";
				return 1;
			}
			break;
		case '}':
			a = stk.top();
			stk.pop();
			if(a == '{'){
				i++;
			}
			else{
				cout << "Not correct\n";
				return 1;
			}
			break;
		case ')':
			a = stk.top();
			stk.pop();
			if(a == '('){
				i++;
			}
			else{
				cout << "Not correct\n";
				return 1;
			}
			break;
		default :
			i++;
	}	
	}
	if(stk.empty()) cout << "correct \n";
	return 0;
}
