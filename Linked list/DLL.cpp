//Simulating a list through doubly linked list
#include<iostream>
using namespace std;

struct link{
	link * prev;
	link * next;
	int data;
};

link * start = NULL;

void InsertAtBeg(){
	link * p  = new link();
	cout << "\nEnter data: ";
	cin >> p->data;
	p->prev = NULL;
	p->next = start;
	
	if(start != NULL)
	start->prev = p;
	
	start = p;
	cout << "\n***Successfully inserted***\n";
}

void Traverse(){
	link * p = start;
	if(start == NULL){
		cout << "\nEmpty list\n";
		return;
	}
	int i = 0;
	while(p != NULL){
		cout << i++ << ". " << p->data << endl;
		p = p->next;
	}
}

void InsertAtEnd(){
	link * p = new link();
	cout << "\nEnter data ";
	cin >> p->data;
	link * q = start;
	if(start == NULL){
		start = p;
		p->next = NULL;
		p->prev = NULL;
		return;
	}
	while(q->next != NULL){
		q = q->next;
	}
	p->next = NULL;
	q->next = p;
	p->prev = q;
	cout << "\n***Successfully inserted***\n";
}

void DeleteBeg(){
	if(start == NULL){
		cout << "\nEmpty list\n";
		return ;
	}
	link * p = start;
	start = start->next;
	if(start != NULL)
	start->prev = NULL;
	cout << "\nSuccessfully deleted " << p->data << endl;
	delete p;
}

void DeleteEnd(){
	link * q = start;
	if(start == NULL){
		cout << "\nEmpty list\n";
		return;
	}
	while(q->next != NULL){
		q = q->next;
	}
	if(q->prev != NULL)
	(q->prev)->next = NULL;
	cout << "\nSuccessfully deleted " << q->data << endl;
	delete q;
}

void Reverse(){
	if(start == NULL){
		cout << "\nEmpty list\n";
		return;
	}
	cout << "\nIn reverse order:\n";
	link *  p = start;
	while(p->next != NULL){
		p = p->next;
	}
	while(p != NULL){
		cout << p->data << endl;
		p = p->prev;
	}
}

void InsertSpec(){
    int pos;
    cout << "\nEnter position :";
	cin >> pos;
	if(pos == 0){
		InsertAtBeg();
		return;
	}
	link * p = new link();
	
	link *q = start;
	for(int i = 0; i < pos - 1; i++){
		if(q == NULL){
			cout << "\nInvalid position\n";
			return;
		}
		q = q->next;
	}
	
	cout << "\nEnter data : ";
	cin >> p->data;
	
	p->prev = q;
	p->next = q->next;
	q->next->prev = p;
	q->next = p;
	cout << "\n***Successfully inserted***\n";
}

void DeleteSpec(){
	if(start == NULL){
		cout << "\nEmpty list\n";
		return;
	}
    int pos;
    cout << "\nEnter position:";
    cin >> pos;
    if(pos == 0){
    	DeleteBeg();
    	return;
	}
	link * p = start;
	for(int i = 0; i < pos; i++){
		if(p == NULL){
			cout << "\nInvalid range\n";
			return;
		}
		p = p->next;
	}
	if(p->prev != NULL)
	p->prev->next = p->next;
	if(p->next != NULL)
	p->next->prev = p->prev;
	cout << "\nSuccessfully deleted " << p->data << endl;
	delete p;
}

int main(){
	cout << "\nSimulating a list through a doubly linked list\n";
	    do{
		int opt;
		cout << "\nMenu:";
		cout << "\n1 Insert 1 item at beginning"
		     << "\n2 Insert 1 item at end"
		     << "\n3 Traverse list"
		     << "\n4 Exit"
		     << "\n5 Delete 1 item from beginning"
		     << "\n6 Delete 1 item from end"
		     << "\n7 Delete 1 item from specific position"
		     << "\n8 Insert 1 item at Specific position"
		     << "\n9 Reverse display the list";
		cout << "\n\nEnter a option:\t";
		cin >> opt;
		switch(opt){
			case 1: InsertAtBeg();
			break;
			case 2: InsertAtEnd();
			break;
			case 3: Traverse();
			break;
			case 4: exit(1);
			break;
			case 5: DeleteBeg();
			break;
			case 6: DeleteEnd();
			break;
			case 7: DeleteSpec();
			break;
			case 8: InsertSpec();
			break;
            case 9: Reverse();
            break;
			default:
				cout << "\nEnter valid option.";
		}
	}while(true);
	return 0;
}
