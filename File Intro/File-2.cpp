//File handling in cpp
//create a file booklist with book name and it's price...
//then read the file 
#include<iostream>
#include<fstream>

using namespace std;

int main(){
	
	ofstream fout;		
	char filename[30];
	cout << "Enter file name" << endl;
	
	cin >> filename;
	fout.open(filename);   //opening using open() member function
						   //useful when multiple o/p files.
	
	fout << "Book list" << endl;
	cout << "Enter the name of 5 books and their price" << endl;
	
	for(int i = 0; i < 5; i++){
		string book_name; float price;
		cin >> book_name >> price;
		fout << book_name << " - " << price << endl;
	}		
	fout.close();  //close before opening another file..
	
	/*
	//to open another file with same object..
	fout.open("Another_file_name");  
	fout << "Write something in file "  << endl;
	fout.close();  */
	
	//To open the file..
	cout << endl << endl;
	
	ifstream fin;
	fin.open(filename);
	char line[30];
	
	while(fin){    				//check of EOF
		fin.getline(line,30);		
		cout << line << endl;
	}
	
	fin.close();
	
	//for simultaneous r/w create two different object..
	//like -> ifstream fin1,fin2; ofstream fout1,fout2;
	return 0;   									
}
