//Simulating a list through doubly circular linked list
#include<iostream>
using namespace std;


class link{
	private:
	link * prev;
	link * next;
	int data;
	
	link * start;
	link * last;
	public:
		link(){
		 	this->start = NULL;
		 	this->last = NULL;
		 }
		void clear();
		void push_front(int data);
		void push_back(int data);
		void display();
		void pop_front();
		void pop_back();
		void reverse();
		int length();
		
};


void link::clear(){
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

void link::push_front(int data){
	link * p = new link();
	p->data = data;
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
}

void link::display(){
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

int link::length(){
	int i = 0;
	link * p = start;
	if(start == NULL){
		cout << 0 << endl;
		return  i;
	}
	do{
		i++;
		p = p->next;
	}while(p != start);
	return i;
}

void link::push_back(int data){
    link * p  = new link();
    p->data = data;
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
}

void link::pop_front(){
	if(start == NULL){
		cout << "\n***Empty list***\n";
		return;
	}
	else if(start == last){
		start = NULL;
		last = NULL;
	}
	else{
	link *p = start;
	start = start->next;
	start->prev = last;
    last->next = start;
    delete p;
	}
}

void link::pop_back(){
	if(start == NULL){
	  cout << "\n***Empty list***\n";
	  return;
	}
	else if(start == last){
		start = NULL;
		last  = NULL;
	}
	else{
		link *p = last;
		last = last->prev;
		last->next = start;
		start->prev = last;
	}
}

void link::reverse(){
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

int main(){
	link  A;
	
	A.push_back(3);
	A.push_back(12);
	A.push_back(15);
	A.push_front(100);
	
	A.display();
	
	A.reverse();
	cout << "\nNo. of datas are: " << A.length();
	A.pop_front();
	A.clear();
	return 0;
}

