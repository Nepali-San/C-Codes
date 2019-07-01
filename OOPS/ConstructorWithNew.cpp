
#include<iostream>
#include<cstring>

using namespace std;

class String{
	char * name;
	int length;
	public:
		String(){                   //Constructor-1
			length = 0;
			name = new char(length+1);
		}
		String(char * s){           //Constructor-2
			length = strlen(s);
			name = new char(length+1);
			strcpy(name,s);
		}
		void display(void){
			cout << name << endl;
		}
		void join(String &a , String &b);
};

void String::join(String &a , String &b){
	length = a.length + b.length;  //join is member function so possible to access private data
	delete name;
	name = new char[length + 1];
	strcpy(name,a.name);
	strcat(name,b.name);
};

int main(){
	char a[] = "San ";
	char b[] = "Neupane ";
	char c[] = "Words ";
	String name1(a), name2(b) , name3(c), s1 , s2;
	s1.join(name1,name2);
	s2.join(s1,name3);
	name1.display();
	name2.display();
	name3.display();
	s1.display();
	s2.display();
	return 0; 
}
