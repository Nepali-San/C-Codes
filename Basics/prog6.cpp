#include <iostream>
int main(){
	//for each loop
	
    int arr[] = {1,432,3,4,5};
    
    for(int i : arr)
    std::cout << i << std::endl;
	
	//above for each loop is equivalent to:
    std::cout << '\n' ;
    std::cout << '\n' ;
	
	for(int i = 0; i<=4 ;i++)
	std::cout << arr[i] << std::endl;
	
	return 0;
}
