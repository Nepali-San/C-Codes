

#include<iostream>
#include<cmath>

double sqrt(int x);

int main(){
	int num;
	std::cout << "Enter a number\n";
	std::cin >> num;
	double result;  
	try{
		result = sqrt(num);
	}
	catch(const char *text){
		std::cout << "Error !!!" << text << std::endl;
		return 1;
	}
	std::cout << "The square root is " << result; 
	return 0;
}

double sqrt(int x){
	if(x < 0)
	throw " Negative number ";
	return pow(x,0.5);
}
