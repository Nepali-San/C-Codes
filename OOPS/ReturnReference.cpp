//Let's have a look at call by reference and return by reference
#include<iostream>

int & smaller(int &s , int &w){ //set reference of a & b to s & w
	if(s  > w) return w;  //return reference
	else return s;
}

int main(){
	int a,b;
	std::cout << "a = ";
	std::cin >> a;
	std::cout << "b = ";
	std::cin >> b;
	
	smaller(a,b) = -10;  //assigns the returned reference
	
	std::cout << "a = " << a << " b = " << b << std::endl;
	
	return 0;
}
