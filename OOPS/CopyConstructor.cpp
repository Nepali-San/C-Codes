#include<iostream>
using namespace std;

class Code{
	int id;
	public:
	Code(){
	}
	Code(int a){
		id = a;
	}
	Code(const Code & a){  //Reference to object, copies the data of passed object
		id = a.id;
	}
	void display(void){
		cout << id << endl;
	}
};

int main(){
	Code a(10);
	
	Code b(a);  //invokes copy constructor
	Code c = a;  //invokes copy constructor
	
	Code d;
	d = c;        //doesn't invokes copy constructor but uses overloaded '='
	
	cout << "Id of a = " ; a.display();
	cout << "Id of b = " ; b.display();
	cout << "Id of c = " ; c.display();
	cout << "Id of d = " ; d.display();
	return 0;
}
