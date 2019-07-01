//Overloading operators

#include<iostream>
using namespace std;

class vector{
	private:
		int *arr;
		int n;
	public:
		vector(int);
		void insert(int, int);
		void display();
		vector operator + (vector &);
		void operator - ();
		
	    friend vector operator * (vector & , vector &); //using friend function for binary operator
	    friend void operator ~ (vector &);              //using friend function for unary operator
};

vector::vector(int size){
	n = size;    
	arr = new int[n];
}

void vector::insert(int index, int data){
	arr[index] = data;
}

void vector::display(){
	//n is of the calling object property
	for(int i = 0; i < n ;i++){
		cout << arr[i] << " " ;
	}
}

vector vector::operator + (vector &c){
	vector d(n);
	for(int i = 0; i < n; i++){
		d.arr[i] = arr[i] + c.arr[i];
	}
	return d;
}

void vector::operator - (){
	for(int i = 0; i < n; i++)
	arr[i] = - arr[i];
}

vector operator *(vector &a, vector &b){  //friend function definition
	int n = a.n;  //since here object is not the one who called so we provide n explictly from any one object
	vector c(n);
	for(int i = 0; i < n; i++){
		c.arr[i] = a.arr[i] * b.arr[i];
	}
	return c;
}

void operator ~ (vector &a){	   //friend function defition
	for(int i = 0; i < a.n; i++){
		a.arr[i] = - a.arr[i];
	}
}

int main(){
	int n , index, data;
	cout << "Enter the size of the vectors : ";
	cin >> n;
	
	vector a(n);
	cout << "Enter the data for the vector 1" << endl;
	for(int i = 0; i < n; i++){
		cin >> data;
		a.insert(i,data);
	}	
	
	vector b(n);
	cout << "Enter the data for the vector 2" << endl;
	for(int i = 0; i < n; i++){
		cin >> data;
		b.insert(i,data);
	}
	
	vector c(n);
	
	c = a + b;     								 //overloading binary operator "+" that has return type
	cout << "\nAfter adding both vectors" << endl;
	c.display();
	
	-c;										    //overloading unary minus
	cout << "\nNegating the sum result " << endl;
	c.display();
	
	//block for friend function 
	{
		vector d(n);
		cout << "\nAfter multiplying both vectors" << endl;
		d = a * b;
		d.display();
		~d;                             //overloading unary minus using friend
		cout <<"\nNegating multiplied result" << endl;
		d.display();
    }
	
	return 0;
}
