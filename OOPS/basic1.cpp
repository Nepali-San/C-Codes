#include<iostream>

using namespace std;

class employee {
	private:
	int age ;
	string name;
	int salary;
	
	employee(string n, int a, int s){
		name = n;
		age = a;
		salary = s;
	}
};

int main(){
	employee emp1("San", 20 , 120000);
	 
	 //if no constructor 
//	emp1.age = 20;
//	emp1.name = "San";
//	emp1.salary = 120000;


       //if public can use this
//	cout << "Name : " << emp1.name << endl;
//	cout << "Age : " << emp1.age << endl;
//	cout << "Salary : " <<emp1.salary;
	return 0;
}
