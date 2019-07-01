#include<iostream>
#include<fstream>
using namespace std;

/* 
			   file modes :
			-----------------
	ios::app       Append to end-of-file
	ios::ate	   go to end of file on opening
	ios::binary    binary file
	ios::in        open file for reading only	
	ios::out	   open file for writing only
	ios::trunc     Delete content of file if exists
	etc...
*/

int main(){
	ofstream fout;
	
	//using bitwise or(|) we may combine modes...
	
	fout.open("new file.txt",ios::binary|ios::app);    //open binary file and append date to it's end
	fout << "hello " << endl;              
	fout.close();
}
