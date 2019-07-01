#include<bits/stdc++.h>

using namespace std;

class String{
	char *p;
	int len;
	public:
		String (){len = 0; p = 0;}
		String (const char *p);
		String (const String &s);
		~String () {delete p;}
		friend String operator+(const String &s,const String &t);
	//	friend int operator <= (const String &s,const String &t);
		friend void show(const String &s);
		void operator = (const char *s);
};

String::String(const char *s){
	cout << "not from = " << endl;
	len = strlen(s);
	p = new char[len + 1];
	strcpy(p,s);
}

String::String(const String &s){
	len  = s.len;
	p = new char[len + 1];
	strcpy(p,s.p);
}

void String::operator = (const char *s){
	cout << "from = " << endl;
	len = strlen(s);
	p = new char[len+1];
	strcpy(p,s);
}

String operator+(const String &s,const String &t){
	String temp;
	temp.len = s.len + t.len;
	temp.p = new char(temp.len + 1);
	strcpy(temp.p,s.p);
	strcat(temp.p,t.p);
	return temp;
}

void show (const String &s){
	cout << s.p;
}

int main(){
	String s1("New ");
	String s2 = "Nepal"; //s1 and s2 are invoked by same constructor
	String s3 = s1 + s2;
	
	String s4;
	s4 = "hello";
	
	const char *a;   //if no const then it violets the nature of string 
	a = "this is ";  //nature : strings character at index i contents cannot be modifed
	
	cout << endl;show(s4);
	cout << endl;show(s1); 	
	cout << endl;show(s2); 
	cout << endl;show(s3); 
	return 0;
}
