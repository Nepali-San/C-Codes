#include<iostream>
#include<set>
using namespace std;

int main(){
	//elements in set are always in sorted order
	set<int,greater<int> > s; 
	//greater is just to arrange in descending order...
	//if greater not uses then it is arrange in ascending order...
	
	s.insert(10); 
	s.insert(50);
	s.insert(12); //values are keys themself so no multiple values are stored
	s.insert(20);
	s.insert(50);
	cout << "\nElements of s\n";
	set<int, greater<int> >::iterator itr;
	for(itr = s.begin(); itr != s.end(); itr++) cout << *itr << " ";
	cout << endl;
	
	cout << "\nElements of s2\n";
	set<int> s2(s.begin(),s.end()); //initalizing the s2 with s1 values;
	set<int>::iterator it;
	for(it = s2.begin(); it != s2.end(); it++) cout << *it  << " ";
	cout << endl;
	
	cout << "\nAfter deleting values from begin to 12 in s" << endl;
	s.erase(s.begin(),s.find(12));
	for(it = s.begin(); it != s.end(); it++) cout << *it << " ";
	cout << endl;
	
	cout << "\nAfter deleting values from begin to 12 in s2" << endl;
	s2.erase(s2.begin(),s2.find(12));
	for(it = s2.begin(); it != s2.end(); it++) cout << *it << " ";
	cout << endl;
	
	int num = s2.erase(20); //20 is erased so num = 1;
	
	cout << "\nErase 20 in s2\n";
	for(it = s2.begin(); it != s2.end(); it++) cout << *it << " ";
	cout << endl;
	
	num = s2.erase(10); //10 absent in s2 so can't erase and num = 0
	
	s.insert(10); 
	s.insert(50);
	s.insert(40);
	s.insert(0);
	s.insert(112);
	cout << "\nElements in s\n";
	for(itr = s.begin(); itr != s.end(); itr++) cout << *itr << " " ;
	cout << endl;
    cout << "\n\nLower bound after 15 in s\n";
	cout << *s.lower_bound(15) << endl;
	
	set<int> s3(s.begin(),s.end());
	set<int>::iterator i;
	cout << "\n\nElements in s3\n";
	for(i = s3.begin(); i != s3.end(); i++) cout << *i << " " ;
	
	cout << "\n\nLower bound after or from possible position of 15 in s3\n";
	cout << *s3.lower_bound(15) << endl;
	cout << "\n\nLower bound after or from possible position of 12 in s3\n";
	cout << *s3.lower_bound(12) <<  endl;
	
	return 0;
}
