#include<iostream>
#include<iomanip>

int main(){
	
	
	bool a = true; 
	char c = 'w';  //signed(+ve and -ve ASCII) and unsigned(+ve) form
	int n ; //signed and unsigned form and also long,short form
	long long  jlk ; //really big numbers
	float f = 0.5769;
	double d;
	n = 10;
	n = 132; //redeclaration
	std::cout << " Number is " << n << std::endl;
	
	
	int year = 2017,month = 1,date = 9;
	std::cout << year << '/' << month << '/' << date << std::endl;
	std::cout << year << '/' << std::setw(2) << month << '/' << std::setw(2) << date << std::endl;
	std::cout << year << '/' << std::setw(2) << std::setfill('0') << month << '/' << std::setw(2) << std::setfill('0')  << date;
	//setfill to fill empty space with any character.          	
}
