//Detecting loop in linked list using set(hash table) & Floyd's cycle finding algorithm

/*
Alternative method:
less efficient method (uses more memory) :
-> put a field(visit) in node
-> initialize all isit field to false
-> visit the node one by one
-> if visit field is false change it to true
-> if already true then loop detected
*/

#include<iostream>
#include<unordered_set>
using namespace std;

struct node{
	int data;
	node * next;
};

void insert(int data, node** head_r){
	node * p = new node();
	p->data = data;
	p->next = *head_r;
	*head_r = p;
}

//Hash table method
bool detectLoop(node* head){
	node *p = head;
	unordered_set<node * > s;
	while(p != NULL){
		if(s.find(p) != s.end()) return true;  //if already inserted
		s.insert(p);
		p = p->next;
	}
	return false;
}

//Floyd's cycle finding algorithm
bool detectLoop2(node * head){
	node *slow , *fast;     //uses fast pointer and slow pointer
	fast = head;
	slow = head;
	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) return true;
	}
	return false;
}

int main(){
	node * head = NULL;
	
	insert(10,&head);
	insert(20,&head);
	insert(30,&head);
	insert(40,&head);
	insert(50,&head);
	
	head->next->next->next->next = head;  //Creating a loop in list
	
	if(detectLoop2(head)){
		cout << "Loop found" << endl;
	}
	else cout << "No loop" << endl;
	
	return 0;
}
