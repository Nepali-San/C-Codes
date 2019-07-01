/* Multilevel inheritance:
      class A;                  <- parent/base  class
      class B : public A;       <- intermediate base class
      class C : public B;       <- derived class
*/

#include<iostream>
using namespace std;

class Student{
	protected:
		int roll_number;
		string name;
	public:
		void initialize_detail(){
			roll_number = 5;
			name = "Abcd";
		}
		void details(){
			cout << "Roll number of " << name << " is " << roll_number << endl;
		}
};

class Teacher : public Student{
	protected:
		string f_name,m_name;
	    string phone_no;
	    string marks;
	public:
		void details(){
			cout << "call " << f_name << "/" << m_name << " at " << phone_no << endl;
		}
		void get_details(){
			cout << "faters name " << endl;
			cin >> f_name;
			cout << "mothers name" << endl;
			cin >> m_name;
			cout << "phone number" << endl;
			cin >> phone_no;
		}
};

class Principal:public Teacher{
	public:
		void details(){
			cout << "Good student" << endl;
		}
};

int main(){
	Principal p;
	Teacher t;
	Student s;
	
	
	//s,p,t are different objects , we must initialize each of them seprately
	
	cout << "For principal " << endl;
	p.get_details();      //p uses the method of class teacher as it doesn't have it's own
	p.details();          //p uses it's own method(details) since it has it's own 
	
	cout << "\nFor teacher " << endl;
	t.initialize_detail();  //inheriting the method of parent class(student)
	t.get_details();        //since t is different object we again call this method and give different value
	t.details();            //t uses it's own method not of student i.e. overriding
	t.Student::details();   //now t uses it's parent(Student)method valid if already initialized through t
	
	cout << "\nFor student" << endl;
	s.initialize_detail();
	s.details();            //it uses it's method
	
	return 0;
}
