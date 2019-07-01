//Singly circular linked list
#include<iostream>
using namespace std;

struct link{
	link * next;
	int data;
};

link * start = NULL;
link * last   = NULL;

void InsertAtBeg(){
	link * p = new link();
	cout << "\nEnter the data: ";
	cin >> p->data;
	if(start == NULL){
	  start = p;
	  last  = p;
      p->next = last;
	}
	else{
		p->next = start;
		start = p;
		last->next = start;
	}
	cout << "\n***Successfully Inserted***\n";
}

void InsertAtEnd(){
	link * p = new link();
	cout << "\nEnter data: ";
	cin >> p->data;
	if(start == NULL){
		start = p;
		last = p;
		p->next = p;
	}
	else{
		last->next = p;
		p->next = start; 
	    last = p;
	}
	cout << "\n***Successfully Inserted***\n";
}

void Traverse(){
	if(start == NULL ){
		cout << "\nEmpty list\n";
		return;
	}
	cout << "\nThe elements of list are:\n";
	link * p = start;
	int index = 0;
	do{
		cout << index++ << ". " << p->data << endl;
		p = p->next;
	}while(p != start);
}

void DeleteBeg(){
	link * p = start;
	if(start == NULL){
		cout << "\nEmpty list\n";
		return;
	}
	else if(start == last){
		start = NULL;
		last = NULL;
		cout << "\nSucessfully deleted " << p->data << endl;
		delete p;
	}
	else{
	  start = start->next;
	  last->next = start;
	  cout << "\nSucessfully deleted " << p->data << endl;
	  delete p;
	}
}

void DeleteEnd(){
	link * p = last;
	if(p == NULL){
		cout << "\nEmpty list\n";
		return;
	}
	else if( start == last){
		start = NULL;
		last = NULL;
		cout << "\nSuccessfully deleted " << p->data << endl;
		delete p;
	}
	else{
		link * q = start;
		while(q->next != last){
			q = q->next;
		}
		last = q;
		last->next = start;
		cout << "\nSuccessfully deleted " << p->data << endl;
		delete p;
	}
}

void InsertSpec(){
   int pos;
   cout << "\nEnter the position : ";
   cin >> pos;
   if(pos == 0){
   	InsertAtBeg();
   	return;
   }	
   else{
   	link * p = new link();
   	link * q = start;
   	if(q == NULL){
   		cout << "\nInvalid range\n";
   		return;
	}
   	cout << "\nEnter data: ";
   	cin >> p->data;
   	for(int i = 0; i < pos - 1; i++){
   		if(q == start && i != 0){
   			cout << "\nInvalid range\n";
   			return;
		   }
   		q = q->next;
	   }
	   p->next = q->next;
	   q->next = p;
	   if(p->next == start) {
	   	last = p;
	   }
   }
   cout << "\n***Successfully Inserted***\n";
}

void DeleteSpec(){
	if(start == NULL){
		cout << "\nEmpty list\n";
		return;
	}
	link *prev , *current;
	int pos;
	cout << "\nEnter the position: ";
	cin >> pos;
	if(pos == 0){
		DeleteBeg();
		return;
	}
	current = start;
	for(int i = 0; i < pos; i++){
		prev = current;
		current = current->next;
		if(current == start){
			cout << "\nInvalid position\n";
			return;
		}
	}
	prev->next = current->next;
	if(current == last) {
		last = prev;
	}
	cout << "\nSuccessfully deleted " << current->data << endl;
	delete current;
}

int main(){
	    cout << "\nSimulating a list through a Singly circular linked list\n";
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
		     << "\n8 Insert 1 item at Specific position";
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
