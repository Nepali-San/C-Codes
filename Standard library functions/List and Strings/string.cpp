#include<iostream>
#include<string>

using namespace std;
int main(){
	string str = ("hello hello");
	cout << str << endl;
	
	cout << str.size() << endl; //size of string
	cout << str.at(1) << str[6] << endl;  //characters at given index
	
	bool emp = str.empty(); //true if empty
	cout << emp << " <- string is not empty\n";
	
	str.push_back('e');  //pushing a character in string str
	cout << str << endl;
	str.pop_back();
	cout << str << endl;
	
		
	//for string concatenation
	
	string s1 = "Butter";
	string s2 = "fly";
	cout << s1+s2+'\n' << s1+" and "+s2 << endl;
	
	//to read a entire line of string
	
	cout << "\n\nEnter a line of string:\n";
	string s;
	getline(cin,s);
	cout << "You have entered ( " << s << " )" << endl << endl;
	
	
	cout << "After inserting a new string , we get\n";
	string a = " Good Good";
	s.insert(s.end(),a.begin(),a.end());  //inserting nice in string s
	cout << s << endl;
	
	//to clear the 5 characters from the string starting from index 3
	cout << "After deleting  5 characters starting from index 3 :\n\n";
	s.erase(3,5);
	cout << s << endl << "size " << s.size() << endl;
	cout << endl ;
	cout << (int)'A' << endl;
	cout << (int)'Z';
	return 0;
}
