//Singly linked list:
#include<iostream>
using namespace std;

struct link{
	int data;
	link *next;
};

link * head = NULL;

void InsertAtBeg(){
	int data;
	cout << "\nEnter data:\t";
	cin >> data;
	link * p = new link();
	p->data = data;
	p->next = head;
	head = p;
	cout << "\n***Success***\n";
}

void InsertAtEnd(){
	int data;
    cout << "\nEnter data:\t";
    cin >> data;
    link * p = new link();
    p->data = data;
    p->next = NULL;
    if(head == NULL){
    	head = p;
	}
	else{
		link * q = head;
		while(q->next != NULL){
			q = q->next;
		}
		q->next = p;
	}
	cout << "\n***Success***\n";
}

void Traverse(){
	link * p = head;
	if(head == NULL){
		cout << "\nEmpty list\n";
		return;
	}
	cout << "\nThe elements are listed below:\n";
	int index = 0;
	while(p != NULL){
		cout << index++ <<". " << p->data << endl;
		p = p->next;
	}
	cout << "\n***Success***\n";
}

void DeleteBeg(){
   if(head == NULL){
   	cout << "\nEmpty list\n";
   	return ;
   }
   else{
   	link * p = head;
   	head = head->next;
   	cout << "\nSuccessfully deleted " << p->data << endl;
   	delete p;
   }
}

void  DeleteEnd(){
	if(head == NULL){
		cout << "\n Empty list\n";
		return ;
	}
	else if(head->next == NULL){
	   link * p = head;
	   head = NULL;
	   	delete p;
	}
	else{
		link *p , *q;
		p = head;
		q = head->next;
		while(q->next != NULL){
			p = q;
			q = q->next;
		}
		p->next = NULL;
		cout << "\nSuccessfully deleted " << q->data << endl;
		delete q;
	}
}

void InsertSpec(){
	int pos;
	cout << "Enter the position to insert\n";
	cin >> pos;
	link *p;
	p = head;
	if(pos == 0){
		InsertAtBeg();
		return;
	}
	for(int i = 0; i < pos - 1; i++){
		if(p == NULL) {
			cout << "invalid" << endl;
			 return;
		}
		p = p->next;
	}
	link * q = new link();
    cout << "ENter data " ;
    cin >> q->data;
    q->next = p->next;
    p->next = q;
    cout << "\n***Success***\n";
}

void DeleteSpec(){
	if(head == NULL){
		cout << "\n Empty list\n";
		return ;
	}
	link *current , *previous;
	int pos;
	cout << "Enter the position to delete" << endl;
	cin >> pos;
	if(pos == 0){
		DeleteBeg();
		return;
	}
	current = head;
	for(int i = 0; i < pos; i++){
		if(current == NULL){
			cout << "Invalid range" << endl;
			return;
		}
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
	cout << "\nSuccessfully deleted " << current->data << endl;
	delete current;
}

int main(){
	cout << "Simulating a list through singly linked list\n";
	do{
		cout << "\n";
		int opt;
		cout << "Menu:";
		cout << "\n1 Insert at beginning"
		     << "\n2 Insert at end"
		     << "\n3 Traverse"
		     << "\n4 Exit"
		     << "\n5 Delete 1 item from beginning"
		     << "\n6 Delete 1 item from end"
		     << "\n7 Delete 1 item from specific position"
		     << "\n8 Insert at Specific position";
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
			default:
				cout << "\nEnter valid option.";
		}
	}while(true);
	return 0;
}
