//File handling in cpp
#include<iostream>
#include<fstream>

using namespace std;

int main(){
	
	ofstream outfile("file_name.txt");  //opening a file using constructor of ofstream
									    //this method is useful when only one ofstream file is in the system
									    //for multiple file stream we use open()
	cout << "Enter a name" << endl;
	char name[20];
	cin >> name;
	
	outfile << name << endl;
	
	outfile.close();
	
	//input file created below....
	
	ifstream inf("file_name.txt");
	inf >> name;
	cout << "data in the file is "<< name << endl;
	inf.close();
	return 0;   									
}
