#include<iostream>

class name{
	
	// variables
	public :
		int x;
		int y;
		
	private :
		int x1;
		int x2;
		
	//Methods	
	private:
		void info(){
			std::cout << "\n\nINFO: \nAll the private materials \ncan be accessed \nand used only inside the class \nbut can be used and accessed \nthrough public methods for outside of class\n\n";
		}
		
	public :
		void set(int a ,int b){  //to set our private var.
		    this->x1 = a;
		    this->x2 = b;
		}
		int sthadd(){  //Adds private var.
			int add = this->x1 + this->x2;
			this->info();
			return add;
		}
		int *GetPrivateVar(){ //You can't return two var. normally so use pointer and return addr.
			int *a;
			a = (int *)malloc(2*sizeof(int));
			*a = this->x1;
			*(a+1) = this->x2;
			return a;
		}
};

int main(){
	name sth;   
	
	sth.x = 10;   //direct access to a public variable (x,y) allowed
	std::cout << "\nThis is our public variable : " << sth.x << std::endl;
	
	sth.set(20,30);   //Can't access private variable (x1,x2) so use set (public function)
	
    int *h = sth.GetPrivateVar();
    std::cout << "\nPrivate variables are: " << *h << " and " << *(h+1) << std::endl;
    
    int a1 = sth.sthadd(); //adds private variable 
    std::cout << "Sum of variable is : " << a1 << std::endl; //result of above addition
}
