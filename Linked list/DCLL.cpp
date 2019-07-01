//Simulating a list through doubly circular linked list
#include<iostream>
using namespace std;

struct link{
	link * prev;
	link * next;
	string data;  
};

link * start = NULL;
link * last  = NULL;

void Clear(){
	link *p = start;
	do{ 
	    if(start == last){
		start = last = NULL;
		return;
    	}
	    p = start;
	    start = start->next;
	    last->next = start;
	    delete p;
	}while(p != start);
}

void InsertAtBeg(){
	link * p = new link();
	cout << "\nEnter data:";
	cin.ignore();
	getline(cin,p->data);
	if(start == NULL){
		start = p;
		last = p;
		p->prev = p;  //start->prev = last
		p->next = p;  //last->next = start
	}
	else{
		p->next = start;
		p->prev = last;
		start->prev = p;
		last->next = p;
		start = p;
	}
	cout << "\n***Sucessfully inserted***\n";
}

void Traverse(){
	if(start == NULL){
		cout << "\n***Empty list***\n";
		return;
	}
	cout << "\nThe elements of lists are:\n";
	int i = 0;
	link * p = start;
	do{
		cout << i++ << ". " << p->data << endl;
		p = p->next;
	}while(p != start);
}

void Count(){
	int i = 0;
	link * p = start;
	if(start == NULL){
		cout << 0 << endl;
		return;
	}
	do{
		i++;
		p = p->next;
	}while(p != start);
	cout << i << endl;
}

void InsertAtEnd(){
    link * p  = new link();
    cout << "\nEnter data:";
    cin.ignore();
	getline(cin,p->data);
    if(last == NULL){
    	start = last = p;
    	p->next = p->prev = p;
	}
	else{
		p->next = start;
		p->prev = last;
		last->next = p;
		start->prev = p;
		last = p;
	}
	cout << "\n***Sucessfully inserted***\n";
}

void DeleteBeg(){
	if(start == NULL){
		cout << "\n***Empty list***\n";
		return;
	}
	else if(start == last){
		cout << "\nDeleted item is " << start->data << endl;
		start = NULL;
		last = NULL;
	}
	else{
	link *p = start;
	start = start->next;
	start->prev = last;
    last->next = start;
    cout << "\nDeleted item is " << p->data << endl;
    delete p;
	}
}

void DeleteEnd(){
	if(start == NULL){
	  cout << "\n***Empty list***\n";
	  return;
	}
	else if(start == last){
		cout << "\nDeleted item is " << start->data << endl;
		start = NULL;
		last  = NULL;
	}
	else{
		link *p = last;
		last = last->prev;
		last->next = start;
		start->prev = last;
		cout << "\nDeleted item is " << p->data << endl;
	}
}

void Reverse(){
   if(last == NULL){
   	cout << "\n***Empty list***\n";
   	return;
   }
   int i = 0;
   cout << "\nReversed version of the list is:\n";
   link * p = last;
   do{
   	cout << i++ << " . " << p->data << endl;
   	p = p->prev;
   }while(p != last);
}

void InsertSpec(){
	link *p = new link();
	int pos;
	cout << "\nEnter position : ";
	cin >> pos;
	if(pos == 0){
		InsertAtBeg();
		return;
	}
	link * q = start;
	if(q == NULL){
		cout << "\nInvalid position\n";
		return;
	}
	for(int i = 0; i < pos - 1; i++){
		if(q == start && i != 0){
			cout << "\nInvalid position\n";
			return;
		}
		q = q->next;
	}
	cout << "\nEnter data : ";
	cin.ignore();
	getline(cin,p->data);
	
	p->prev = q;
	p->next =q->next;
	if(q != last){
		q->next->prev = p;
	}
	else{
		last  = p;
		start->prev = last;
	}
	
	q->next = p;
	
   cout << "\n***Sucessfully inserted***\n";
}

void DeleteSpec(){
	if(start == NULL){
		cout << "\n***Empty list***\n";
		return;
	}
	int pos;
	cout << "\nEnter position:";
	cin >> pos;
	if(pos == 0){
		DeleteBeg();
		return;
	}
	link * q = start;
	for(int i = 0; i < pos; i++){
		if(i != 0 && q == start){
			cout << "\nInvalid range\n";
			return;
		}
		q = q->next;
	}
	q->prev->next = q->next;
	if(q != last){
	q->next->prev = q->prev;	
	}
	else{
		last = q->prev;
		start->prev = last;
	}
	cout << "\nDeleted item is " << q->data << endl;
	delete q;
}

int main(){
	cout << "\nSimulating a list through a doubly circular linked list\n";
	    do{
		int opt;
		cout << "\nMenu:" << endl <<"`````";
		cout << "\n1  <- Insert 1 item at beginning"
		     << "\n2  <- Insert 1 item at end"
		     << "\n3  <- Insert 1 item at Specific position"
		     << "\n4  <- Traverse list"
		     << "\n5  <- Delete 1 item from beginning"
		     << "\n6  <- Delete 1 item from end"
		     << "\n7  <- Delete 1 item from specific position"
		     << "\n8  <- Reversely display the list"
		     << "\n9  <- Count items"
		     << "\n10 <- Clear list"
		     << "\n11 <- Exit";
		cout << "\n\nEnter a option:\t";
		cin >> opt;
		switch(opt){
			case 1: InsertAtBeg();
			break;
			case 2: InsertAtEnd();
			break;
			case 3: InsertSpec();
			break;
			case 4: Traverse();
			break;
			case 5: DeleteBeg();
			break;
			case 6: DeleteEnd();
			break;
			case 7: DeleteSpec();
			break;
            case 8: Reverse();
            break;
            case 9: 
			cout << "\nNumber of items = "; Count();
            break;
            case 10: 
			Clear();
			cout << "\n***List cleared***\n";
			break;
            case 11: exit(1);
			break;
			default:
				cout << "\nEnter valid option.";
		}
	}while(true);
	return 0;
}

