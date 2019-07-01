#include <iostream>

#define PI 3.1415 //Macro constant

int main(){
	const float pi = 3.1415;  //here pi is read only , you cannot change it's value
	//float const pi = 3.1415  <- Also valid
	// pi = 6 <- causes error
	
    float c(5.3);  //new method for assigning a variable
    std::cout << c;

}
