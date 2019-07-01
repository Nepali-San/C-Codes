#include<iostream>

int main(){
	int n1,n2,n3,n4,n5;
	std::cout << "Enter any five integers seprated by space :" << std::endl;
	std::cin >> n1 >> n2 >> n3 >> n4 >> n5;
	int sum = (n1 + n2 + n3 + n4 + n5);
	
	// sum and 5 is both int so sum/5 also gives int , hence we use 5.0f to get float point
	float avg = sum/5.0f;
	std::cout << "The sum is " << sum << " and the average is " << avg ;
	return 0;
}
