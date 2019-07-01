#include<iostream>
#include<string>

using namespace std;

class employee {
	private:
	int age ;
	string name;
	int salary;
	
	public : 
	
	employee(string n, int a, int s){
	    name = n;
		age = a;
		salary = s;
	}
	
	int getAge(){
		return age;
	}
	
	string getName(){
		return name;
	}
	
	string getDetails(){
		string details = "Name: " + name;
		details += "Age : " + to_string(age);
		details += "Salary : " + to_string(salary);
	}
};

int main(){
	employee emp1("San", 20 , 120000);
	 cout << emp1.getAge() << endl;
	 cout << emp1.getName() << endl;
	 cout << emp1.getDetails() << endl;

	return 0;
}
