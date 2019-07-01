#include<iostream> //for io
#include<iomanip> //for setw

using namespace std;

int main(){
	
	cout << 2017 << " is today's year." << endl; //either do code like this if you write using namespace.. as above
	std::cout << 11 << " is today's month." << std::endl; //or do code like this if no namespace std
	std::cout << 9 << " is today's date." << std::endl; //using no namespace is good in rare situations.
	std::cout << std::setw (5) << 9 << " is today's date." << std::endl;
	std::cout << std::setw (10) << 2017 << " is today's year." << std::endl << set::setw();
	return 0;
}

//endl is to terminate the line..
