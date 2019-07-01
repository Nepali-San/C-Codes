#include<iostream>
using namespace std;

class B{
	int a;             //private members are not inheritable
	public:
		int b;         //All public,protected members are inheritable
		void set_ab(void);
		int get_a(void);
		void show_a(void);
};

//class D : private B   //changes visibility of derived members to private
//class D : protected B //changes visibility of derived members to protected
class D : public B{     //Doesn't change visibility of derived members
	int c;
	public:
		void mul(void);
		void display(void);
};

void B::set_ab(){
	a = 5; b = 10;
}

int B::get_a(){
	return a;
}

void B::show_a(){
	cout << " a = " << a << endl;
}

void D::mul(){
	c = b * get_a();
}

void D::display(){
	cout << " a = " << get_a() << endl;
	cout << " b = " << b << endl;
	cout << " c = " << c << endl;
}

int main(){
	D d;
	
	d.set_ab(); //sets a to 5 and b = 10
	d.mul();
	d.show_a();  //although a is not inherited a can be accessed by inherited member show_a()
	d.display();
	
	d.b = 20;
//	d.a = 12;  //Invalid statement , a is private so not inherited
	d.mul();
	d.display();
	
	return 0;
}
